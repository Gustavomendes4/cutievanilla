#ifndef CUTIEVANILLA_HISTOGRAM_IO_H_INCLUDED
#define CUTIEVANILLA_HISTOGRAM_IO_H_INCLUDED

typedef enum _CVImageFileFormat{
    CV_IMAGE_FORMAT_CSV,
    CV_IMAGE_FORMAT_TXT,
    CV_IMAGE_FORMAT_XLSX,

    CV_INVALID_HISTOGRAM_FORMAT
}CVHistogramFileFormat;

/* == Adiciona cabeçalhos para funções de I/O de imagens == */

#include "cutievanilla/histogram.h"

#include "csv/csv_io.h"

#include "txt/txt_io.h"

#include "xlsx/xlsx_io.h"

bool cv_histogram_io_validate_format(const char* filename, CVHistogramFileFormat format);

CVHistogramFileFormat cv_histogram_io_detect_format(const char* filename);

CVHistogram* cv_histogram_io_load(const char* filename);

int cv_histogram_io_save(CVHistogram* histogram, const char* filename);

#endif // CUTIEVANILLA_HISTOGRAM_IO_H_INCLUDED