
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "colorspace_internal.h"

static bool rgb_unpack_pixel(const void* src_pixel, void** r, void** g, void** b, CVType type){

    size_t size = cv_type_size(type);

    if(size == 0) return false;

    const uint8_t* vec = src_pixel;

    *r = (void*)(vec + (size * 0));
    *g = (void*)(vec + (size * 1));
    *b = (void*)(vec + (size * 2));

    return true;
}

bool rgb_to_gray(const void* src_pixel, void* dest_pixel, CVType type){
    // Gray = (0.299 * R) + (0.587 * G) + (0.114 * B)
    double R, G, B;
    void *r, *g, *b;

    /* get r, g, b values */
    if( !rgb_unpack_pixel(src_pixel, &r, &g, &b, type) )
        return false;

    /* convert to double */
    if(
        cv_type_convert(r, type, &R, CV_FLOAT64) != TYPE_OK ||
        cv_type_convert(g, type, &G, CV_FLOAT64) != TYPE_OK ||
        cv_type_convert(b, type, &B, CV_FLOAT64) != TYPE_OK
    ){
        return false;
    }

    // apply formula
    double value = (0.299 * R) + (0.587 * G) + (0.114 * B);

    /* convert to main type again */
    return cv_type_convert(&value, CV_FLOAT64, dest_pixel, type) == TYPE_OK;
}

bool rgb_to_rgba(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_rgba - not implemented");

    return false;
}

bool rgb_to_bin(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_bin - not implemented");

    return false;
}

bool rgb_to_hsv(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_hsv - not implemented");

    return false;
}

bool rgb_to_hsl(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_hsl - not implemented");

    return false;
}

bool rgb_to_bgr(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_bgr - not implemented");

    return false;
}

bool rgb_to_bgra(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_bgra - not implemented");

    return false;
}

bool rgb_to_cmyk(const void* src_pixel, void* dest_pixel, CVType type){
    (void)src_pixel;
    (void)dest_pixel;
    (void)type;

    printf("rgb_to_cmyk - not implemented");

    return false;
}
