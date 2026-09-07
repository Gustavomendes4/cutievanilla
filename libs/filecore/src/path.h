/*      Compilation protection     */
#ifndef FILECORE_ALLOW_INTERNAL
    #error "Never include file.h directly, include only <filecore.h> "
#endif //FILECORE_ALLOW_INTERNAL

#ifndef FILECORE_PATH_H_INCLUDED
#define FILECORE_PATH_H_INCLUDED

/*

    Funçções que analisam e constroem caminhos, sem alterar o
    sistema de arquivos.
    Não há chamadas de sistema!!  * Ha algumas

*/

#include <stddef.h>
#include <stdbool.h>

#ifndef FC_PATH_MAX_SIZE
    #define FC_PATH_MAX_SIZE 300

    #define FC_PATH_MAX_SIZE_NAME 255

#endif


#ifdef FILECORE_COMPILE_TO_WINDOWS
    #define FC_PATH_SEPARATOR '\\'
    #define FC_PATH_SEPARATOR_STR "\\"

    #define FC_IS_PATH_SEPARATOR(ch) ((ch) == '\\' || (ch) == '/')

#else
    #define FC_PATH_SEPARATOR '/'
    #define FC_PATH_SEPARATOR_STR "/"

    #define FC_IS_PATH_SEPARATOR(ch) ((ch) == '/')

#endif //FILECORE_COMPILE_TO_WINDOWS

#ifdef __cplusplus
extern "C" {
#endif


// ==========================================
// Checagens e Validações
// ==========================================

bool fc_isPathSeparator(char ch);

bool fc_isAbsolutePath(const char *path);

bool fc_isRelativePath(const char *path);

int fc_isValidPath(const char* path);

int fc_pathBelongsTo(const char* path, const char* root);


// ==========================================
// Inspeção Zero-Copy (Retorna ponteiro/sub-string)
// ==========================================

// Retorna o ponteiro para o início do nome do arquivo ("a/b/file.txt" -> "file.txt")
const char* fc_getName(const char* path);

// Retorna o ponteiro para a extensão ("file.txt" -> ".txt" ou NULL)
const char* fc_getExtension(const char *path);


// ==========================================
// Manipulação e Modificação de Buffers
// ==========================================

// Copia o diretório pai ("a/b/c" -> "a/b")
void fc_getParent(char *dst, size_t dst_size, const char *path);

// Normaliza barras e resolve '.' e '..' apenas textual ("a/b/../c" -> "a/c")
bool fc_normalizePath(char *dst, size_t dst_size, const char *path);

// Junta dois caminhos tratando separadores
void fc_joinPath(char* dst, size_t size, const char* path1, const char* path2);

// Altera a extensão do arquivo
void fc_changeExtension(char* dst, size_t dst_size, const char* path, const char* new_ext);

// Extrai apenas o nome sem extensão ("image.png" -> "image")
void fc_getStem(char* dst, size_t dst_size, const char* path);

void fc_changeStem(char* dst, size_t dst_size, const char* path, const char* new_stem);

// Calcula o caminho relativo de 'target' a partir de 'base'
bool fc_relative_to(char *dst, size_t dst_size, const char *base, const char *target);


/*/
    UTIL WRAPPERS
/*/

bool fc_hasExtension(const char *path, const char *ext);

void fc_removeExtension(char *path);

#ifdef __cplusplus
}
#endif

#endif