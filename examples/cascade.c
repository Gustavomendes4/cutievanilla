
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cutievanilla.h"

#include "./detector/pico.h"
#include "./detector/cascade_face.h"

const char* PATH = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\raw\\Andre.bmp";

const char* OUT = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\examples\\out.bmp";


void draw(CVImage* image, CVRegion region){

    if(image == NULL || !cv_region_is_valid(region))
        return;


    long right  = cv_region_right(region);
    long left   = cv_region_left(region);
    long top    = cv_region_top(region);
    long bottom = cv_region_bottom(region);
    
    for(int i = left; i < right; i++){
        cv_image_set_channel(image, i+1, top, 0, U8_LIST(255));
        cv_image_set_channel(image, i+1, top, 1, U8_LIST(0));
        cv_image_set_channel(image, i+1, top, 2, U8_LIST(0));

        cv_image_set_channel(image, i+1, bottom, 0, U8_LIST(255));
        cv_image_set_channel(image, i+1, bottom, 1, U8_LIST(0));
        cv_image_set_channel(image, i+1, bottom, 2, U8_LIST(0));
    }

    for(int j = top; j < bottom; j++){

        cv_image_set_channel(image, right, j, 0, U8_LIST(255));
        cv_image_set_channel(image, right, j, 1, U8_LIST(0));
        cv_image_set_channel(image, right, j, 2, U8_LIST(0));

        cv_image_set_channel(image, left, j, 0, U8_LIST(255));
        cv_image_set_channel(image, left, j, 1, U8_LIST(0));
        cv_image_set_channel(image, left, j, 2, U8_LIST(0));

    }

}

CVImage* open_gray(const char* path){

    CVImage* img = cv_image_load(path);

    if(img == NULL)
        return NULL;


    CVImage* new = cv_image_create(
        cv_image_width(img),
        cv_image_height(img),
        1,
        CV_UINT8
    );

    if(new == NULL){
        cv_image_free(img);
        return NULL;
    }

    for( int x = 0; x < cv_image_width(img); x++)
    for( int y = 0; y < cv_image_height(img); y++){

        const uint8_t* r = cv_image_get_channel(img, x, y, 0);
        const uint8_t* g = cv_image_get_channel(img, x, y, 1);
        const uint8_t* b = cv_image_get_channel(img, x, y, 2);

        uint8_t gray_value = (uint8_t)(
            0.299f * (*r) +
            0.587f * (*g) +
            0.114f * (*b)
        );
        // uint8_t mean = ((int)*r + (int)*g + (int)*b) / 3;

        cv_image_set_pixel(new, x, y, &gray_value);

    }

    cv_image_free(img);

    return new;
}

int save_gray(CVImage* image, const char* path){

    if( image == NULL || path == NULL)
        return -1;


    CVImage* temp = cv_image_create(
        cv_image_width(image),
        cv_image_height(image),
        3,
        CV_UINT8
    );

    if(temp == NULL) return -2;


    for( int x = 0; x < cv_image_width(image); x++)
    for( int y = 0; y < cv_image_height(image); y++){

        const uint8_t* value = cv_image_get_channel(image, x, y, 0);

        cv_image_set_channel(temp, x, y, 0, value);
        cv_image_set_channel(temp, x, y, 1, value);
        cv_image_set_channel(temp, x, y, 2, value);
    }

    int rt = cv_image_save(temp, path);

    cv_image_free(temp);

    return rt == 0 ? 0 : -4;


    /*
    draw(img, CV_REGION(10, 10, 30, 20));
    
    printf("Salvando...\n");
    cv_image_save(img, OUT);
    
    return 0;
    */
}


int main(int argc, char** argv) {

    CVImage* gray = open_gray(PATH);
    CVImage* img = cv_image_load(PATH);

    if(gray == NULL || img == NULL){
        printf("Erro ao criar gray image\n");
        return -1;
    }

    float rcsq[4 * 1024];
    int max_detections = 1024;

    float min_size = 40.0f;
    float max_size = 1000.0f;
    float scale_factor = 1.1f;
    float stride = 0.1f;

    int num_detections = find_objects(
        rcsq, max_detections,
        (void*)cascade_face,
        0.0f,
        
        gray->matrix->data,
        
        cv_image_height(gray), cv_image_width(gray), cv_image_width(gray),

        scale_factor, stride, min_size, max_size
    );

    num_detections = cluster_detections(rcsq, num_detections);

    printf("\n========================================\n");
    printf("Arquivo: %s (%dx%d px)\n", PATH, cv_image_width(gray), cv_image_height(gray));
    printf("Faces encontradas: %d\n", num_detections);

    
    for (int i = 0; i < num_detections; ++i) {
        float score = rcsq[4 * i + 3];
        if (score > 12.0f) {
            float r = rcsq[4 * i + 0];
            float c = rcsq[4 * i + 1];
            float s = rcsq[4 * i + 2];

            int x_min = (int)(c - s / 2.0f);
            int y_min = (int)(r - s / 2.0f);
            int tam = (int)s;
            
            printf("  -> Face #%d: X=%d, Y=%d, Tam=%d px | Score=%.2f\n",
            i + 1, x_min, y_min, tam, score);

            draw(img, CV_REGION(x_min, y_min, tam, tam));
        }
    }

    // save_gray(gray, OUT);
    cv_image_save(img, OUT);

    cv_image_free(gray);
    cv_image_free(img);
    return 0;
}
