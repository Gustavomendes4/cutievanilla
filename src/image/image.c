/*

    this file describes the public API for open, create, manipulate and save images.




*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "filecore.h"

#include "io/image_io.h"

#include "core/type.h"
#include "core/matrix.h"
#include "core/image.h"

bool cv_image_isvalid(CVImage* image){

    if( image == NULL)
        return false;

    if( !cv_matrix_isvalid(image->matrix) || !cv_colorspace_isvalid(image->color_format) )
        return false;
    
    return true;
}

CVImage* cv_image_create(size_t width, size_t height, CVColorSpace color_space, CVType data_type){

    /* se clrspc_or_chn < 0, considera-se um ENUM, caso contrário, o númetro de canais */
    size_t channels = cv_colorspace_channels((CVColorSpace )color_space);
    
    if(
        width == 0      ||
        height == 0     ||
        channels == 0        
    ){
        return NULL;
    }

    CVMatrix* matrix = cv_matrix_create(3, (size_t[]){width, height, channels},  data_type);

    if( matrix == NULL ){
        return NULL;
    }

    
    CVImage* img = malloc(sizeof(CVImage));

    if( img == NULL ){
        cv_matrix_free(matrix);
        return NULL;
    }


    /* fill matrix */
    img->color_format = color_space;
    img->matrix = matrix;

    return img;
}

CVImage* cv_image_load( const char* filename){

    /* Previous conditions */
    if( !fc_isValidPath(filename) ) return NULL;

    if( !fc_existsFile(filename) ) return NULL;

    return cv_image_io_load(filename);
}

CVImage* cv_image_clone(const CVImage* image){

    if( image == NULL)
        return NULL;

    CVImage* new = (CVImage*)malloc(sizeof(CVImage));
    
    if( new == NULL ){ return NULL; }
    
    new->matrix = cv_matrix_clone(image->matrix);
    
    if( new->matrix == NULL){
        free(new);
        return NULL;
    }

    new->color_format = cv_image_get_colorspace(image);

    return new;
}

int cv_image_save(const CVImage* image, const char* filename){

    /* Previous conditions */
    if( !fc_isValidPath(filename) ) return -1;

    if( !image ) return -2;

    return cv_image_io_save(image, filename);
}

void cv_image_free( CVImage* image){

    if( !image ) return;

    cv_matrix_free(image->matrix);

    free(image);

}

/* X */ CVImage* cv_image_convert( const CVImage* image, CVColorSpace color_space){
    
    if(image == NULL)
        return NULL;

    if( !cv_colorspace_isvalid(color_space) )
        return NULL;

    CVColorSpace src_cs = cv_image_get_colorspace(image);

    if( src_cs == color_space){
        
        printf("\nclonei");
        return cv_image_clone(image) ; 
    }

        
    
    /* create new image */
    CVType type   = cv_image_get_type(image);
    size_t width  = cv_image_width(image);
    size_t height = cv_image_height(image);


    CVImage* new = cv_image_create(
        width,
        height,
        color_space,
        type
    );

    if( new == NULL) { return NULL; }
    
    /* Iterate pixels*/
    uint8_t buffer[1024];

    printf("(A)\n");

    for( size_t x = 0; x < width; x++){

        for( size_t y = 0; y < height; y++){

            const void* pixel = cv_image_get_pixel(image, x, y);

            // cv_colorspace_convert_pixel(pixel, src_cs, buffer, color_space, type);

            cv_image_set_pixel(new, x, y, buffer);
        }
    }

    printf("(B)\n");

    return new;
}

size_t cv_image_width(const CVImage *image){

    if( image == NULL)
        return 0;

    const size_t* shape = cv_matrix_get_shape(image->matrix);
    
    if( shape == NULL)
        return 0;

    return shape[0];
}

size_t cv_image_height(const CVImage *image){

    if( image == NULL)
        return 0;

    const size_t* shape = cv_matrix_get_shape(image->matrix);
    
    if( shape == NULL)
        return 0;

    return shape[1];
}

size_t cv_image_channels(const CVImage *image){

    if( image == NULL)
        return 0;

    const size_t* shape = cv_matrix_get_shape(image->matrix);
    
    if( shape == NULL)
        return 0;

    return shape[2];
}

CVColorSpace cv_image_get_colorspace(const CVImage *image){

    if( image == NULL)
        return 0;

    return image->color_format;
}

CVType cv_image_get_type(const CVImage *image){

    if( image == NULL)
        return CV_TYPE_UNKNOWED;

    return cv_matrix_get_type(image->matrix);
}

void cv_image_set_pixel(CVImage *image, size_t x, size_t y, const void* values){

    /* values é tratado sempre com o mesmo tipo da imagem */

    if( image == NULL || values == NULL){
        return;
    }

    size_t size = cv_matrix_element_size(image->matrix);
    
    size_t channels = cv_image_channels(image);

    for( size_t i = 0; i < channels; i++){

        const void *addr = ((const uint8_t*)values) + (i * size);

        cv_matrix_set(image->matrix, (size_t[]){x, y, i}, addr);
    }

}

const void* cv_image_get_pixel(const CVImage *image, size_t x, size_t y){

    if( image == NULL)
        return NULL;

    return cv_matrix_get(image->matrix, (size_t[]){x, y});
}

void cv_image_set_channel(CVImage *image, size_t x, size_t y, size_t channel, const void* value){

    if( image == NULL || value == NULL)
        return;

    cv_matrix_set(image->matrix, (size_t[]){x, y, channel}, value);
}

const void* cv_image_get_channel(const CVImage *image, size_t x, size_t y, size_t channel){

    if( image == NULL )
        return NULL;

    return cv_matrix_get(image->matrix, (size_t[]){x, y, channel} );
}
