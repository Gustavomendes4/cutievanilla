
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include "cutievanilla.h"
#include "cutievanilla/matrix.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));

    const char* path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\icon.bmp";

    const char* path_saida = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\saida.bmp";

    // CVImage* img = cv_image_load(path);

    CVImage* img2 = cv_image_create(1920, 1920, CV_COLOR_RGBA, CV_IMAGE_DATA_UINT8);

    CVMatrix* matrix = cv_matrix_create(6, SZ_LIST(10, 10, 10, 10, 10, 10), CV_MATRIX_FLOAT64);

    printf("matrix criada:\n");
    
    //
    printf("type: [%lu] %s\n", (long)cv_matrix_element_size(matrix), cv_matrix_type_name(matrix->type));

    //
    long dim = (long)cv_matrix_get_dimension(matrix);
    printf("dimensions: %lu\n", dim);

    //
    const size_t* shape = cv_matrix_get_shape(matrix);
    printf("shape: {");
    for(int i = 0; i < dim; i++)
        printf(" %lu,", shape[i]);
    printf("}\n");

    //
    printf("total: %lu\n", (long)cv_matrix_element_count(matrix)); 
    
    
    
    
    

    if(img2 == NULL){
        printf("Deu ruim");
        exit(1);
    }

    
    for(int x = 0; x < 1920; x++){

        for(int y = 0; y < 1920; y++){

            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;

            // cv_image_set_pixel(img2, x, y, R(r, g, b));
            cv_image_set_channel(img2, x, y, 0, &r);
            cv_image_set_channel(img2, x, y, 1, &g);
            cv_image_set_channel(img2, x, y, 2, &b);

        }


    }
    
    
    int n = cv_image_save(img2, path_saida);

    cv_image_free(img2);
    
    printf("TUDO CERTO! (%d)\n", n);

    return 0;

}
