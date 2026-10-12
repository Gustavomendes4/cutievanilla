
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"

#include <stdint.h>


int main(int argc, char *argv[]) {

    
    const char* path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\icon.bmp";

    const char* path_saida = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\saida.jpg";

    CVImage* img = cv_image_load(path);

    if(img == NULL)
        printf("Deu ruim");




    /*==========*/
    CVMatrix* mx = img->matrix;


    uint8_t max = 255, min = 0;


    size_t offset = mx->shape[0] / 2;

    for( size_t x = 10; x < 1000; x++){

        for( size_t y = 0; y < 10; y++){

            cv_matrix_set(mx, (size_t[]){x, y+80, 0}, &min); // r
            cv_matrix_set(mx, (size_t[]){x, y+80, 1}, &max); // g
            cv_matrix_set(mx, (size_t[]){x, y+80, 2}, &min); // b
        }

    }
    
    
    cv_image_save(path_saida, img);

    cv_image_free(img);

    return 0;
}


