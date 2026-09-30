
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla/histogram.h"

#include "txt_io.h"

CVHistogram* cv_txt_load( const char* filename){
    printf("carregado TXT!\n");

    return NULL;
}

int cv_txt_save(CVHistogram* image, const char* filename){
    printf("salvo TXT!\n");

    return 1;
}

bool cv_is_valid_txt_file(const char* filename){
    printf("validado TXT!\n");
    return true;
}
