//
//  asmFunctions.c
//  Simulatron
//
//  Created by Daniel Sandoval on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#include "asmFunctions.h"

int soma(unsigned long* programCounter, short int* codeMemory, short int* dataMemory) {
    accumulator += dataMemory[codeMemory[*programCounter+1]];
    *programCounter += 2;
    return 1;
}

int stop(unsigned long* programCounter, short int* codeMemory, short int* dataMemory) {
    return 0;
}