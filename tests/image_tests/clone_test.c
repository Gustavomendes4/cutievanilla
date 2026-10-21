
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"

#include <stdint.h>

const char* path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\raw\\Gustavo.bmp";

const char* path_saida1 = "..\\..\\image_tests\\saida1.bmp";
const char* path_saida2 = "..\\..\\image_tests\\saida2.bmp";


int main(int argc, char *argv[]) {

    CVImage* img = cv_image_load(path);

    if(img == NULL){
        printf("Erro ao abrir imagem\n");
        return -1;
    }

    CVImage* clone = cv_image_clone(img);
    
    if(clone == NULL){
        printf("Erro ao clonar imagem\n");
        return -2;
    }
    
    /* =========================================== */

    for(int j = 0; j < 30; j++)
    for(int i = 10; i < 40; i++){

        cv_image_set_pixel(img, i, 10+j, U8_LIST(255, 0, 0));
        
        cv_image_set_pixel(clone, i, 10+j, U8_LIST(0, 0, 255));
    }

    /* =========================================== */

    cv_image_save(img, path_saida1);
    cv_image_save(clone, path_saida2);

    cv_image_free(img);
    cv_image_free(clone);

    return 0;
}


