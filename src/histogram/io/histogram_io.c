#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "filecore.h"

#include "histogram_io.h"

struct Format{

    const char* extension;

    CVHistogramFileFormat format;

    bool (*validator)(const char*);

    CVHistogram* (*loader)(const char*);
    
    int (*saver)(CVHistogram*, const char*);
};

static const struct Format FormatList[] = {
    {"csv",  CV_IMAGE_FORMAT_CSV,   cv_is_valid_csv_file,   cv_csv_load, cv_csv_save},
    {"txt",  CV_IMAGE_FORMAT_TXT,   cv_is_valid_txt_file,   cv_txt_load, cv_txt_save},
    {"xlsx",  CV_IMAGE_FORMAT_XLSX, cv_is_valid_xlsx_file,  cv_xlsx_load, cv_xlsx_save},

    {"", CV_INVALID_HISTOGRAM_FORMAT,   NULL,  NULL, NULL}
};

bool cv_histogram_io_validate_format(const char* filename, CVHistogramFileFormat format){

    for(int i = 0; FormatList[i].format != CV_INVALID_HISTOGRAM_FORMAT; i++){

        if( FormatList[i].format == format ){

            if( FormatList[i].validator )
                return FormatList[i].validator(filename);
        }
    }

    return false;
}

CVHistogramFileFormat cv_histogram_io_detect_format(const char* filename){

    const char* ext = fc_getExtension(filename) + 1;

    for( int i = 0; FormatList[i].format != CV_INVALID_HISTOGRAM_FORMAT; i++ ){

        const char* curr_ext = FormatList[i].extension;

        if( strcmp(curr_ext, ext) == 0 ){
            return FormatList[i].format;
        }
    }

    return CV_INVALID_HISTOGRAM_FORMAT;
}

CVHistogram* cv_histogram_io_load(const char* filename){

    CVHistogramFileFormat format = cv_histogram_io_detect_format(filename);
    
    if( format == CV_INVALID_HISTOGRAM_FORMAT )
        return NULL;
    

    for( int i = 0; FormatList[i].format != CV_INVALID_HISTOGRAM_FORMAT; i++ ){

        if( FormatList[i].format == format ){

            if( !cv_histogram_io_validate_format(filename, format) )
                return NULL;

            if( FormatList[i].loader )
                return FormatList[i].loader(filename);

        }
    }

    return NULL;
}

int cv_histogram_io_save(CVHistogram* histogram, const char* filename){

    /* Detect image format */
    CVHistogramFileFormat format = cv_histogram_io_detect_format(filename);

    if( format == CV_INVALID_HISTOGRAM_FORMAT )
        return -3;


    for( size_t i = 0; FormatList[i].format != CV_INVALID_HISTOGRAM_FORMAT; i++ ){

        if( FormatList[i].format == format ){

            if( FormatList[i].saver )
                return FormatList[i].saver(histogram, filename);

        }
    }

    return -1;
}
