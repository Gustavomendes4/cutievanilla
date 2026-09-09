#include <stdio.h>


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "filecore.h"

#include "io/image_io.h"


#include "cutievanilla/matrix.h"
#include "cutievanilla/image.h"


/*                      */
/*  Private functions   */
/*                      */
static bool is_valid_image_data_type(CVImageDataType type){
    return type >= 0 && type < CV_IMAGE_DATA_UNKNOWED;
}

static CVMatrixType image_to_matrix_type(CVImageDataType type){

    switch(type){

        case CV_IMAGE_DATA_UINT8:   return CV_MATRIX_UINT8;
        case CV_IMAGE_DATA_INT8:    return CV_MATRIX_INT8;
        case CV_IMAGE_DATA_UINT16:  return CV_MATRIX_UINT16;
        case CV_IMAGE_DATA_INT16:   return CV_MATRIX_INT16;
        case CV_IMAGE_DATA_UINT32:  return CV_MATRIX_UINT32;
        case CV_IMAGE_DATA_INT32:   return CV_MATRIX_INT32;
        case CV_IMAGE_DATA_FLOAT32: return CV_MATRIX_FLOAT32;
        case CV_IMAGE_DATA_FLOAT64: return CV_MATRIX_FLOAT64;

        default:                    
        case CV_IMAGE_DATA_UNKNOWED: return CV_MATRIX_OTHER_TYPE;
    }
}

static size_t num_of_channels(CVImageColorSpace color_space){

    switch(color_space){

        case CV_COLOR_GRAY: return 1;
        case CV_COLOR_RGB:  return 3;
        case CV_COLOR_RGBA: return 4;
        case CV_COLOR_BIN:  return 1;
        case CV_COLOR_HSV:  return 3;
        // case CV_COLOR_UNKNOWN:
    }
    
    return 0;
}

/*                      */
/*   Public functions   */
/*                      */
CVImage* cv_image_create(size_t width, size_t height, CVImageColorSpace color_space, CVImageDataType data_type){

    size_t channels = num_of_channels(color_space);

    if(
        width == 0      ||
        height == 0     ||
        channels == 0   ||
        !is_valid_image_data_type(data_type)
        
    ){
        return NULL;
    }

    CVMatrixType type = image_to_matrix_type(data_type);

    CVMatrix* matrix = cv_matrix_create(3, (size_t[]){width, height, channels},  type);

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
    img->meta_data = (CVMetaData){0};
    img->matrix = matrix;

    return img;
}

CVImage* cv_image_load( const char* filename){

    /* Previous conditions */
    if( !fc_isValidPath(filename) ) return NULL;

    if( !fc_existsFile(filename) ) return NULL;

    return cv_image_io_load(filename);
}

int cv_image_save(CVImage* image, const char* filename){

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

CVImageColorSpace cv_image_get_colorformat(const CVImage *image){

    if( image == NULL)
        return 0;

    return image->color_format;
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
