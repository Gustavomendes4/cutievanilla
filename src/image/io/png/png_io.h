#ifndef PNG_IO_H_INCLUDED
#define PNG_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _CVImage CVImage;

CVImage* cv_png_load( const char* filename);

int cv_png_save(CVImage* image, const char* filename);

bool cv_is_valid_png_file(const char* filename);

#endif // PNG_IO_H_INCLUDED