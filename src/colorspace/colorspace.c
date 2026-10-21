
#include "cutievanilla.h"


bool cv_colorspace_isvalid(CVColorSpace color_space){
    return true;
}

size_t cv_colorspace_channels(CVColorSpace color_space){

    switch(color_space){

        case CV_COLOR_GRAY: return 1;
        case CV_COLOR_RGB:  return 3;
        case CV_COLOR_RGBA: return 4;
        case CV_COLOR_BIN:  return 1;
        case CV_COLOR_HSV:  return 3;
        case CV_COLOR_UNKNOWN:
    }
    
    return 0;
}

void cv_colorspace_convert_pixel(
    const void* src,
    CVColorSpace src_cs,
    void* dest,
    CVColorSpace dest_cs,
    CVType type
){

    if(
        src == NULL ||
        dest == NULL ||
        !cv_colorspace_isvalid(src_cs) ||
        !cv_colorspace_isvalid(dest_cs) ||
        !cv_type_is_valid(type)
    ) return;

    




}






