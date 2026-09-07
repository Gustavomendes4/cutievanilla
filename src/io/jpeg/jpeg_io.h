#ifndef JPEG_IO_H_INCLUDED
#define JPEG_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _CVImage CVImage;

CVImage* cv_jpeg_load( const char* filename);

int cv_jpeg_save(CVImage* image, const char* filename);

bool cv_is_valid_jpeg_file(const char* filename);

#endif // JPEG_IO_H_INCLUDED