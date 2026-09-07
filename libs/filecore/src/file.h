
/*      Compilation protection     */
#ifndef FILECORE_ALLOW_INTERNAL
    #error "Never include file.h directly, include only <filecore.h> "
#endif //FILECORE_ALLOW_INTERNAL


#ifndef FILECORE_FILE_H_INCLUDED
#define FILECORE_FILE_H_INCLUDED


/*****      DEPENDENCIES      *****/
#include <stdio.h>   //  User to FILE*
#include <stdbool.h> //  User to bool

#include "filecore.h"   //  User to FC_PATH_MAX_SIZE


#ifdef __cplusplus
extern "C" {
#endif

/*****      STRUCTURES      *****/

typedef enum _FC_OpenMode{

    FC_INVALID_MODE = 0,

    FC_READ,        // rb | Modo leitura, deve existir
    FC_WRITE,       // wb | Modo escrita, apaga existesnte
    FC_APPEND,      // ab | Modo append, cria se não existir 
    FC_READ_UPDATE,
    FC_WRITE_UPDATE,
    FC_APPEND_UPDATE,

    FC_OPENMODE_COUNT
}FC_OpenMode;

typedef struct _FC_File{

    FILE* f;

    char path[FC_PATH_MAX_SIZE];

    FC_OpenMode mode;

}FC_File;


/*****      FUNCTIONS      *****/

// Open and close functions
FC_Result   fc_open (FC_File* file, const char* path, FC_OpenMode mode);
FC_Result   fc_close(FC_File* file);

// Read and write functions
size_t      fc_read (FC_File* file, void* buffer, size_t maxBufferSize);
size_t      fc_write(FC_File* file, const void* buffer, size_t bufferSize);
FC_Result   fc_flush(FC_File* file);

// Cursor functtions
bool        fc_seek (FC_File* file, long offset, int whence);
size_t      fc_tell (FC_File* file);
FC_Result   fc_rewind(FC_File* file);

// Others
size_t      fc_size (FC_File* file);
bool        fc_eof  (FC_File* file);
FC_Result   fc_ferror(FC_File* file);


#ifdef __cplusplus
}
#endif

#endif // FILECORE_FILE_H_INCLUDED