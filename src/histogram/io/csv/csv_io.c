
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "cutievanilla/histogram.h"

#include "cutievanilla/type.h"

#include "csv_io.h"

CVHistogram* cv_csv_load( const char* filename){
    printf("carregado CSV!\n");

    return NULL;
}

int cv_csv_save(CVHistogram* histogram, const char* filename){
    
    if( histogram == NULL || filename == NULL)
        return -3;

    if( histogram->bins == 0)
        return -4;

    /* Alloc buffer to read values */
    void* value = malloc(histogram->element_size);
    
    if( value == NULL ){ return -6; }
    
    /* Open file */
    FILE* file = fopen(filename, "wb");

    if( file == NULL){ return -5; }


    /* Local variables */
    const CVType type = histogram->type;

    char value_str[32], line[70];

    size_t count;

    /* read values and write line */
    for( size_t i = 0; i < histogram->bins; i++){

        /* get value of bin[i] */
        if( !cv_histogram_get_value(histogram, i, value) ){
            free(value);
            fclose(file);
            return -10;
        }

        /* convert to string */
        if( !cv_type_to_string(value_str, value, type) ){
            free(value);
            fclose(file);
            return -11;
        }

        /* get count of bin */
        count = cv_histogram_get_count(histogram, i);

        /* create line string */
        int len = snprintf(line, 70, "%s ; %zu\n", value_str, count);

        if( len < 0 || (size_t)len >= sizeof(line)){
            free(value);
            fclose(file);
            return -12;
        }

        /* write line in file */
        if( fputs(line, file) == EOF){
            free(value);
            fclose(file);
            return -13;
        }

    }

    free(value);
    fclose(file);

    return 0;
}

bool cv_is_valid_csv_file(const char* filename){

    return true;
}
