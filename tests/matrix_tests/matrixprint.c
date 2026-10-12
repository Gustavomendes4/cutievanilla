
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"
#include "cutievanilla/matrix.h"

#include <stdint.h>


int main(int argc, char *argv[]) {

    CVMatrix* mat = cv_matrix_create(3, SZ_LIST(10, 10, 10), CV_UINT8);

    uint8_t value = 10;

    cv_matrix_set(mat, (size_t[]){2, 6, 6}, &value);

    cv_matrix_set(mat, (size_t[]){2, 6, 6}, U8_LIST(10));

    //  Imprime matriz
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){

            for(int k = 0; k < 10; k++){

                uint8_t* dado = cv_matrix_get(mat, (size_t[]){i, j, k});

                printf(" %d | ", (int)(*dado));
            }
            printf("\n");
        }
        printf("\n\n");
    }


}


