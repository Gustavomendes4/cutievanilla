
#include <limits.h>
#include "cutievanilla.h"

/* validation */
bool cv_region_is_valid(CVRegion region){
    return region.height > 0 && region.width > 0;
}

/* geometry */
long cv_region_right(CVRegion region){
    return region.x + region.width;
}

long cv_region_left(CVRegion region){
    return region.x;
}

long cv_region_top(CVRegion region){
    return region.y;
}

long cv_region_bottom(CVRegion region){
    return region.y + region.height;
}

long cv_region_area(CVRegion region){
    return region.width * region.height;
}

long cv_region_center_x(CVRegion region){
    return region.x + (region.width / 2);
}

long cv_region_center_y(CVRegion region){
    return region.y + (region.height/ 2);
}

/* relation */
bool cv_region_contains_point(CVRegion region, long x, long y){

    return (
        x >= cv_region_left(region) &&
        x <  cv_region_right(region) &&

        y >= cv_region_top(region) &&
        y <  cv_region_bottom(region)
    );
}

bool cv_region_contains(CVRegion outer, CVRegion inner){

    return (
        cv_region_left(inner) >= cv_region_left(outer) &&
        cv_region_right(inner) <= cv_region_right(outer) &&
        cv_region_top(inner) >= cv_region_top(outer) &&
        cv_region_bottom(inner) <= cv_region_bottom(outer)
    );
}

bool cv_region_intersects(CVRegion region1, CVRegion region2){

    // Duas regiões se interceptam se uma NÃO estiver totalmente 
    // à esquerda, à direita, acima ou abaixo da outra.
    return (
        cv_region_left(region1) < cv_region_right(region2) &&
        cv_region_right(region1) > cv_region_left(region2) &&
        cv_region_top(region1) < cv_region_bottom(region2) &&
        cv_region_bottom(region1) > cv_region_top(region2)
    );
}

bool cv_region_equals(CVRegion region1, CVRegion region2){

    return (
        region1.width == region2.width   &&
        region1.height == region2.height &&
        region1.x == region2.x           &&
        region1.y == region2.y
    );

}

/* operations */
CVRegion cv_region_intersection(CVRegion region1, CVRegion region2){

    if (!cv_region_intersects(region1, region2)) {
        return CV_REGION(0, 0, 0, 0);
    }

    long left   = CV_MAX(cv_region_left(region1), cv_region_left(region2));
    long top    = CV_MAX(cv_region_top(region1), cv_region_top(region2));
    long right  = CV_MIN(cv_region_right(region1), cv_region_right(region2));
    long bottom = CV_MIN(cv_region_bottom(region1), cv_region_bottom(region2));

    return CV_REGION(left, top, right - left, bottom - top);
}

CVRegion cv_region_union(CVRegion region1, CVRegion region2){
    
    if (!cv_region_is_valid(region1)) return region2;
    if (!cv_region_is_valid(region2)) return region1;

    long left   = CV_MIN(cv_region_left(region1), cv_region_left(region2));
    long top    = CV_MIN(cv_region_top(region1), cv_region_top(region2));
    long right  = CV_MAX(cv_region_right(region1), cv_region_right(region2));
    long bottom = CV_MAX(cv_region_bottom(region1), cv_region_bottom(region2));

    return CV_REGION(left, top, right - left, bottom - top);
}

CVRegion cv_region_translated(CVRegion region, long dx, long dy){
    return CV_REGION(region.x + dx, region.y + dy, region.width, region.height);
}

CVRegion cv_region_subregion(CVRegion region, long x, long y, long width, long height){
    
    CVRegion subregion = CV_REGION(
        region.x + x,
        region.y + y,
        width,
        height
    );

    return subregion;
    // return cv_region_intersection(region, subregion); // limit in dad region

}

bool cv_region_split(CVRegion region, int rows, int cols, CVRegion* output){

    /* Validations */
    if( !cv_region_is_valid(region)) return false;

    if( output == NULL) return false;

    if(rows < 1 || cols < 1) return false;

    if (cols > INT_MAX / rows) return false;

    if (rows > region.height || cols > region.width) {
        return false;
    }

    /* calculate dimentions */
    long sub_width = region.width / cols;
    long sub_height = region.height / rows;

    long extra_width = region.width % cols;
    long extra_height = region.height % rows;

    /* fill array */
    long y = region.y;

    for (int row = 0; row < rows; row++) {

        long height = sub_height + (row < extra_height ? 1 : 0);
        long x = region.x;

        for (int col = 0; col < cols; col++) {
            long width = sub_width + (col < extra_width ? 1 : 0);

            output[row * cols + col] = CV_REGION(
                x,
                y,
                width,
                height
            );

            x += width;
        }

        y += height;
    }
    return true;
}