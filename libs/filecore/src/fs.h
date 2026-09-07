#ifndef FILECORE_FS_H_INCLUDED
#define FILECORE_FS_H_INCLUDED

/*
    Centraliza as chamadas de sistema de filesystem
*/

#include <stdint.h> // util to use size_t
#include <stdbool.h> // util to use bool


/*  File Operation  */
bool fc_existsFile(const char* path);

bool fc_copyFile(const char* source, const char* destination);

bool fc_deleteFile(const char* path);

bool fc_moveFile(const char* filepath, const char* newpath);

bool fc_renameFile(const char* filename, const char* newname);

size_t fc_getFileSize(const char* path);

bool fc_touch(const char* path); // Cria arquivo vazio se nao existir

// fc_getFileInfo


/*  Directory  Operation  */

bool fc_existsDirectory(const char* path);

bool fc_createDirectory(const char* path);

bool fc_deleteDirectory(const char* path);

bool fc_isDirectoryEmpty(const char* path);

bool fc_moveDirectory(const char* source, const char* destination); // arquivos e diretorios

bool fc_renameDirectory(const char* source, const char* destination);

size_t fc_getDirectorySize(const char* source);

int fc_getFullPath(char* fullpath, const char* basepath);

#endif
