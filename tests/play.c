
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"

#include "cutievanilla/draw.h"

int main(int argc, char* argv[]){

    const char* path_in  = "C:\\Users\\Gustavo\\Desktop\\cutievanilla\\images\\raw\\Gustavo.bmp";
    const char* path_out = "C:\\Users\\Gustavo\\Desktop\\cutievanilla\\images\\saida.bmp";
 
    /* Open image */
    CVImage* image = cv_image_load(path_in);

    if( image == NULL ){
        printf("Erro ao abrir imagem.\n");
        return -1;
    }


    cv_draw_region(image, CV_REGION(10, 10, 80, 80), U8_LIST(0, 255, 255), 10);

    cv_draw_region(image, CV_REGION(10, 10, 80, 80), U8_LIST(255, 0, 0), 3);

    cv_draw_region(image, CV_REGION(10, 10, 80, 80), U8_LIST(0, 0, 255), 1);

    if( cv_image_save(image, path_out) != 0 ){
        printf("Erro para salvar imagem.\n");
    }

    /* End of program */
    cv_image_free(image);
    printf("Sucesso!!\n");
    return 0;
}