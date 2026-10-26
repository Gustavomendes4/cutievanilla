
#include <stdio.h>
#include <stdint.h>

#include "cutievanilla.h"

#include "colorspace_internal.h"

typedef struct _ColorSpaceMap{

    // CVColorSpace colorspace;

    const char* name;
    
    uint8_t channels;

}ColorSpaceMap;

static const ColorSpaceMap mapping[ CV_COLOR_COUNT ] = {

    [CV_COLOR_UNKNOWN]  = {"CV_COLOR_UNKNOWN", 0},
    [CV_COLOR_GRAY]     = {"CV_COLOR_GRAY", 1},
    [CV_COLOR_RGB]      = {"CV_COLOR_RGB", 3},
    [CV_COLOR_RGBA]     = {"CV_COLOR_RGBA", 4},
    [CV_COLOR_BIN]      = {"CV_COLOR_BIN", 1},
    [CV_COLOR_HSV]      = {"CV_COLOR_HSV", 3},
    
    [CV_COLOR_HSL]  = {"CV_COLOR_HSL", 3},
    [CV_COLOR_BGR]  = {"CV_COLOR_BGR", 3},
    [CV_COLOR_BGRA] = {"CV_COLOR_BGRA", 4},
    [CV_COLOR_CMYK] = {"CV_COLOR_CMYK", 4},

};


static const CVColorConvertFn converters[CV_COLOR_COUNT][CV_COLOR_COUNT] = {

    [CV_COLOR_UNKNOWN] = {
        [CV_COLOR_GRAY] = NULL,
        [CV_COLOR_RGB]  = NULL,
        [CV_COLOR_RGBA] = NULL,
        [CV_COLOR_BIN]  = NULL,
        [CV_COLOR_HSV]  = NULL,
        [CV_COLOR_HSL]  = NULL,
        [CV_COLOR_BGR]  = NULL,
        [CV_COLOR_BGRA] = NULL,
        [CV_COLOR_CMYK] = NULL
    },

    [CV_COLOR_GRAY] = {
        [CV_COLOR_GRAY] = NULL,
        [CV_COLOR_RGB]  = gray_to_rgb,
        [CV_COLOR_RGBA] = gray_to_rgba,
        [CV_COLOR_BIN]  = gray_to_bin,
        [CV_COLOR_HSV]  = gray_to_hsv,
        [CV_COLOR_HSL]  = gray_to_hsl,
        [CV_COLOR_BGR]  = gray_to_bgr,
        [CV_COLOR_BGRA] = gray_to_bgra,
        [CV_COLOR_CMYK] = gray_to_cmyk
    },
    
    [CV_COLOR_RGB] = {
        [CV_COLOR_GRAY] = rgb_to_gray,
        [CV_COLOR_RGB]  = NULL,
        [CV_COLOR_RGBA] = rgb_to_rgba,
        [CV_COLOR_BIN]  = rgb_to_bin,
        [CV_COLOR_HSV]  = rgb_to_hsv,
        [CV_COLOR_HSL]  = rgb_to_hsl,
        [CV_COLOR_BGR]  = rgb_to_bgr,
        [CV_COLOR_BGRA] = rgb_to_bgra,
        [CV_COLOR_CMYK] = rgb_to_cmyk
    },
    
    [CV_COLOR_RGBA] = {
        [CV_COLOR_GRAY] = rgba_to_gray,
        [CV_COLOR_RGB]  = rgba_to_rgb,
        [CV_COLOR_RGBA] = NULL,
        [CV_COLOR_BIN]  = rgba_to_bin,
        [CV_COLOR_HSV]  = rgba_to_hsv,
        [CV_COLOR_HSL]  = rgba_to_hsl,
        [CV_COLOR_BGR]  = rgba_to_bgr,
        [CV_COLOR_BGRA] = rgba_to_bgra,
        [CV_COLOR_CMYK] = rgba_to_cmyk
    },
    
    [CV_COLOR_BIN] = {
        [CV_COLOR_GRAY] = bin_to_gray,
        [CV_COLOR_RGB]  = bin_to_rgb,
        [CV_COLOR_RGBA] = bin_to_rgba,
        [CV_COLOR_BIN]  = NULL,
        [CV_COLOR_HSV]  = bin_to_hsv,
        [CV_COLOR_HSL]  = bin_to_hsl,
        [CV_COLOR_BGR]  = bin_to_bgr,
        [CV_COLOR_BGRA] = bin_to_bgra,
        [CV_COLOR_CMYK] = bin_to_cmyk
    },
    
    [CV_COLOR_HSV] = {
        [CV_COLOR_GRAY] = hsv_to_gray,
        [CV_COLOR_RGB]  = hsv_to_rgb,
        [CV_COLOR_RGBA] = hsv_to_rgba,
        [CV_COLOR_BIN]  = hsv_to_bin,
        [CV_COLOR_HSV]  = NULL,
        [CV_COLOR_BGR]  = hsv_to_bgr,
        [CV_COLOR_HSL]  = hsv_to_hsl,
        [CV_COLOR_BGRA] = hsv_to_bgra,
        [CV_COLOR_CMYK] = hsv_to_cmyk
    },
    
    [CV_COLOR_HSL] = {
        [CV_COLOR_GRAY] = hsl_to_gray,
        [CV_COLOR_RGB]  = hsl_to_rgb,
        [CV_COLOR_RGBA] = hsl_to_rgba,
        [CV_COLOR_BIN]  = hsl_to_bin,
        [CV_COLOR_HSV]  = hsl_to_hsv,
        [CV_COLOR_HSL]  = NULL,
        [CV_COLOR_BGR]  = hsl_to_bgr,
        [CV_COLOR_BGRA] = hsl_to_bgra,
        [CV_COLOR_CMYK] = hsl_to_cmyk
    },

    [CV_COLOR_BGR] = {
        [CV_COLOR_GRAY] = bgr_to_gray,
        [CV_COLOR_RGB]  = bgr_to_rgb,
        [CV_COLOR_RGBA] = bgr_to_rgba,
        [CV_COLOR_BIN]  = bgr_to_bin,
        [CV_COLOR_HSV]  = bgr_to_hsv,
        [CV_COLOR_HSL]  = bgr_to_hsl,
        [CV_COLOR_BGR]  = NULL,
        [CV_COLOR_BGRA] = bgr_to_bgra,
        [CV_COLOR_CMYK] = bgr_to_cmyk
    },
    
    [CV_COLOR_BGRA] = {
        [CV_COLOR_GRAY] = bgra_to_gray,
        [CV_COLOR_RGB]  = bgra_to_rgb,
        [CV_COLOR_RGBA] = bgra_to_rgba,
        [CV_COLOR_BIN]  = bgra_to_bin,
        [CV_COLOR_HSV]  = bgra_to_hsv,
        [CV_COLOR_HSL]  = bgra_to_hsl,
        [CV_COLOR_BGR]  = bgra_to_bgr,
        [CV_COLOR_BGRA] = NULL,
        [CV_COLOR_CMYK] = bgra_to_cmyk
    },
    
    [CV_COLOR_CMYK] = {
        [CV_COLOR_GRAY] = cmyk_to_gray,
        [CV_COLOR_RGB]  = cmyk_to_rgb,
        [CV_COLOR_RGBA] = cmyk_to_rgba,
        [CV_COLOR_BIN]  = cmyk_to_bin,
        [CV_COLOR_HSV]  = cmyk_to_hsv,
        [CV_COLOR_HSL]  = cmyk_to_hsl,
        [CV_COLOR_BGR]  = cmyk_to_bgr,
        [CV_COLOR_BGRA] = cmyk_to_bgra,
        [CV_COLOR_CMYK] = NULL
    }
};

