#ifndef TXT_IO_H_INCLUDED
#define TXT_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _CVHistogram CVHistogram;

CVHistogram* cv_txt_load( const char* filename);

int cv_txt_save(CVHistogram* image, const char* filename);

bool cv_is_valid_txt_file(const char* filename);

#endif // CSV_IO_H_INCLUDED