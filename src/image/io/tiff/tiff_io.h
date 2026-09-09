#ifndef TIFF_IO_H_INCLUDED
#define TIFF_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _CVImage CVImage;

CVImage* cv_tiff_load( const char* filename);

int cv_tiff_save(CVImage* image, const char* filename);

bool cv_is_valid_tiff_file(const char* filename);

#endif // TIFF_IO_H_INCLUDED