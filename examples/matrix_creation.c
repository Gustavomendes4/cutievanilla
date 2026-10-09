
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"


int main(int argc, char *argv[]) {

    CVMatrix* matrix = cv_matrix_create(6, SZ_LIST(10, 10, 10, 10, 10, 10), CV_FLOAT32);

    if( matrix == NULL){
        fprintf(stderr, "Error to create matrix\n");
        return -1;
    }

    printf("\nMatrix created successfully!\n\n");
    

    /****   Print matrix values     ****/

    //  Print element size and type
    printf("\ttype:\t\t[%lu] %s\n", (long)cv_matrix_element_size(matrix), cv_matrix_type_name(matrix->type));

    // get and print dimensions
    long dim = (long)cv_matrix_get_dimension(matrix);
    
    printf("\tdimensions:\t%lu\n", dim);

    // print shapes
    const size_t* shape = cv_matrix_get_shape(matrix);
    
    printf("\tshape:\t\t{");
    
    for(int i = 0; i < dim; i++){
        printf(" %lu%c", shape[i], (i+1 < dim) ? ',' : ' ');
    }
    
    printf("}\n");

    // print total of elements in matrix
    printf("\ttotal:\t\t%lu\n", (long)cv_matrix_element_count(matrix)); 

    
    return 0;
}


