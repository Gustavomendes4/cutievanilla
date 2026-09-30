

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include "cutievanilla.h"
#include "cutievanilla/matrix.h"
#include "cutievanilla/histogram.h"

int main(int argc, char *argv[]){

    uint8_t start = 0, step = 1;

    CVHistogram* hist = cv_histogram_create(256, CV_UINT8);

    cv_histogram_init_values(hist, &start, &step);
    
    /* Initialize bin counts */
    for( size_t i = 0; i < cv_histogram_bins(hist) ; i++){
        cv_histogram_set_count(hist, i, i * 11);
    }
    
    /* print histogram */    
    for( size_t i = 0; i < cv_histogram_bins(hist) ; i++){
    
        int count;
        uint8_t value;
        cv_histogram_get_value(hist, i, &value);

        count = (int)cv_histogram_get_count(hist, i);
    
        printf("[%02d] %03d ; %03d\n", (int)i, (int)value, count);
    }

    /* export histogram */
    const char* path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\h.csv";

    int n = cv_histogram_save(hist, path);

    printf(": %d", n);

    return 0;

}
