#include <string.h>
#include <stdio.h>

#include "cutievanilla.h"
#include "matrix_internal.h"

size_t calc_linear_index(const CVMatrix* matrix, const size_t* indices){

    if( matrix == NULL || indices == NULL)
        return INVALID_INDEX;

    size_t index = 0;

    for(size_t i = 0; i < matrix->dimension; i++){

        if( indices[i] >= matrix->shape[i]){
            return INVALID_INDEX;
        }

        index = index * matrix->shape[i] + indices[i];
    }

    return index;
}

const void* cv_matrix_get_linear(const CVMatrix* matrix, size_t index){

    if( !cv_matrix_isvalid(matrix) )
        return NULL;

    if( index >= matrix->total_elements)
        return NULL;

    return (char*)matrix->data + (index * matrix->element_size);
}

void cv_matrix_set_linear(CVMatrix* matrix, size_t index, const void* value){

    if( !cv_matrix_isvalid(matrix) || value == NULL)
        return;

    if( index >= matrix->total_elements)
        return;

    memcpy(
        (char *)matrix->data +
        (index * matrix->element_size),
        value,
        matrix->element_size
    );

}