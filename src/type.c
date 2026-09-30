
#include <stdio.h>

#include "cutievanilla.h"
#include "cutievanilla/type.h"

#define CV_TYPE_STRING_SIZE 32

size_t cv_type_size(CVType type){

    switch(type){
        case CV_UINT8:
        case CV_INT8:
            return 1;

        case CV_UINT16:
        case CV_INT16:
            return 2;

        case CV_UINT32:
        case CV_INT32:
        case CV_FLOAT32:
            return 4;

        case CV_FLOAT64:
            return 8;

        default:
        case CV_TYPE_UNKNOWED:
            return 0;
    }
}

bool cv_type_to_string(char* buffer, const void* value, CVType type){

    if( buffer == NULL || value == NULL)
        return false;

    switch(type){

        case CV_UINT8:{
            uint8_t num = *(uint8_t*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%u", num) >= 0;
        }

        case CV_INT8:{
            int8_t num = *(int8_t*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%d", (int)num) >= 0;
        }

        case CV_UINT16:{
            uint16_t num = *(uint16_t*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%u", (unsigned)num) >= 0;
        }

        case CV_INT16:{
            int16_t num = *(int16_t*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%d", (int)num) >= 0;
        }

        case CV_UINT32:{
            uint32_t num = *(uint32_t*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%u", (unsigned)num) >= 0;
        }

        case CV_INT32:{
            int32_t num = *(int32_t*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%d", (int)num) >= 0;
        }

        case CV_FLOAT32:{
            float num = *(float*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%f", num) >= 0;
        }

        case CV_FLOAT64:{
            double num = *(double*)value;

            return snprintf(buffer, CV_TYPE_STRING_SIZE, "%f", num) >= 0;
        }
    }

    return false;
}

bool cv_type_is_equals(CVType type, const void* a, const void* b){

    switch(type){

        /* Intenger types */
        case CV_UINT8:
        case CV_INT8:
        case CV_UINT16:
        case CV_INT16:
        case CV_UINT32:
        case CV_INT32:
            return (memcmp(a, b, cv_type_size(type)) == 0);


        /* float types */
        case CV_FLOAT32:
        case CV_FLOAT64:
            //return ... not implemented
            return false;

        default:
            return false;
    }
}