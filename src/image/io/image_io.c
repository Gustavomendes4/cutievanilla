
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "filecore.h"

#include "image_io.h"

struct Format{

    const char* extension;

    CVImageFileFormat format;

    bool (*validator)(const char*);

    CVImage* (*loader)(const char*);
    
    int (*saver)(CVImage*, const char*);

};

static const struct Format FormatList[] = {
    {"bmp",  CV_IMAGE_FORMAT_BMP,    cv_is_valid_bmp_file,   cv_bmp_load, cv_bmp_save},
    {"png",  CV_IMAGE_FORMAT_PNG,    cv_is_valid_png_file,   cv_png_load, cv_png_save},
    {"jpg",  CV_IMAGE_FORMAT_JPG,    cv_is_valid_jpg_file,   cv_jpg_load, cv_jpg_save},
    {"jpeg", CV_IMAGE_FORMAT_JPEG,   cv_is_valid_jpeg_file,  cv_jpeg_load, cv_jpeg_save},
    {"tiff", CV_IMAGE_FORMAT_TIFF,   cv_is_valid_tiff_file,  cv_tiff_load, cv_tiff_save},

    {"", CV_INVALID_IMAGE_FORMAT,   NULL,  NULL, NULL}
};

bool cv_image_io_validate_format(const char* filename, CVImageFileFormat format){

    for(int i = 0; FormatList[i].format != CV_INVALID_IMAGE_FORMAT; i++){

        if( FormatList[i].format == format ){

            if( FormatList[i].validator )
                return FormatList[i].validator(filename);
        }
    }

    return false;
}

CVImageFileFormat cv_image_io_detect_format(const char* filename){

    const char* ext = fc_getExtension(filename) + 1;

    for( int i = 0; FormatList[i].format != CV_INVALID_IMAGE_FORMAT; i++ ){

        const char* curr_ext = FormatList[i].extension;

        if( strcmp(curr_ext, ext) == 0 ){
            return FormatList[i].format;
        }
    }

    return CV_INVALID_IMAGE_FORMAT;
}

CVImage* cv_image_io_load(const char* filename){

    CVImageFileFormat format = cv_image_io_detect_format(filename);
    
    if( format == CV_INVALID_IMAGE_FORMAT )
        return NULL;
    

    for( int i = 0; FormatList[i].format != CV_INVALID_IMAGE_FORMAT; i++ ){

        if( FormatList[i].format == format ){

            if( !cv_image_io_validate_format(filename, format) )
                return NULL;

            if( FormatList[i].loader )
                return FormatList[i].loader(filename);

        }
    }

    return NULL;
}

int cv_image_io_save(CVImage* image, const char* filename){

    /* Detect image format */
    CVImageFileFormat format = cv_image_io_detect_format(filename);

    if( format == CV_INVALID_IMAGE_FORMAT )
        return -3;


    for( size_t i = 0; FormatList[i].format != CV_INVALID_IMAGE_FORMAT; i++ ){

        if( FormatList[i].format == format ){

            if( FormatList[i].saver )
                return FormatList[i].saver(image, filename);

        }
    }

    return -1;
}
