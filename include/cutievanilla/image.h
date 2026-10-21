#ifndef CUTIEVANILLA_IMAGE_H_INCLUDED
#define CUTIEVANILLA_IMAGE_H_INCLUDED

#include <stdint.h>

#include "type.h"
#include "colorspace.h"
#include "metadata.h"

/* Forward declaration */
typedef struct _CVMatrix CVMatrix;

/* ========================= */
/* Image                     */
/* ========================= */
typedef struct _CVImage{
    
    CVMatrix* matrix;
    
    CVColorSpace color_format;

    CVMetaData meta_data; // not implemented yet

}CVImage;



/* ========================= */
/* Creation / destruction    */
/* ========================= */

CVImage* cv_image_create(size_t width, size_t height, CVColorSpace color_space, CVType data_type);

CVImage* cv_image_load(const char* filename);

CVImage* cv_image_clone(const CVImage* image);

int cv_image_save(const CVImage* image, const char* filename);

void cv_image_free(CVImage* image);

CVImage* cv_image_convert(const CVImage* image, CVColorSpace color_space);

/* ========================= */
/* Information               */
/* ========================= */
size_t cv_image_width(const CVImage *image);

size_t cv_image_height(const CVImage *image);

size_t cv_image_channels(const CVImage *image);

CVColorSpace cv_image_get_colorspace(const CVImage *image);

CVType cv_image_get_type(const CVImage *image);

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