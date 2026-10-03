
#include <stdlib.h>
#include <string.h>

#include <limits.h>

#include "cutievanilla/matrix.h"

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

static bool is_matrix_valid(const CVMatrix* matrix){

    if(matrix == NULL || matrix->magic != CV_MATRIX_MAGIC_NUMBER)
        return false;

    return true;
}

/* ========================= */

CVMatrix* cv_matrix_create( size_t dimension, const size_t* shape, CVType type){

    if( dimension == 0 || shape == NULL )
        return NULL;

    /* get element size*/
    size_t element_size = cv_type_size(type);
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

    // Overflow security
    if (total_elements > SIZE_MAX / element_size)
        return NULL;


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

    matrix->magic = CV_MATRIX_MAGIC_NUMBER;

    memcpy(matrix->shape, shape, dimension * sizeof(size_t));

    return matrix;
}

void cv_matrix_free(CVMatrix* matrix){

    if( matrix == NULL ) return;

    matrix->magic = 0;
    
    free(matrix->shape);
    
    free(matrix->data);

    free(matrix);
}

CVMatrix* cv_matrix_clone(const CVMatrix* matrix){

    if( !is_matrix_valid(matrix) ){
        return NULL;
    }

    size_t dimension = cv_matrix_get_dimension(matrix);

    const size_t* shape = cv_matrix_get_shape(matrix);

    CVType type = matrix->type;

    CVMatrix* newMatrix = cv_matrix_create(dimension, shape, type);

    if( !is_matrix_valid(newMatrix) ){
        return NULL;
    }

    size_t total_bytes = (cv_matrix_element_size(matrix) * cv_matrix_element_count(matrix));

    memcpy( newMatrix->data, matrix->data, total_bytes);
    
    return newMatrix;
}

size_t cv_matrix_get_dimension(const CVMatrix *matrix){
    
    if( !is_matrix_valid(matrix) )
        return 0;

    return matrix->dimension;
}

const size_t *cv_matrix_get_shape(const CVMatrix *matrix){
    
    if( !is_matrix_valid(matrix) )
        return NULL;

    return matrix->shape;
}

size_t cv_matrix_element_count(const CVMatrix *matrix){
    
    if( !is_matrix_valid(matrix) )
        return 0;

    return matrix->total_elements;
}

size_t cv_matrix_element_size(const CVMatrix *matrix){
    
    if( !is_matrix_valid(matrix) )
        return 0;
    
    return matrix->element_size;
}

const void* cv_matrix_get(const CVMatrix* matrix, const size_t* indices){

    if( !is_matrix_valid(matrix) || indices == NULL)
        return NULL;

    size_t index = calc_linear_index(matrix, indices);

    return cv_matrix_get_flat(matrix, index);
}

const void* cv_matrix_get_flat(const CVMatrix* matrix, size_t index){

    if( !is_matrix_valid(matrix) )
        return NULL;

    if( index >= matrix->total_elements)
        return NULL;

    return (char*)matrix->data + (index * matrix->element_size);
}

void cv_matrix_set(CVMatrix* matrix, const size_t* indices, const void* value){

    if( !is_matrix_valid(matrix) || indices == NULL )
        return;

    size_t index = calc_linear_index(matrix, indices);

    cv_matrix_set_flat(matrix, index, value);
}

void cv_matrix_set_flat(CVMatrix* matrix, size_t index, const void* value){

    if( !is_matrix_valid(matrix) || value == NULL)
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

void cv_matrix_fill(CVMatrix *matrix, const void *value){

    if (!is_matrix_valid(matrix) || value == NULL)
        return;

    for (size_t i = 0; i < matrix->total_elements;i++){
        cv_matrix_set_flat(matrix, i, value);
    }
}

bool cv_matrix_same_shape(const CVMatrix *a, const CVMatrix *b){

    if( !is_matrix_valid(a) || !is_matrix_valid(b))
        return false;

    if(a->dimension != b->dimension)
        return false;

    
    for( size_t i = 0; i < a->dimension; i++){

        if(a->shape[i] != b->shape[i])
            return false;
    }

    return true;
}

bool cv_matrix_same_type(const CVMatrix *a, const CVMatrix *b){

    if( !is_matrix_valid(a) || !is_matrix_valid(b))
        return false;

    return a->type ==  b->type;
/*
    if( a->type !=  b->type )
        return false;

    if( a->type == CV_TYPE_UNKNOWED)
        return a->element_size == b->element_size;
    return true;

*/
}
