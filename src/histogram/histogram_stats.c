/* Default includes */
#include <stdlib.h>
#include <string.h>

/* Public inclues*/
#include "cutievanilla.h"

#include "histogram_internal.h"


size_t cv_histogram_total(const CVHistogram* histogram){

    if(histogram == NULL)
        return 0;


    size_t amount = 0;

    for(size_t bin = 0; bin < histogram->bins; bin++){

        if (SIZE_MAX - amount < histogram->count[bin])
            return SIZE_MAX;

        amount += histogram->count[ bin ];
    }

    return amount;
}

bool cv_histogram_min(const CVHistogram* histogram, void* value){

    if(histogram == NULL || value == NULL)
        return false;


    void* min;
        
    CVType type = histogram->type;

    for(size_t bin = 1; bin < histogram->bins; bin++){

        void* curr = &histogram->value[ bin ];

        if( cv_type_compare(type, min, curr) < 0){
            min = curr;
        }
    }

    return cv_type_copy(type, value, min);
}

bool cv_histogram_max(const CVHistogram* histogram, void* value){

    if(histogram == NULL || value == NULL)
        return false;

    void* max;        
    CVType type = histogram->type;

    for(size_t bin = 1; bin < histogram->bins; bin++){

        void* curr = &histogram->value[ bin ];

        if( cv_type_compare(type, max, curr) > 0){
            max = curr;
        }
    }

    return cv_type_copy(type, value, max);
}

bool cv_histogram_mean(const CVHistogram* histogram, void* value){

    for(size_t bin = 1; bin < histogram->bins; bin++){

        void* curr = &histogram->value[ bin ];




    }



}

bool cv_histogram_median(const CVHistogram* histogram, void* value){

    CVHistogram* clone = cv_histogram_clone(histogram);

    cv_histogram_qsort(clone);






}

bool cv_histogram_variance(const CVHistogram* histogram, void* value){

}
