#include <stdlib.h>

#include "filecore.h"

#include "cutievanilla.h"

#include "image_io.h"

CVImage* cv_image_load( const char* filename){

    /* Previous conditions */
    if( !fc_isValidPath(filename) ) return NULL;

    if( !fc_existsFile(filename) ) return NULL;

    return cv_image_io_load(filename);
}

int cv_image_save(CVImage* image, const char* filename){

    /* Previous conditions */
    if( !fc_isValidPath(filename) ) return -1;

    if( !image ) return -2;

    return cv_image_io_save(image, filename);
}

void cv_image_free( CVImage* image){

    if( !image ) return;

    cv_matrix_free(image->matrix);

    free(image);

}
