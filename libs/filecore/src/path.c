
/*

*/

#include <string.h> // used for memmove, strlen, strcmp

#include "filecore.h"

/***************************************************
*
*   Macros
*
***************************************************/

#ifdef FILECORE_COMPILE_TO_WINDOWS

    #ifndef FC_PATH_SEPARATOR
        #define FC_PATH_SEPARATOR '\\'
    #endif

    #define FC_IS_PATH_SEPARATOR(ch) ((ch) == '\\' || (ch) == '/')

#else

    #ifndef FC_PATH_SEPARATOR
        #define FC_PATH_SEPARATOR '/'
    #endif

    #define FC_IS_PATH_SEPARATOR(ch) ((ch) == '/')

#endif //FILECORE_COMPILE_TO_WINDOWS


/***************************************************
*
*   STATIC FUNCTIONS
*
***************************************************/

#define FC_LAST_CHAR_PTR(str) ((str) && (str)[0] != '\0' ? ((str) + strlen(str) - 1) : NULL)

#define FC_VALID_PATH_LENGTH(size) ( (size) < FC_PATH_MAX_SIZE )


static char* STATIC_fc_getExtension(const char *path){

    if (path == NULL || *path == '\0') {
        return NULL;
    }

    const char* last = FC_LAST_CHAR_PTR(path);

    while( last > path){

        if( *last == '.' ) {
            return (char*)last;
        }

        if( FC_IS_PATH_SEPARATOR(*last) ) {
            return NULL;
        }

        last--;

    }

    return NULL;
}

static char* STATIC_fc_getName( char* path){

    if (path == NULL || *path == '\0') {
        return NULL;
    }

    char* lastSeparator = FC_LAST_CHAR_PTR(path);

    if (FC_IS_PATH_SEPARATOR(*lastSeparator)) {
        return NULL;
    }

    while (lastSeparator > path && !FC_IS_PATH_SEPARATOR(*lastSeparator)) {
        lastSeparator--;
    }

    if (FC_IS_PATH_SEPARATOR(*lastSeparator)) {
        lastSeparator++;
    }

    return lastSeparator;
}

static inline int new_path_size_ext(const char* path, const char* new_ext){

    const char* ext = fc_getExtension(path);

    int current_ext_length = ext ? strlen(ext) : 0;

    int dot = (new_ext[0] != '.' && new_ext[0] != '\0') ? 1 : 0;

    return (
        strlen(path)
        + strlen(new_ext)
        - current_ext_length
        + 1
        + dot
    );
}

static inline int new_path_size_stem(const char* path, const char* new_stem){

    const char *ext = fc_getExtension(path);
    
    const size_t ext_len = ext ? strlen(ext) : 0;

    const char *name = fc_getName(path);

    const size_t current_name_length = ( name ) ? strlen(name) : 0;

    const size_t new_stem_length = strlen(new_stem);

    return (
        strlen(path)
        + new_stem_length
        - current_name_length
        + 1
        + ext_len
    );
}

static inline bool fc_buffersOverlap(const void *a, size_t a_size, const void *b, size_t b_size){
    const uintptr_t a_begin = (uintptr_t)a;
    const uintptr_t a_end   = a_begin + a_size;

    const uintptr_t b_begin = (uintptr_t)b;
    const uintptr_t b_end   = b_begin + b_size;

    return (a_begin < b_end) && (b_begin < a_end);
}

