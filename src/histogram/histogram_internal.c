
#include "histogram_internal.h"

#include "cutievanilla/type.h"

size_t get_value_bin(const CVHistogram* histogram, const void* value){

    if (histogram == NULL || value == NULL)
        return CV_INVALID_INDEX;

    const uint8_t* values = (const uint8_t*)histogram->value;

    for( size_t bin = 0; bin < histogram->bins; bin++){

        const void *bin_value = values + (bin * histogram->element_size);

        // if( memcmp(bin_value, value, histogram->element_size) == 0){
        if( cv_type_equals(histogram->type, bin_value, value) ){
            return bin;
        }
    }

    return CV_INVALID_INDEX;
}

bool cv_histogram_qsort(CVHistogram* histogram){
    
    return true;
}
