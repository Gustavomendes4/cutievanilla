/*
*
*
*
*
*
*
*/

#include "filecore.h"

#if defined(FILECORE_COMPILE_TO_WINDOWS)

    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>

#elif defined(FILECORE_COMPILE_TO_UNIX)

#else
    #error "Platform not defined to compile"
#endif // FILECORE_COMPILE_TO_WINDOWS



#include <errno.h>
#include <string.h>
#include <stdio.h>      // User FILE, fread, fopen, fwrite, fseek
#include <stdbool.h>    // To use bool




static const char* modeToStr(FC_OpenMode mode){

    switch(mode){
        case FC_READ:           return "rb";

        case FC_WRITE:          return "wb";

        case FC_APPEND:         return "ab";

        case FC_READ_UPDATE:    return "rb+";

        case FC_WRITE_UPDATE:   return "wb+";

        case FC_APPEND_UPDATE:  return "ab+";

        default: return NULL;
    }
}

static FC_Result errorByerrno(){
    switch (errno){

            case ENOENT: return FC_File_Not_Exists;	        // Arquivo ou diretório não existe
            case EACCES: return FC_Permission_Denied;	    // Permissão negada
            case EEXIST: return FC_File_Already_Exists;	    // Arquivo já existe
            case EINVAL: return FC_Invalid_Argument;	    // Argumento inválido
            case ENOMEM: return FC_Memory_Out;	            // Memória insuficiente
            case EMFILE: return FC_Much_Files_Open;	        // Muitos arquivos abertos
        
            default:     return FC_Unexpected_error;
        }
}

FC_Result fc_open(FC_File* file, const char* path, FC_OpenMode mode){

    *file = (FC_File){0};

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    if( !fc_isValidPath(path) ){       
        return FC_Invalid_Path;
    }

    const char* strmode = modeToStr(mode);

    if( strmode == NULL ){
        return FC_Invalid_OpenMode;
    }

    file->f = fopen(path, strmode);

    if( file->f == NULL){
        return errorByerrno();
    }

    /// Fil the struct and return success
    file->mode = mode;

    memcpy(file->path, path, strlen(path) + 1);

    return FC_Success;
}

FC_Result fc_close(FC_File* file){

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    if( file->f == NULL)
        return FC_Success;

    fclose(file->f);

    file->path[0] = '\0';
    // memset(file->path, 0, FC_PATH_MAX_SIZE);

    file->mode = FC_INVALID_MODE;

    return FC_Success;
}


// Read and write functions
size_t fc_read(FC_File* file, void* buffer, size_t maxBufferSize){

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    // Validar f

    // Validar openMode

    return fread(buffer, maxBufferSize, 1, file->f);
}

size_t fc_write(FC_File* file, const void* buffer, size_t bufferSize){
    
    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    // Validar f

    // Validar openMode

    return fwrite(buffer, bufferSize, 1, file->f);
}

FC_Result fc_flush(FC_File* file){

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    // Validar f
    
    // Validar openMode


    fflush(file->f);

    return FC_Invalid_Pointer;
}


// Cursor functtions
bool fc_seek(FC_File* file, long offset, int whence){

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    // Validar f

    // fseek();

    fseek(file->f, offset, whence);


    return false;
}

size_t fc_tell(FC_File* file){

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    return 1;
}

FC_Result fc_rewind(FC_File* file){

    if( file == NULL){
        return FC_Invalid_Pointer;
    }

    rewind(file->f);

    return FC_Success;
}

// Others
size_t fc_size(FC_File* file){

    (void)file;

    return 100;
}

bool fc_eof(FC_File* file){

    return feof(file->f) == -1;

}

FC_Result fc_ferror(FC_File* file){

    (void)file->f;

    return FC_File_Not_Exists;

}