/* Internal */
static int colorspace_map_index( CVColorSpace type){

    if( (int)type < 0 || type >= CV_COLOR_COUNT)
        return -1;

    return (int)type;
}

/* public */
bool cv_colorspace_isvalid(CVColorSpace color_space){
    return colorspace_map_index(color_space) > 0;
}

int cv_colorspace_channels(CVColorSpace color_space){

    int index = colorspace_map_index(color_space);

    if( index < 0)
        return -1;

    return mapping[index].channels;
}

const char* cv_colorspace_name(CVColorSpace color_space){

    int index = colorspace_map_index(color_space);

    if( index < 0)
        return "INVALID";

    return mapping[index].name;
}

bool cv_colorspace_convert_pixel(
    const void* src_pixel,
    CVColorSpace src_space,
    void* dest_pixel,
    CVColorSpace dest_space,
    CVType type
){

    /* validate input */
    if( 
        src_pixel == NULL                   ||
        dest_pixel == NULL                  ||
        !cv_type_is_valid(type)
    )
        return false;

    /* validate color spaces */
    int src_idx = colorspace_map_index(src_space);
    int dest_idx = colorspace_map_index(dest_space);

    if( src_idx <= 0 || dest_idx <= 0)
        return false;

    /* call converter */
    return converters[src_idx][dest_idx](src_pixel, dest_pixel, type);
}






