#ifndef CUTIEVANILLA_COLORSPACE_H_INCLUDED
#define CUTIEVANILLA_COLORSPACE_H_INCLUDED

#include <stdbool.h>

#include "core/type.h"

typedef enum _CVColorSpace{
    CV_COLOR_UNKNOWN = 0,
    CV_COLOR_GRAY    = 1,
    CV_COLOR_RGB     = 2,
    CV_COLOR_RGBA    = 3,
    CV_COLOR_BIN     = 4,
    CV_COLOR_HSV     = 5,
    
    CV_COLOR_HSL     = 6,
    CV_COLOR_BGR     = 7,
    CV_COLOR_BGRA    = 8,
    CV_COLOR_CMYK    = 9,
    

    /*
        Dar suporte para abertura de imagens em formatos:
        - binario   ( 1  bits/pixel)
        - gray      ( 8  bits/pixel)
        * rgba      ( 32 bits/pixel)
        - rgb       ( 24 bits/pixel)
        - CMYK      ( 32 bits/pixel) (ciano, magenta, amarelo e preto)
        - HSV      ( 24 bits/pixel) (matiz, saturação e valor)
    */
    CV_COLOR_COUNT
    
}CVColorSpace;

bool cv_colorspace_isvalid(CVColorSpace color_space);

int cv_colorspace_channels(CVColorSpace color_space);

const char* cv_colorspace_name(CVColorSpace color_space);

bool cv_colorspace_convert_pixel(
    const void* src_pixel,
    CVColorSpace src_space,
    void* dest_pixel,
    CVColorSpace dest_space,
    CVType type
);






#endif //CUTIEVANILLA_COLORSPACE_H_INCLUDED