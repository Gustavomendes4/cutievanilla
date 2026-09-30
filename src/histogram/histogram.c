
/* Default includes */
#include <stdlib.h>
#include <string.h>

/* External includes*/
#include "filecore.h"

/* Public inclues*/
#include "cutievanilla/type.h"
#include "cutievanilla/histogram.h"

/* Internal includes */
#include "io/histogram_io.h"
#include "histogram_internal.h"

CVHistogram* cv_histogram_create(size_t bins, CVType type){

    /* ====== Validate input ======*/
    if( bins == 0) return NULL;

    size_t element_size = cv_type_size(type);

    if( element_size == 0 ) return NULL;

    /* ====== Alloc structure ======*/
    CVHistogram* hist = malloc( sizeof(CVHistogram) );

    if( hist == NULL )return NULL;

    /* ====== Alloc values vector ======*/
    hist->value = calloc(bins, element_size);

    if( hist->value == NULL){
        free(hist);
        return NULL;
    }

    /* ====== Alloc values count vector ======*/
    hist->count = calloc(bins, sizeof(*(hist->count)));

    if(hist->count == NULL){
        free(hist->value);
        free(hist);
        return NULL;
    }

    /* ====== Fill structure and return ======*/
    hist->bins = bins;

    hist->element_size = element_size;

    hist->type = type;

    return hist;
}

void cv_histogram_free(CVHistogram** histogram){

    if( histogram == NULL || *histogram == NULL ) return;

    free( (*histogram)->value);

    free( (*histogram)->count);

    free( (*histogram) );

    *histogram = NULL;
}

CVHistogram* cv_histogram_clone(const CVHistogram* histogram){

    if( histogram == NULL)
        return NULL;

    CVHistogram* newhist = cv_histogram_create(histogram->bins, histogram->type);


    /* copy values vector */
    size_t total_values_bytes = cv_histogram_bins(newhist) * cv_histogram_element_size(newhist);

    memcpy(newhist->value, histogram->value, total_values_bytes);

    /* copy count vector */
    size_t total_count_bytes = cv_histogram_bins(newhist) * sizeof(newhist->count[0]);

    memcpy(newhist->count, histogram->count, total_count_bytes);

    return newhist;
}

/*  Inicializacao de bins   /   Melhorar essa gambiarra */
bool cv_histogram_init_values(CVHistogram *histogram, const void *start, const void *step){

    if( histogram == NULL || start == NULL || step == NULL)
        return false;
        
    uint8_t* values = histogram->value;

    for(size_t bin = 0; bin < histogram->bins; bin++){

        // get initial bin addres
        uint8_t* addr = values + (bin * histogram->element_size);


        switch (histogram->type) {

            case CV_UINT8: {
                uint8_t value = *(const uint8_t *)start + (uint8_t)bin * *(const uint8_t *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_INT8: {
                int8_t value = *(const int8_t *)start + (int8_t)bin * *(const int8_t *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_UINT16: {
                uint16_t value = *(const uint16_t *)start + (uint16_t)bin * *(const uint16_t *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_INT16: {
                int16_t value = *(const int16_t *)start + (int16_t)bin * *(const int16_t *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_UINT32: {
                uint32_t value = *(const uint32_t *)start + (uint32_t)bin * *(const uint32_t *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_INT32: {
                int32_t value = *(const int32_t *)start + (int32_t)bin * *(const int32_t *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_FLOAT32: {
                float value = *(const float *)start + (float)bin * *(const float *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

            case CV_FLOAT64: {
                double value = *(const double *)start + (double)bin * *(const double *)step;

                memcpy(addr, &value, sizeof(value));
                break;
            }

        default:
            return false;
        }
    }

    return true;
}

CVHistogram* cv_histogram_load(const char* filename){

    if( !fc_isValidPath(filename) ) return NULL;

    if( !fc_existsFile(filename) ) return NULL;

    return cv_histogram_io_load(filename);
}

int cv_histogram_save(CVHistogram* histogram, const char* filename){

    if( !fc_isValidPath(filename) ) return -1;

    if( !histogram ) return -2;

    return cv_histogram_io_save(histogram, filename);
}

size_t cv_histogram_bins(const CVHistogram *histogram){

    if( histogram == NULL)
        return 0;

    return histogram->bins;
}

size_t cv_histogram_element_size(const CVHistogram *histogram){

    if( histogram == NULL)
        return 0;

    return histogram->element_size;
}

CVType cv_histogram_type(const CVHistogram *histogram){

    if( histogram == NULL)
        return 0;

    return histogram->type;
}

bool cv_histogram_get_value(const CVHistogram *histogram, size_t bin, void *value){

    if( histogram == NULL )
        return false;

    if( value == NULL )
        return false;

    if( histogram->bins <= bin)
        return false;


    void* addr = (uint8_t *)histogram->value + (bin * histogram->element_size);

    memcpy(value, addr, histogram->element_size);

    return true;
}

size_t cv_histogram_get_count(const CVHistogram *histogram, size_t bin){

    if( histogram == NULL )
        return CV_INVALID_INDEX;

    if( histogram->bins <= bin)
        return CV_INVALID_INDEX;

    return histogram->count[bin];
}

bool cv_histogram_set_value(CVHistogram *histogram, size_t bin, const void *value){

    if( histogram == NULL )
        return false;

    if( value == NULL )
        return false;

    if( histogram->bins <= bin)
        return false;

    void* addr = (uint8_t *)histogram->value + (bin * histogram->element_size);

    memcpy(addr, value, histogram->element_size);

    return true;
}

bool cv_histogram_set_count(CVHistogram *histogram, size_t bin, size_t count){

    if( histogram == NULL)
        return false;

    if( histogram->bins <= bin)
        return false;

    histogram->count[bin] = count;

    return true;
}


void cv_histogram_clear_counts(CVHistogram *histogram){

    if( histogram == NULL)
        return;
 
    memset(histogram->count, 0, sizeof(histogram->count) * histogram->bins);
}

void cv_histogram_clear_values(CVHistogram *histogram){
    
    if( histogram == NULL)
        return;

    memset(histogram->value, 0, histogram->element_size * histogram->bins);
}

void cv_histogram_clear(CVHistogram *histogram){

    cv_histogram_clear_counts(histogram);

    cv_histogram_clear_values(histogram);

}
