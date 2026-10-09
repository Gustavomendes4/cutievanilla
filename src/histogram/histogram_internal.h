/*


    This file describe functions used internally in lib for manipulation histogram.

    THIS FUNCTIONS IS NOT PUBLIC.


*/

#ifndef CV_HISTOGRAM_INTERNAL_H_INCLUDED
#define CV_HISTOGRAM_INTERNAL_H_INCLUDED

#include <string.h>

#include "cutievanilla/type.h"
#include "cutievanilla/histogram.h"

size_t get_value_bin(const CVHistogram* histogram, const void* value);

bool cv_histogram_qsort(CVHistogram* histogram);


#endif //CV_HISTOGRAM_INTERNAL_H_INCLUDED