static inline bool isAlpha(char ch){
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
// ==========================================
// Checagens e Validações
// ==========================================

bool fc_isPathSeparator(char ch){
    return FC_IS_PATH_SEPARATOR(ch);
}

bool fc_isAbsolutePath(const char *path){

    if (path == NULL || *path == '\0') {
        return false;
    }

#if defined(FC_COMPILE_TO_WINDOWS)
    // Check for drive letter (e.g., "C:\")
    if ( isAlpha(path[0]) && path[1] == ':' ) {
        return FC_IS_PATH_SEPARATOR(path[2]);
    }

    /* 2. Caminhos UNC e Device Paths (ex: "\\server\share" ou "//server/share") */
    if (FC_IS_PATH_SEPARATOR(path[0]) && FC_IS_PATH_SEPARATOR(path[1])) {
        return true;
    }

    return false;

#elif defined(FC_COMPILE_TO_UNIX)
    return FC_IS_PATH_SEPARATOR(path[0]);
#endif

}

int fc_isValidPath(const char* path){

}

int fc_pathBelongsTo(const char* path, const char* root){

}


// ==========================================
// Inspeção Zero-Copy (Retorna ponteiro/sub-string)
// ==========================================

const char* fc_getName( const char* path){

    if (path == NULL || *path == '\0') {
        return NULL;
    }

    const char* lastSeparator = FC_LAST_CHAR_PTR(path);

    if (FC_IS_PATH_SEPARATOR(*lastSeparator)) {
        return NULL;
    }

    while (lastSeparator > path && !FC_IS_PATH_SEPARATOR(*lastSeparator)) {
        lastSeparator--;
    }

    if (FC_IS_PATH_SEPARATOR(*lastSeparator)) {
        lastSeparator++;
    }

    return lastSeparator;
}

const char* fc_getExtension(const char *path){
    return STATIC_fc_getExtension(path);
}


// ==========================================
// Manipulação e Modificação de Buffers
// ==========================================

void fc_getParent(char *dst, size_t dst_size, const char *path){

    if (dst == NULL || dst_size == 0 || path == NULL || *path == '\0') {
        return;
    }

    /* Found last PATH_SEPARATOR */
    const char* last = FC_LAST_CHAR_PTR(path);
    
    // -1 to skip the last character if it's a separator
    
    if (FC_IS_PATH_SEPARATOR(*last) && last > path) {
        last--;
    }

    while (last > path && !FC_IS_PATH_SEPARATOR(*last)) {
        last--;
    }

    if (!FC_IS_PATH_SEPARATOR(*last)) {
        *dst = '\0';
        return;
    }


    /* Calculate the size of the parent path */
    size_t size = (size_t)(last - path) + 1;

    if (size + 1 > dst_size){
        return;
    }

    /* Copy the parent path */
    memmove(dst, path, size);
    
    dst[size] = '\0';

    return;
}

bool fc_normalizePath(char *dst, size_t dst_size, const char *path){

}

void fc_joinPath(char* dst, size_t size, const char* path1, const char* path2){

    if (dst == NULL || size == 0 || path1 == NULL || path2 == NULL) {
        return;
    }

    size_t len1 = strlen(path1);
    size_t len2 = strlen(path2);

    /* Validate PATH sizes*/
    if( !FC_VALID_PATH_LENGTH(len1) || !FC_VALID_PATH_LENGTH(len2) ) {
        return;
    }

    /* Validate size (Corner case ignored) */
    if( len1 + len2 + 2 > size ) {
        return;
    }

    /* Verify collision in path2 */
    char temp_buffer[FC_PATH_MAX_SIZE];
    const char *p2 = path2;

    if( fc_buffersOverlap(dst, size, path2, len2 + 1) ){
        memmove(temp_buffer, path2, len2 + 1);
        p2 = temp_buffer;
    }

    /* Copy first path */
    char* cursor = dst;

    memmove(cursor, path1, len1 + 1);

    cursor += len1;

    /* Append separator if needed */
    if( !FC_IS_PATH_SEPARATOR(*(cursor - 1)) ) {
        *(cursor++) = FC_PATH_SEPARATOR;
        *(cursor) = '\0';
    }

    /* Remove PATH_SEPARATOR if needed */
    if( FC_IS_PATH_SEPARATOR(*p2) ) {
        p2++;
        len2--;
    }

    /* Append second path */
    memmove(cursor, p2, len2 + 1);

    return;

}

void fc_changeExtension(char* dst, size_t dst_size, const char* path, const char* new_ext){

    if( dst == NULL || dst_size == 0 || path == NULL || new_ext == NULL ) {
        return;
    }

    // Valida size
    if( new_path_size_ext(path, new_ext) > dst_size ) {
        return;
    }

    // Valid same path and new extension Ethan
    if( strcmp(new_ext, fc_getExtension(path)) == 0 ) {
        return;
    }

    // Copia o caminho original para o destino
    memmove(dst, path, strlen(path) + 1);

    // Encontra local para colar a extenção
    char* ext = STATIC_fc_getExtension(dst);

    if( ext == NULL){
        // Se não houver extensão, adiciona a nova extensão no final
        ext = FC_LAST_CHAR_PTR(dst) + 1;
    }


    // Verifica se a nova extensão começa com '.' ou não, e adiciona '.' se necessário
    if( new_ext[0] != '.' && new_ext[0] != '\0' ) {
        *ext = '.';
        ext++;
    }
    
    
    // Copia a nova extensão
    memmove(ext, new_ext, strlen(new_ext) + 1);

    return;

}

void fc_getStem(char* dst, size_t dst_size, const char* path){

    if( dst == NULL || dst_size == 0) {
        return;
    }

    dst[0] = '\0';

    if( path == NULL || *path == '\0') {
        return;
    }

    /* Coleta name e valida*/
    const char* stem = fc_getName((char*)path);

    if( stem == NULL || *stem == '\0' ) {
        *dst = '\0';
        return;
    }

    /* Coleta extensão */
    const char* ext = fc_getExtension(path);

    if( ext == NULL ) {
        ext = FC_LAST_CHAR_PTR(path) + 1;
    }

    /* Coleta stem_size e valida*/
    size_t stem_len = (size_t)(ext - stem);

    if( stem_len > dst_size - 1 ) {
        return;
    }

    /* deep copy */
    memmove(dst, stem, stem_len);
    dst[stem_len] = '\0';
}

/* INCOMPLETO */
void fc_changeStem(char* dst, size_t dst_size, const char* path, const char* new_stem){

    /*
    
        PAREI AQUI, TUDO BUGGADO
    */
    if( dst == NULL || dst_size == 0 || path == NULL || new_stem == NULL ) {
        return;
    }

    // Valida size
    if( new_path_size_stem(path, new_stem) > dst_size ) {
        printf("** Tamanho insuficiente para o novo caminho **\n");
        return;
    }

    size_t stem_len = strlen(new_stem);

    char* cursor;

    const char* ext = fc_getExtension(path);

    /* Copy parent  */
    fc_getParent(dst, dst_size, path);

    if( *dst == '\0' ) {
        cursor = dst;
    } else {
        cursor = FC_LAST_CHAR_PTR(dst) + 1;
        *(cursor++) = FC_PATH_SEPARATOR;
    }

    /* Copy new stem*/
    memmove(cursor, new_stem, stem_len + 1);
    cursor += stem_len;

    /* Copy extension */
    if( ext != NULL ) {
        memmove(cursor, ext, strlen(ext) + 1);
    } else {
        *cursor = '\0';
    }

    return;

}

bool fc_relative_to(char *dst, size_t dst_size, const char *base, const char *target){

}


// ==========================================
//              WRARPPERS
// ==========================================

bool fc_hasExtension(const char *path, const char *ext){
    return fc_getExtension(path) != NULL && strcmp(fc_getExtension(path), ext) == 0;
}

void fc_removeExtension(char* path){
    return fc_changeExtension(path, sizeof(path), path, "");
}

bool fc_isRelativePath(const char *path){
    return !fc_isAbsolutePath(path);
}