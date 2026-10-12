
#include <stdio.h>
#include <stdlib.h>

#include "cutievanilla.h"

int main(int argc, char* argv[]){

    CVRegion region = CV_REGION(10, 20, 100, 200);

    CVRegion region_grid[16];

    if( !cv_region_split(region, 3, 3, region_grid) ){
        printf("Erro no split\n");
        return -1;
    }

    for(int i = 0; i < 9; i++){

        printf(
            "[%02d] {%02d, %02d, %02d, %02d}\n",
            i,
            region_grid[i].x,
            region_grid[i].y,
            region_grid[i].width,
            region_grid[i].height
        );

    }

    return 0;
}