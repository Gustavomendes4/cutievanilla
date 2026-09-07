#ifndef CUTIEVANILLA_IO_H_INCLUDED
#define CUTIEVANILLA_IO_H_INCLUDED



typedef enum _CVFileFormat{
    CV_IMAGE_FORMAT_BMP,
    CV_IMAGE_FORMAT_PNG,
    CV_IMAGE_FORMAT_JPG,
    CV_IMAGE_FORMAT_JPEG,
    CV_IMAGE_FORMAT_TIFF,

    CV_INVALID_IMAGE_FORMAT
}CVFileFormat;

/* == Adiciona cabeçalhos para funções de I/O de imagens == */

#include "bmp/bmp_io.h"

#include "png/png_io.h"

#include "jpg/jpg_io.h"

#include "jpeg/jpeg_io.h"

#include "tiff/tiff_io.h"

bool cv_image_io_validate_format(const char* filename, CVFileFormat format);

CVFileFormat cv_image_io_detect_format(const char* filename);

CVImage* cv_image_io_load(const char* filename);

int cv_image_io_save(CVImage* image, const char* filename);

#endif // CUTIEVANILLA_IO_H_INCLUDED