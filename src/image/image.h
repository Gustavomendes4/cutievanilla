#ifndef CUTIEVANILLA_IMAGE_H_INCLUDED
#define CUTIEVANILLA_IMAGE_H_INCLUDED

#include <stdint.h>

#include "metadata/metadata.h"

/* Forward declaration */
typedef struct _CVMatrix CVMatrix;


/* ========================= */
/* Image format              */
/* ========================= */

typedef enum {
    CV_COLOR_UNKNOWN,
    CV_COLOR_GRAY,
    CV_COLOR_RGB,
    CV_COLOR_RGBA,
    CV_COLOR_BIN,
    CV_COLOR_HSV
    

    /*
        Dar suporte para abertura de imagens em formatos:
        - binario   ( 1  bits/pixel)
        - gray      ( 8  bits/pixel)
        * rgba      ( 32 bits/pixel)
        - rgb       ( 24 bits/pixel)
        - CMYK      ( 32 bits/pixel) (ciano, magenta, amarelo e preto)
        - HSV      ( 24 bits/pixel) (matiz, saturação e valor)
    */
}CVImageColorSpace;

typedef enum {
    CV_IMAGE_DATA_UINT8 = 0,
    CV_IMAGE_DATA_INT8,
    CV_IMAGE_DATA_UINT16,
    CV_IMAGE_DATA_INT16,
    CV_IMAGE_DATA_UINT32,
    CV_IMAGE_DATA_INT32,
    CV_IMAGE_DATA_FLOAT32,
    CV_IMAGE_DATA_FLOAT64,

    CV_IMAGE_DATA_UNKNOWED
} CVImageDataType;


/* ========================= */
/* Image                     */
/* ========================= */

typedef struct _CVImage{
    
    CVMatrix* matrix;
    
    CVImageColorSpace color_format;

    CVMetaData meta_data; // not implemented yet

}CVImage;



/* ========================= */
/* Creation / destruction    */
/* ========================= */

CVImage* cv_image_create(size_t width, size_t height, CVImageColorSpace channels, CVImageDataType data_type);

CVImage* cv_image_load(const char* filename);

int cv_image_save(CVImage* image, const char* filename);

void cv_image_free( CVImage* image);


/* ========================= */
/* Information               */
/* ========================= */
size_t cv_image_width(const CVImage *image);

size_t cv_image_height(const CVImage *image);

size_t cv_image_channels(const CVImage *image);

CVImageColorSpace cv_image_get_colorformat(const CVImage *image);


/* ========================= */
/* Pixel access              */
/* ========================= */

void cv_image_set_pixel(CVImage *image, size_t x, size_t y, const void* values);

const void* cv_image_get_pixel(const CVImage *image, size_t x, size_t y);


/* ========================= */
/* Channel access            */
/* ========================= */

void cv_image_set_channel(CVImage *image, size_t x, size_t y, size_t channel, const void* value);

const void* cv_image_get_channel(const CVImage *image, size_t x, size_t y, size_t channel);




#endif // CUTIEVANILLA_IMAGE_H_INCLUDED