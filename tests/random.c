
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"

#include <stdint.h>

#include <time.h>


int main(int argc, char *argv[]) {

    srand(time(NULL));

    const char* path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\icon.bmp";

    const char* path_saida = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\saida.bmp";

    // CVImage* img = cv_image_load(path);

    CVImage* img2 = cv_image_create(1920, 1920, CV_COLOR_RGBA, CV_IMAGE_DATA_UINT8);

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


