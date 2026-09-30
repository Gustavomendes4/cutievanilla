
#include <stdio.h>
#include <stdlib.h>

#include "filecore.h"

#include "cutievanilla.h"

/*
    
    argv[1] = path da foto
    argv[2] = Nome completo
    argv[3] = cpf

    argv[4] = path de saida do arquivo

*/

int isValidName(){
    return 1;
}

int validateInput(int argc, char* argv[]){

    if( argc < 5){
        fprintf(stderr, "Not enough arguments. Use: *.exe {photo_path} {complete_name} {cpf} {output path}");
        return -1;
    }

    if( !fc_fileExists(argv[1]) ){
        
    }



}

int main(int argc, char* argv[]){

    if(argc < 5){

    }















}