
#include <stdio.h>
#include <stdlib.h>

#include "bmp_io.h"

#include "cutievanilla.h"


/* local validations */

static bool isValidFileHeader(const BitmapFileHeader* head){
    if (head == NULL)
        return false;

    /*
     * BMP signature:
     *
     * 'B' = 0x42
     * 'M' = 0x4D
     *
     * Little-endian:
     * 0x4D42
     */
    if (head->bfType != 0x4D42)
        return false;

    /*
     * Pixel data must start after the headers.
     */
    if (head->bfOffBits < sizeof(BitmapFileHeader))
        return false;

    /*
     * A valid BMP cannot have an empty file.
     */
    if (head->bfSize == 0)
        return false;

    return true;
}

static bool isValidInfoHeader(const BitmapInfoHeader* head){
    if (head == NULL)
        return false;

    /*
     * We currently support BITMAPINFOHEADER.
     */
    if (head->biSize != 40)
        return false;

    /*
     * Width must be positive.
     */
    if (head->biWidth <= 0)
        return false;

    /*
     * Our current decoder expects bottom-up BMPs.
     * Negative height means top-down BMP.
     */
    if (head->biHeight <= 0)
        return false;

    /*
     * BMP specification requires one plane.
     */
    if (head->biPlanes != 1)
        return false;

    /*
     * Current decoder reads:
     *
     * B G R
     *
     * Therefore only 24-bit BMP is supported.
     */
    if (head->biBitCount != 24)
        return false;

    /*
     * BI_RGB = no compression.
     */
    if (head->biCompression != 0)
        return false;

    return true;
}

/* public functions */
CVImage* cv_bmp_load(const char* filename){
    
    FILE* file = fopen(filename, "rb");
    
    if( file == NULL)
        return NULL;
    
    
    /* READ HEADERS*/
    BitmapFileHeader fileHeader;
    
    BitmapInfoHeader infoHeader;

    if (fread(&fileHeader, sizeof(fileHeader), 1, file) != 1) {
        fclose(file);
        return NULL;
    }

    if (fread(&infoHeader, sizeof(infoHeader), 1, file) != 1) {
        fclose(file);
        return NULL;
    }

    /* validate header*/
    if( !isValidFileHeader(&fileHeader) ){
        fclose(file);
        return NULL;
    }

    if( !isValidInfoHeader(&infoHeader) ){
        fclose(file);
        return NULL;
    }


    /* image dimensions */
    const size_t width = infoHeader.biWidth;
    const size_t height = infoHeader.biHeight;
    

    /* alloc matrix */
    CVMatrix* matrix = cv_matrix_create(
        3,
        (size_t[]){width, height, 4},
        CV_MATRIX_UINT8
    );

    if(matrix == NULL){
        fclose(file);
        return NULL;
    }


    /* move cursor to pixel data */
    if (fseek(file, fileHeader.bfOffBits, SEEK_SET) != 0) {
        cv_matrix_free(matrix);
        fclose(file);
        return NULL;
    }

    
    /* BMP row size */
    size_t row_size = width * 3;

    size_t row_padded = (row_size + 3) & ~((size_t)3);

    uint8_t* row = malloc(row_padded);
    
    if( row == NULL ){
        cv_matrix_free(matrix);
        fclose(file);
        return NULL;
    }
    

    /* read pixels */
    for( size_t i = 0; i < height; i++){

        if( fread(row, 1, row_padded, file) != row_padded){
            free(row);
            cv_matrix_free(matrix);
            fclose(file);
            return NULL;
        }

        size_t y = height - 1 - i;

        for( size_t x = 0; x < width; x++){

            uint8_t b = row[x * 3 + 0];
            uint8_t g = row[x * 3 + 1];
            uint8_t r = row[x * 3 + 2];
            uint8_t a = 255;

            cv_matrix_set(matrix, (size_t[]){x, y, 0}, &r);
            cv_matrix_set(matrix, (size_t[]){x, y, 1}, &g);
            cv_matrix_set(matrix, (size_t[]){x, y, 2}, &b);
            cv_matrix_set(matrix, (size_t[]){x, y, 3}, &a);

        }

    }
    
    free(row);
    fclose(file);
    
    /* temporario */

    CVImage* img = malloc( sizeof(CVImage) );

    if( img == NULL ){
        cv_matrix_free(matrix);
        return NULL;
    }

    img->matrix = matrix;

    img->color_format = CV_COLOR_RGBA;
    img->file_format = CV_IMAGE_FORMAT_BMP;

    return img;
}

