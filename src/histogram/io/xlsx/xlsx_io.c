
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla/histogram.h"

#include "xlsx_io.h"

CVHistogram* cv_xlsx_load( const char* filename){
    printf("carregado XLSX!\n");

    return NULL;
}

int cv_xlsx_save(CVHistogram* image, const char* filename){
    printf("salvo XLSX!\n");

    return 1;
}

bool cv_is_valid_xlsx_file(const char* filename){
    printf("validado XLSX!\n");
    return true;
}
