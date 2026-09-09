#ifndef BMP_IO_H_INCLUDED
#define BMP_IO_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

/* forward declaration */
typedef struct _CVImage CVImage;

#pragma pack(push, 1)

typedef struct _BitmapFileHeader{
    uint16_t bfType;      // Deve ser "BM" = 0x4D42
    uint32_t bfSize;      // Tamanho do arquivo em bytes
    uint16_t bfReserved1; // Reservado
    uint16_t bfReserved2; // Reservado
    uint32_t bfOffBits;   // Offset até o início dos dados de imagem
}BitmapFileHeader;

typedef struct _BitmapInfoHeader{
    uint32_t biSize;          // Tamanho deste cabeçalho (40 bytes)
    int32_t  biWidth;         // Largura em pixels
    int32_t  biHeight;        // Altura em pixels
    uint16_t biPlanes;        // Sempre 1
    uint16_t biBitCount;      // Bits por pixel (24 = RGB)
    uint32_t biCompression;   // Tipo de compressão (0 = sem compressão)
    uint32_t biSizeImage;     // Tamanho da imagem em bytes
    int32_t  biXPelsPerMeter; // Resolução horizontal
    int32_t  biYPelsPerMeter; // Resolução vertical
    uint32_t biClrUsed;       // Nº de cores usadas
    uint32_t biClrImportant;  // Nº de cores importantes
}BitmapInfoHeader;

#pragma pack(pop)

/* assert to certify headers size */
_Static_assert(sizeof(BitmapFileHeader) == 14, "Invalid BitmapFileHeader size");
_Static_assert(sizeof(BitmapInfoHeader) == 40, "Invalid BitmapInfoHeader size");

typedef struct _Bitmap{

    BitmapFileHeader fileHeader;

    BitmapInfoHeader infoHeader;

}Bitmap;


CVImage* cv_bmp_load( const char* filename);

int cv_bmp_save(CVImage* image, const char* filename);

bool cv_is_valid_bmp_file(const char* filename);

#endif // BMP_IO_H_INCLUDED