int cv_bmp_save(CVImage* image, const char* filename){
    

    if( image == NULL || image->matrix == NULL){
        return 1;
    }


    FILE* file = fopen(filename, "wb");

    if( file == NULL)
        return 2;


    /* */
    const size_t width  = image->matrix->shape[0];
    const size_t height = image->matrix->shape[1];

    
    /* BMP rows must be aligned to 4 bytes. */
    const size_t row_size = width * 3;

    const size_t row_padded = (row_size + 3) & ~((size_t)3);

    /* Calculate header infos */
    const size_t image_size = row_padded * height;

    const size_t pixel_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    const size_t file_size = pixel_offset + image_size;


    /*  File Header   */
    BitmapFileHeader fileHeader = {
        .bfType         = 0x4D42,
        .bfSize         = file_size,
        .bfReserved1    = 0,
        .bfReserved2    = 0,
        .bfOffBits      = pixel_offset 
    };

    /*  Info Header */
    BitmapInfoHeader infoHeader = {
        .biSize     = 40,
        .biWidth    = width,
        .biHeight   = height,
        .biPlanes   = 1,
        .biBitCount = 24,
        .biCompression  = 0,
        .biSizeImage     = image_size,
        .biXPelsPerMeter = 0,
        .biYPelsPerMeter = 0,
        .biClrUsed       = 0,
        .biClrImportant  = 0
    };


    /* Write headers in file*/
    if( fwrite(&fileHeader, sizeof(BitmapFileHeader), 1, file) != 1){
        fclose(file);
        return 4;
    }

    if( fwrite(&infoHeader, sizeof(BitmapInfoHeader), 1, file) != 1){
        fclose(file);
        return 4;
    }

    
    /* allocate 1 BMP row*/
    uint8_t* row = calloc(1, row_padded);

    if( row == NULL){
        fclose(NULL);
        return 5;
    }


    /*
    * BMP is bottom-up.
    *
    * Matrix:
    *
    * y = 0       -> top
    * y = height-1 -> bottom
    *
    * BMP:
    *
    * first row -> bottom
    */
    for (size_t i = 0; i < height; i++) {

        size_t y = height - 1 - i;

        /*  Fill row with BGR pixels */
        for (size_t x = 0; x < width; x++) {

            const uint8_t* r = cv_matrix_get(image->matrix, (size_t[]){x, y, 0});

            const uint8_t* g = cv_matrix_get(image->matrix, (size_t[]){x, y, 1});

            const uint8_t* b = cv_matrix_get(image->matrix, (size_t[]){x, y, 2});

            row[x * 3 + 0] = *b;
            row[x * 3 + 1] = *g;
            row[x * 3 + 2] = *r;
        }

        /*
         * Padding bytes are already zero
         * because the row was allocated with calloc.
         */

        if (fwrite(row, 1, row_padded, file) != row_padded) {
            free(row);
            fclose(file);
            return 6;
        }
    }

    free(row);
    fclose(file);

    return 0;
}

bool cv_is_valid_bmp_file(const char* filename){

    FILE* file = fopen(filename, "rb");

    if( file == NULL)
        return false;

    /* READ HEADERS*/
    BitmapFileHeader fileHeader;
    
    BitmapInfoHeader infoHeader;

    if (fread(&fileHeader, sizeof(fileHeader), 1, file) != 1) {
        fclose(file);
        return false;
    }

    if (fread(&infoHeader, sizeof(infoHeader), 1, file) != 1) {
        fclose(file);
        return false;
    }

    fclose(file);
     
    return isValidFileHeader(&fileHeader) && isValidInfoHeader(&infoHeader);

}
