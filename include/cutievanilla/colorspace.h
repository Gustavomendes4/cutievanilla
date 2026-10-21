#ifndef CUTIEVANILLA_COLORSPACE_H_INCLUDED
#define CUTIEVANILLA_COLORSPACE_H_INCLUDED

#include <stdbool.h>

typedef enum _CVColorSpace{
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
}CVColorSpace;

bool cv_colorspace_isvalid(CVColorSpace color_space);

size_t cv_colorspace_channels(CVColorSpace color_space);

void cv_colorspace_convert_pixel(
    const void* pixel,
    CVColorSpace src_cs,
    void* buffer,
    CVColorSpace color_space,
    CVType type
);







#endif //CUTIEVANILLA_COLORSPACE_H_INCLUDED