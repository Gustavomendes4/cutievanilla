
#include <stdlib.h>
#include <string.h>

#include <limits.h>

#include "matrix.h"

#define INVALID_INDEX SIZE_MAX

//  Local functions
static size_t calc_linear_index(const CVMatrix* matrix, const size_t* indices){

    if( matrix == NULL || indices == NULL)
        return INVALID_INDEX;

    size_t index = 0;

    for(size_t i = 0; i < matrix->dimension; i++){

        if( indices[i] >= matrix->shape[i])
            return INVALID_INDEX;

        index = index * matrix->shape[i] + indices[i];
    }

    return index;
}


/* Construction / Destruction */
CVMatrix* cv_matrix_create( size_t dimension, const size_t* shape, CVMatrixType type){

    if( dimension == 0 || shape == NULL )
        return NULL;

    /* get element size*/
    size_t element_size = cv_matrix_type_size(type);
    /* validate element */
    if( element_size == 0 )
        return NULL;


    /* calculate total number of elements */
    size_t total_elements = 1;

    for( size_t i = 0; i < dimension; i++ ){

        if( shape[i] == 0 )
            return NULL;

        // Verifica overflow antes da multiplicação:
        if (total_elements > SIZE_MAX / shape[i]) {
            return NULL;
        }

        total_elements *= shape[i];
    }


    /* allocate matrix */
    CVMatrix* matrix = (CVMatrix*) malloc(sizeof(CVMatrix));

    if( matrix == NULL )
        return NULL;

    /* allocate shape */
    matrix->shape = (size_t*) malloc(dimension * sizeof(size_t));
    
    if (matrix->shape == NULL ){
        free(matrix);
        return NULL;
    }

    /* allocate matrix data */
    matrix->data = calloc(total_elements, element_size);

    if (matrix->data == NULL) {
        free(matrix->shape);
        free(matrix);
        return NULL;
    }


    /* fill struct */
    matrix->type = type;

    matrix->dimension = dimension;

    matrix->total_elements = total_elements;
    
    matrix->element_size = element_size;

    memcpy(matrix->shape, shape, dimension * sizeof(size_t));

    return matrix;
}

void cv_matrix_free(CVMatrix* matrix){

    if( !matrix ) return;

    if( matrix->shape )
        free(matrix->shape);

    if( matrix->data )
        free(matrix->data);
    
    free(matrix);

}

CVMatrix* cv_matrix_clone(const CVMatrix* matrix){

}


/* type */
size_t cv_matrix_type_size(CVMatrixType type){

    switch(type){
        case CV_MATRIX_UINT8:
        case CV_MATRIX_INT8:
            return 1;

        case CV_MATRIX_UINT16:
        case CV_MATRIX_INT16:
            return 2;

        case CV_MATRIX_UINT32:
        case CV_MATRIX_INT32:
        case CV_MATRIX_FLOAT32:
            return 4;

        case CV_MATRIX_FLOAT64:
            return 8;

        default:
            return 0;
    }

}

const char *cv_matrix_type_name(CVMatrixType type){

    switch(type){
        case CV_MATRIX_UINT8:
            return "uint8";
        
        case CV_MATRIX_INT8:
            return "int8";

        case CV_MATRIX_UINT16:
            return "uint16";
        
        case CV_MATRIX_INT16:
            return "int16";

        case CV_MATRIX_UINT32:
            return "uint32";

        case CV_MATRIX_INT32:
            return "int32";

        case CV_MATRIX_FLOAT32:
            return "float32";

        case CV_MATRIX_FLOAT64:
            return "float64";

        default:
            return "None";
    }

}


/* access */
const void* cv_matrix_get(const CVMatrix* matrix, const size_t* indices){

    if( matrix == NULL || indices == NULL)
        return NULL;

    size_t index = calc_linear_index(matrix, indices);

    return cv_matrix_get_flat(matrix, index);
}

const void* cv_matrix_get_flat(const CVMatrix* matrix, size_t index){

    if( matrix == NULL)
        return NULL;

    if( index >= matrix->total_elements)
        return NULL;

    return (char*)matrix->data + (index * matrix->element_size);
}

void cv_matrix_set(CVMatrix* matrix, const size_t* indices, const void* value){

    if( matrix == NULL || indices == NULL)
        return;

    size_t index = calc_linear_index(matrix, indices);

    if( index == INVALID_INDEX )
        return;

    cv_matrix_set_flat(matrix, index, value);
}

void cv_matrix_set_flat(CVMatrix* matrix, size_t index, const void* value){

    if( matrix == NULL || value == NULL)
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


/* Data */
void cv_matrix_fill(CVMatrix *matrix, const void *value){

}
