
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"


const char* path_in = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\icon.bmp";

const char* path_out = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\icon2.bmp";


int main(int argc, char* argv[]){


    CVImage* img = cv_image_load(path_in);

    for( int i = 0; i < 400; i ++)
    for(int j = 0; j < 400; j++){

        cv_image_set_pixel(img, i + 200, j + 400, U8_LIST(1, 1, 1));

    }

    cv_image_save(img, path_out);

    cv_image_free(img);


    return 0;
}