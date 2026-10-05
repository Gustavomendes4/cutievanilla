
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#include "cutievanilla.h"
#include "raylib.h"

#define WIDTH 800
#define HEIGHT 600


void* show_me(void* arg){

    CVImage* image = (CVImage*)arg;

    /* Validate image */
    if(image == NULL){
        printf("invalid img\n");
        return NULL;
    }

    /* get dimensions */
    int img_w = cv_image_width(image);
    int img_h = cv_image_height(image);

    /* */

    InitWindow(800, 600, "Image");

    int monitor = GetCurrentMonitor();
    int max_w = GetMonitorWidth(monitor) - 100;  // Margem de segurança
    int max_h = GetMonitorHeight(monitor) - 100;

    // 2. Ajusta o tamanho da janela para não ultrapassar a tela
    int win_w = (img_w > max_w) ? max_w : img_w;
    int win_h = (img_h > max_h) ? max_h : img_h;

    SetWindowSize(win_w, win_h);
    SetWindowPosition((GetMonitorWidth(monitor) - win_w) / 2, (GetMonitorHeight(monitor) - win_h) / 2);

    /* */
    
    SetTargetFPS(60);

    // 1. Cria uma imagem vazia na RAM
    Image canvas = GenImageColor(win_w, win_h, BLACK);


    // 2. Fill texture by image matrix
    for(size_t y = 0; y < win_h; y++){

        for(size_t x = 0; x < win_w; x++){

            const uint8_t* r = cv_image_get_channel(image, x, y, 0);
            const uint8_t* g = cv_image_get_channel(image, x, y, 1);
            const uint8_t* b = cv_image_get_channel(image, x, y, 2);

            if (r && g && b) {
                ImageDrawPixel(&canvas, x, y, (Color){ *r, *g, *b, 255 });
            }else{
                printf("erro ao acessar matriz\n");
                return NULL;
            }
  
        }

    }

    // 3. carrega textura na VRAM
    Texture2D texture = LoadTextureFromImage(canvas);


    // printf("\n\n(1)\n\n");

    while (!WindowShouldClose()) {

        // --- RENDERIZAÇÃO (GPU) ---
        BeginDrawing();
            ClearBackground(BLACK);

            // Desenha a textura atualizada
            DrawTexture(texture, 0, 0, WHITE);

        EndDrawing();
    }

    // Libera a memória
    UnloadTexture(texture);
    UnloadImage(canvas);
    CloseWindow();

    return NULL;

}

bool create(CVImage* image, pthread_t* id){

    pthread_t tid;

    bool r = pthread_create(&tid, NULL, show_me, image) == 0;

    if( id )
        *id = tid;

    return r;
}

int main(void) {
    
    const char* path = "C:\\Users\\Gustavo\\Desktop\\cutievanillacpp\\images\\icon.bmp";

    CVImage* img = cv_image_load(path);

    if(img == NULL){
        printf("Error to load image: %d", path);
        return -1;
    }


    pthread_t id;
    if( !create(img, &id) ){
        printf("Erro ao criar thread\n");
        return -3;
    }

    printf("\n\nEsperando window\n\n");

    pthread_join(id, NULL);

    cv_image_free(img);
    return 0;
}