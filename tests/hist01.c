

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include "cutievanilla.h"
#include "cutievanilla/matrix.h"
#include "cutievanilla/histogram.h"

int main(int argc, char *argv[]){


    CVHistogram* hist = cv_histogram_create(256, CV_FLOAT32);

    float start = 0, step = 0.25;

    cv_histogram_init_values(hist, &start, &step);

    for( size_t i = 0; i < hist->bins; i++){

        float value;

        cv_histogram_get_value(hist, i, &value);

        printf("[%d] : %.2f\n", (int)i, value);

    }

}
