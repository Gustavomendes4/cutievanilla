#ifndef JPG_IO_H_INCLUDED
#define JPG_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _CVImage CVImage;

CVImage* cv_jpg_load( const char* filename);

int cv_jpg_save(CVImage* image, const char* filename);

bool cv_is_valid_jpg_file(const char* filename);

#endif // JPG_IO_H_INCLUDED