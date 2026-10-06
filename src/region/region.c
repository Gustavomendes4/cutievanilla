
#include "cutievanilla.h"

#include "cutievanilla/region.h"

/* validation */
bool cv_region_is_valid(CVRegion region){

}

/* geometry */
long cv_region_right(CVRegion region){

}

long cv_region_left(CVRegion region){

}

long cv_region_top(CVRegion region){

}

long cv_region_bottom(CVRegion region){

}

long cv_region_area(CVRegion region){

}


/* relation */
bool cv_region_contains_point(CVRegion region, long x, long y){

}

bool cv_region_contains(CVRegion outer, CVRegion inner){

}

bool cv_region_intersects(CVRegion region1, CVRegion region2){

}

bool cv_region_equals(CVRegion region1, CVRegion region2){

}

/* operations */
CVRegion cv_region_intersection(CVRegion region1, CVRegion region2){

}

CVRegion cv_region_union(CVRegion region1, CVRegion region2){

}

CVRegion cv_region_translated(CVRegion region, long dx, long dy){
    
}
