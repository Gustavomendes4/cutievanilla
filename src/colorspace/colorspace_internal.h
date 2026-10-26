#ifndef CUTIEVANILLA_COLORSPACE_INTERNAL_H_INCLUDED
#define CUTIEVANILLA_COLORSPACE_INTERNAL_H_INCLUDED

#include <stdbool.h>
#include "cutievanilla/type.h"

typedef bool (*CVColorConvertFn)(const double* src, double* dest, CVType dest_type);

bool gray_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool gray_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

bool rgb_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgb_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

bool rgba_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool rgba_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

bool bin_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bin_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

bool hsv_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsv_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

/* from hsl */
bool hsl_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool hsl_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);


bool bgr_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgr_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

bool bgra_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool bgra_to_cmyk(const double* src_pixel, double* dest_pixel, CVType dest_type);

bool cmyk_to_gray(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_rgb(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_rgba(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_bin(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_hsv(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_hsl(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_bgr(const double* src_pixel, double* dest_pixel, CVType dest_type);
bool cmyk_to_bgra(const double* src_pixel, double* dest_pixel, CVType dest_type);


#endif // CUTIEVANILLA_COLORSPACE_INTERNAL_H_INCLUDED
