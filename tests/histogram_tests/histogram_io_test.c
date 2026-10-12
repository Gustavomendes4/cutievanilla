

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include "cutievanilla.h"
#include "cutievanilla/matrix.h"
#include "cutievanilla/histogram.h"

int main(int argc, char *argv[]){

    // Dummy
    CVHistogram* hist = cv_histogram_create(256, CV_FLOAT32);

    // Paths
    const char* csv_path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\h.csv";
    const char* txt_path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\h.txt";
    const char* xlsx_path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\h.xlsx";

    // Test open calls
    CVHistogram* csv = cv_histogram_load(csv_path);
    CVHistogram* txt = cv_histogram_load(txt_path);
    CVHistogram* xlsx = cv_histogram_load(xlsx_path);

    // Test save calls
    cv_histogram_save(hist, csv_path);
    cv_histogram_save(hist, txt_path);
    cv_histogram_save(hist, xlsx_path);

    return 1;
}