
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"

int main(int argc, char* argv[]){

    float num1 = 2.35, num2 = 4.92;

    uint32_t b = 0;

    cv_type_add(CV_UINT32, &b, &b, (uint32_t[]){INT_MAX});

    // int r = (f)num1;

    printf("r: %d, deveria ser : %d", (int)b, INT_MAX);

    return 0;
}
