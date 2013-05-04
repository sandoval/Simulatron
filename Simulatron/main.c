//
//  main.c
//  Simulatron
//
//  Created by Daniel Sandoval and Pedro Salum on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asmFunctions.h"
#define MEMSIZE 65535
#define DEBUGER

short int accumulator;

int main(int argc, const char * argv[])
{
    unsigned short int codigo = 0;
    unsigned long programCounter = 0;
    short int* memory = (short int*)malloc(MEMSIZE*sizeof(short int));
    accumulator = 0;
    
    if (argc < 2) {
        printf("Entre com a opção -H para obter ajuda");
        exit(1);
    }
    else{
        if (strlen(argv[1]) >= 3) {
            FILE *file;
            file = fopen(argv[1], "r");
            int i=0;
            while (fscanf(file, "%hd",&memory[i]) != EOF) {
                i++;
            }
#ifdef DEBUGER
            
            printf("\nArquivo lido com sucesso\n");
            
#endif
            
        }
        else if(strcmp(argv[1],"-m") || strcmp(argv[1],"-M")){
            printf("Entre manualmente o código do programa (para finalizar entre com o código 65535):\n");
        
            long i = 0;
            while (1) {
                scanf("%hud", &codigo);
                if (codigo == 65535)
                    break;
                memory[i] = codigo;
                i++;
            }
        }
        else if(strcmp(argv[1],"-h") || strcmp(argv[1],"-H")){
            printf("Manual de funcionamento do Simulatron:\n");
            
        }
    
        bindingAsmFuncions();
        
        while (asmFunctions[memory[programCounter]-1](&programCounter, memory));

#ifdef DEBUGER
        
        printf("Resultado do acumulador: %hd", accumulator);
        
#endif
    
    return 0;
    }
}

