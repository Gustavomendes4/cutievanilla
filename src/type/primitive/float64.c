#include <stdint.h>
#include "float64.h"

bool f64_equals(const void* a, const void* b){
    (void)a;
    (void)b;
    return false;
}

int f64_comparer(const void* a, const void* b){
    (void)a;
    (void)b;
    return 0;
}

TypeError f64_adder(void* dest, const void* a, const void* b){
    (void)dest;
    (void)a;
    (void)b;
    return false;
}

TypeError f64_subtractor(void* dest, const void* a, const void* b){
    (void) dest;
    (void) a;
    (void) b;
    return false;
}

TypeError f64_multiplier(void* dest, const void* a, const void* b){
    (void) dest;
    (void) a;
    (void) b;
    return false;
}

TypeError f64_divider(void* dest, const void* a, const void* b){
    (void) dest;
    (void) a;
    (void) b;
    return false;
}

TypeError f64_min(void* value){
    (void) value;
    return false;
}

TypeError f64_max(void* value){
    (void) value;
    return false;
}

TypeError f64_to_string(char* string, const void* value){
    (void) string;
    (void) value;
    return false;
}

TypeError f64_from_string(void* value, const char* string){
    (void) string;
    (void) value;
    return false;
}

TypeError f64_can_convert(CVType type){
    (void) type;
    return TYPE_OK;
}

TypeError f64_convert(void* dest, CVType srcType, const void* src){

    double* buff = (double*)dest;

    switch( srcType ){

        case CV_UINT8:{
            uint8_t value = *((uint8_t*)src);
            *buff = (double)value;
        }break;

        case CV_INT8:{
            int8_t value = *((int8_t*)src);
            *buff = (double)value;
        }break;

        case CV_UINT16:{
            uint16_t value = *((uint16_t*)src);
            *buff = (double)value;
        }break;

        case CV_INT16:{
            int16_t value = *((int16_t*)src);
            *buff = (double)value;
        }break;

        case CV_UINT32:{
            uint32_t value = *((uint32_t*)src);
            *buff = (double)value;
        }break;

        case CV_INT32:{
            int32_t value = *((int32_t*)src);
            *buff = (double)value;
        }break;

        case CV_FLOAT32:{
            float value = *((float*)src);
            *buff = (double)value;
        }break;

        case CV_FLOAT64:{
            *buff = *((double*)src);
        }break;

        case CV_TYPE_COUNT: break;
        case CV_TYPE_UNKNOWED: break;
    }

    return TYPE_ERROR_INVALID_TYPE;
}
