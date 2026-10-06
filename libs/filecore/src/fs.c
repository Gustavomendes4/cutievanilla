/*
    Centraliza as chamadas de sistema de filesystem
*/

#include <stdint.h> // util to use size_t
#include <stdbool.h> // util to use bool

#include "filecore.h"

/*  File Operation  */
bool fc_existsFile(const char* path){
    return true;
}

bool fc_copyFile(const char* source, const char* destination){
return true;
}

bool fc_deleteFile(const char* path){
return true;
}

bool fc_moveFile(const char* filepath, const char* newpath){
return true;
}

bool fc_renameFile(const char* filename, const char* newname){
return true;
}

size_t fc_getFileSize(const char* path){
return 1;
}

bool fc_touch(const char* path){
return true;
}

bool fc_existsDirectory(const char* path){
return true;
}

bool fc_createDirectory(const char* path){
return true;
}

bool fc_deleteDirectory(const char* path){
return true;
}


bool fc_isDirectoryEmpty(const char* path){
return true;
}

bool fc_moveDirectory(const char* source, const char* destination){
return true;
}

bool fc_renameDirectory(const char* source, const char* destination){
return true;
}

size_t fc_getDirectorySize(const char* source){
return true;
}

int fc_getFullPath(char* fullpath, const char* basepath){
return true;
}