#ifndef CSV_IO_H_INCLUDED
#define CSV_IO_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>



/* forward declaration */
typedef struct _CVHistogram CVHistogram;

CVHistogram* cv_csv_load( const char* filename);

int cv_csv_save(CVHistogram* histogram, const char* filename);

bool cv_is_valid_csv_file(const char* filename);

#endif // CSV_IO_H_INCLUDED 