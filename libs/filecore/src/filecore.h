#ifndef FILECORE_H_INCLUDED
#define FILECORE_H_INCLUDED

/*
#include <windows.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include <dirent.h>
#endif
*/



#ifdef _WIN32
    #define FILECORE_COMPILE_TO_WINDOWS
#else
    #define FILECORE_COMPILE_TO_UNIX
#endif //_WIN32


/*
    Return codes for functions in this library
*/
typedef enum _FC_Result{

    A, 
    
    FC_Invalid_Path,
    FC_Invalid_OpenMode,
    FC_Invalid_Pointer,
    FC_File_Not_Exists,
    FC_Success,
    FC_Permission_Denied,
    FC_File_Already_Exists,
    FC_Invalid_Argument,
    FC_Memory_Out,
    FC_Much_Files_Open,



    FC_Unexpected_error,
    
    C

}FC_Result;

#define FILECORE_ALLOW_INTERNAL

#include "path.h"

#include "file.h"
#include "dir.h"
#include "fs.h"

#undef FILECORE_ALLOW_INTERNAL

#endif 