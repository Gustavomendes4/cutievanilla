#ifndef CUTIEVANILLA_H_INCLUDED
#define CUTIEVANILLA_H_INCLUDED

#include "io/image_io.h"

#include "matrix/matrix.h"

#include "metadata/metadata.h"

/*
    Dar suporte para abertura de imagens em formatos:
    - binario   ( 1  bits/pixel)
    - gray      ( 8  bits/pixel)
    * rgba      ( 32 bits/pixel)
    - rgb       ( 24 bits/pixel)
    - CMYK      ( 32 bits/pixel) (ciano, magenta, amarelo e preto)
    - HSV      ( 24 bits/pixel) (matiz, saturação e valor)
*/

typedef enum {
    CV_COLOR_UNKNOWN,
    CV_COLOR_GRAY,
    CV_COLOR_RGB,
    CV_COLOR_RGBA,
    CV_COLOR_BGR,
    CV_COLOR_BGRA,
    CV_COLOR_BIN,
    CV_COLOR_HSV


}CVImageColorSpace;


typedef struct _CVImage{
    
    CVMatrix* matrix;
    
    CVImageColorSpace color_format;

    CVFileFormat file_format;

    CVMetaData meta_data; // not implemented yet

}CVImage;

CVImage* cv_image_load(const char* filename);

int cv_image_save(CVImage* image, const char* filename);

void cv_image_free( CVImage* image);



#endif // CUTIEVANILLA_H_INCLUDED