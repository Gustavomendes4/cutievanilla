#ifndef CUTIEVANILLA_MATRIX_H_INCLUDED
#define CUTIEVANILLA_MATRIX_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

#include "cutievanilla/type.h"

#define CV_MATRIX_MAGIC_NUMBER 0xCA

typedef struct _CVMatrix{
    
    size_t dimension;       // 1D, 2D, 3D, etc; represent the size of shape and strides arrays

    size_t *shape;          // shape of the matrix, e.g. [rows, cols, channels] ; represent the size of each dimension

    uint16_t magic;

    size_t total_elements;

    CVType type;

    size_t element_size;

    void* data;

}CVMatrix;

/* Construction / Destruction */
CVMatrix* cv_matrix_create( size_t dimension, const size_t* shape, CVType type);

void cv_matrix_free(CVMatrix* matrix);

CVMatrix* cv_matrix_clone(const CVMatrix* matrix);

/* Type */
size_t cv_matrix_get_dimension(const CVMatrix *matrix);

const size_t *cv_matrix_get_shape(const CVMatrix *matrix);

size_t cv_matrix_element_count(const CVMatrix *matrix);

size_t cv_matrix_element_size(const CVMatrix *matrix);

/* access */
const void* cv_matrix_get(const CVMatrix* matrix, const size_t* indices);

const void* cv_matrix_get_flat(const CVMatrix* matrix, size_t index);

void cv_matrix_set(CVMatrix* matrix, const size_t* indices, const void* value);

void cv_matrix_set_flat(CVMatrix* matrix, size_t index, const void* value);


/* Data */
void cv_matrix_fill(CVMatrix *matrix, const void *value);

/* comparation */
bool cv_matrix_same_shape(const CVMatrix *a, const CVMatrix *b);

bool cv_matrix_same_type(const CVMatrix *a, const CVMatrix *b);



#endif // CUTIEVANILLA_MATRIX_H_INCLUDED