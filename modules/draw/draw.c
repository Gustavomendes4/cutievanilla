
#include <stdio.h>

#include "cutievanilla.h"
#include "cutievanilla/draw.h"

int cv_draw_square(CVImage* image, CVRegion square, const void* color){

    if( !cv_image_isvalid(image) )
        return -1;


    size_t width = cv_image_width(image);
    size_t height = cv_image_height(image);

    CVRegion valid_region = CV_REGION(
        0, 0,
        width,
        height
    );

    if( !cv_region_intersects(valid_region, square))
        return 1;

    valid_region = cv_region_intersection(valid_region, square);


    for( size_t x = cv_region_left(valid_region); x < cv_region_right(valid_region); x++)

    for( size_t y = cv_region_top(valid_region); y < cv_region_bottom(valid_region); y++){

        cv_image_set_pixel(image, x, y, color);

    }



}

void cv_draw_region(CVImage* image, CVRegion region, const void* color, int thickness){

    if( !cv_image_isvalid(image) )
        return;

    if(thickness <= 0 || thickness > 30)
        return;

    long top = cv_region_top(region);
    long bottom = cv_region_bottom(region);
    long left = cv_region_left(region);
    long right = cv_region_right(region);
    
    
    // validation

    if( !cv_region_intersects(region, region))
        return;

    /* draw top bar*/
    cv_draw_square(
        image,
        CV_REGION(region.x, region.y, region.width, thickness),
        color
    );
    
    /* draw bottom bar*/
    cv_draw_square(
        image,
        CV_REGION(region.x, region.y + region.height - thickness, region.width, thickness),
        color
    );
    
    /* draw left bar*/
    cv_draw_square(
        image,
        CV_REGION(region.x, region.y, thickness, region.height),
        color
    );
    
    /* draw right bar*/
    cv_draw_square(
        image,
        CV_REGION(region.x + region.width - thickness, region.y, thickness, region.height),
        color
    );
    


}