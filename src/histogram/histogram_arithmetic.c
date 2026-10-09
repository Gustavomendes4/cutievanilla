
/* Default includes */
#include <stdlib.h>
#include <string.h>

/* Public inclues*/
#include "cutievanilla.h"

#include "histogram_internal.h"

bool cv_histogram_add_count(CVHistogram *histogram, size_t bin, int64_t count){

    if (histogram == NULL)
        return false;

    if (bin >= histogram->bins)
        return false;

    /*  ========    Prositive input     ========*/
    if(count >= 0){

        uint64_t amount = (uint64_t)count;

        // Overflow protection
        if (amount > SIZE_MAX - histogram->count[bin])
            return false;

        histogram->count[bin] += (size_t)amount;
    }

    /*  ========    Negative input     ========*/
    else{

        uint64_t amount = (uint64_t)(-(count + 1)) + 1;

        // Underflow protection
        if(amount >= histogram->count[bin])
            histogram->count[bin] = 0;
        else
            histogram->count[bin] -= (size_t)amount;
    }

    return true;
}

bool cv_histogram_add(CVHistogram *histogram, const void* value, int64_t count){

    if( histogram == NULL || value == NULL)
        return false;

    if(count == 0)
        return true;

    size_t bin = get_value_bin(histogram, value);

    if( bin == CV_INVALID_INDEX)
        return false;

    return cv_histogram_add_count(histogram, bin, count);
}

bool cv_histogram_add_histogram(CVHistogram *dst, const CVHistogram *src);

bool cv_histogram_subtract_histogram(CVHistogram *dst, const CVHistogram *src);