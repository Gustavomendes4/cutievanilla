#ifndef XLSX_IO_H_INCLUDED
#define XLSX_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _CVHistogram CVHistogram;

CVHistogram* cv_xlsx_load( const char* filename);

int cv_xlsx_save(CVHistogram* image, const char* filename);

bool cv_is_valid_xlsx_file(const char* filename);

#endif // XLSX_IO_H_INCLUDED