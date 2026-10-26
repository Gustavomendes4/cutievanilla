
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"


const char* path_in = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\raw\\Iara.bmp";

const char* path_out = ".\\out.bmp";


int main(int argc, char* argv[]){


    CVImage* img = cv_image_load(path_in);

    CVImage* out = cv_image_convert(img, CV_COLOR_GRAY);

    if( out == NULL){
        printf("convert retornou NULL\n");
        return -2;
    }

    int n = cv_image_save(out, path_out);

    if( n != 0){
        printf("save retornou [%d]\n", n);
        return -2;
    }


    cv_image_free(img);
    cv_image_free(out);

    printf("Sucesso!!\n");
    return 0;
}