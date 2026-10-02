#ifndef CUTIEVANILLA_HISTOGRAM_H_INCLUDED
#define CUTIEVANILLA_HISTOGRAM_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

#include "matrix.h"

#define CV_INVALID_INDEX SIZE_MAX

typedef struct _CVHistogram{
    
    size_t bins;        // number of bins (number of elements in 'value' and in 'count')

    size_t element_size; // size of each value element

    CVType type;  // type of each value

    void* value;        // value represented by each bin (typped by 'type')

    size_t* count;      // number of occurrences of each value

}CVHistogram;

/* forware declaration */
typedef struct _CVImage CVImage;
typedef struct _CVMatrix CVMatrix;


/* ====== IO interface ====== */
CVHistogram* cv_histogram_load(const char* filename);

int cv_histogram_save(CVHistogram* histogram, const char* filename);

CVHistogram* cv_histogram_clone(const CVHistogram* histogram);

/* ====== Creation / Destruction ====== */
CVHistogram* cv_histogram_create(size_t bins, CVType type);

void cv_histogram_free(CVHistogram** hist);

/* ====== Properties ====== */
size_t cv_histogram_bins(const CVHistogram *histogram);

size_t cv_histogram_element_size(const CVHistogram *histogram);

CVType cv_histogram_type(const CVHistogram *histogram);


/* ====== Read ====== */
bool cv_histogram_get_value(const CVHistogram *histogram, size_t bin, void *value);

size_t cv_histogram_get_count(const CVHistogram *histogram, size_t bin);


/* ====== Write ====== */
bool cv_histogram_set_value(CVHistogram *histogram, size_t bin, const void *value);

bool cv_histogram_set_count(CVHistogram *histogram, size_t bin, size_t count);


/* ====== Modification ====== */
bool cv_histogram_add_count(CVHistogram *histogram, size_t bin, int64_t count);

bool cv_histogram_add(CVHistogram *histogram, const void* value, int64_t count);

void cv_histogram_clear_counts(CVHistogram *histogram);

void cv_histogram_clear_values(CVHistogram *histogram);

void cv_histogram_clear(CVHistogram *histogram);

bool cv_histogram_init_values(CVHistogram *histogram, const void *start, const void *step);

#endif //CUTIEVANILLA_HISTOGRAM_H_INCLUDED
