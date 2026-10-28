#ifndef CUTIEVANILLA_DRAW_H_INCLUDED
#define CUTIEVANILLA_DRAW_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

#include "cutievanilla.h"

int cv_draw_square(CVImage* image, CVRegion square, const void* color);

void cv_draw_region(CVImage* image, CVRegion region, const void* color, int thikness);

#endif //CUTIEVANILLA_DRAW_H_INCLUDED