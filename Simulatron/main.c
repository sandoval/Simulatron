//
//  main.c
//  Simulatron
//
//  Created by Daniel Sandoval on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "asmFunctions.h"

short int accumulator;

int main(int argc, const char * argv[])
{
    unsigned short int codigo = 0;
    unsigned long programCounter = 0;
    short int* codeMemory = (short int*)malloc(2048*sizeof(short int));
    short int* dataMemory = (short int*)malloc(2048*sizeof(short int));
    accumulator = 0;
    
    printf("Entre manualmente o código do programa:\n");
    
    long i = 0;
    while (1) {
        scanf("%hud", &codigo);
        if (codigo == 65535)
            break;
        codeMemory[i] = codigo;
        i++;
    }
    
    printf("Entre manualmente os dados de memória:\n");
    
    i = 0;
    while (1) {
        scanf("%hud", &codigo);
        if (codigo == 65535)
            break;
        dataMemory[i] = codigo;
        i++;
    }
    
    asmFunctions[0] = soma;
    asmFunctions[13] = stop;
    
    while (asmFunctions[codeMemory[programCounter]-1](&programCounter, codeMemory, dataMemory));
    
    printf("Resultado do acumulador: %hd", accumulator);
    
    return 0;
}

