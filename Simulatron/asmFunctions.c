//
//  asmFunctions.c
//  Simulatron
//
//  Created by Daniel Sandoval and Pedro Salum on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#include "asmFunctions.h"
#include <stdio.h>

int add(unsigned long* programCounter, short int* memory) {
    accumulator += memory[memory[*programCounter+1]];
    *programCounter += 2;
    return 1;
}

int sub(unsigned long* programCounter, short int* memory) {
    accumulator -= memory[memory[*programCounter+1]];
    *programCounter += 2;
    return 1;
}

int mult(unsigned long* programCounter, short int* memory) {
    accumulator *= memory[memory[*programCounter+1]];
    *programCounter += 2;
    return 1;
}

int div(unsigned long* programCounter, short int* memory) {
    if (memory[memory[*programCounter+1]] != 0){
        accumulator /= memory[memory[*programCounter+1]];
        *programCounter += 2;
        return 1;
    }
    else{
        printf("\n DIVISAO POR 0. FALHA DE SEGMENTACAO!\n");
        return 0;
    }
    
}

int jmp(unsigned long* programCounter, short int* memory) {
    *programCounter = memory[*programCounter+1];
    return 1;
}

int jmpn(unsigned long* programCounter, short int* memory) {
    if (accumulator < 0)
        *programCounter = memory[*programCounter+1];
    else
        *programCounter += 2;
    return 1;
}

int jmpp(unsigned long* programCounter, short int* memory) {
    if (accumulator > 0)
        *programCounter = memory[*programCounter+1];
    else
        *programCounter += 2;
    return 1;
}

int jmpz(unsigned long* programCounter, short int* memory) {
    if (accumulator == 0)
        *programCounter = memory[*programCounter+1];
    else
        *programCounter += 2;
    return 1;
}

int copy(unsigned long* programCounter, short int* memory) {
    memory[memory[*programCounter+2]] = memory[memory[*programCounter+1]];
    *programCounter += 3;
    return 1;
}

int load(unsigned long* programCounter, short int* memory) {
    accumulator = memory[memory[*programCounter+1]];
    *programCounter += 2;
    return 1;
}

int store(unsigned long* programCounter, short int* memory) {
    memory[memory[*programCounter+1]] = accumulator;
    *programCounter += 2;
    return 1;
}

int input(unsigned long* programCounter, short int* memory) {
    printf(">> ");
    scanf("%hd",&memory[memory[*programCounter+1]]);
    *programCounter += 2;
    return 1;
}

int output(unsigned long* programCounter, short int* memory) {
    printf("-> %hd\n",memory[memory[*programCounter+1]]);
    *programCounter += 2;
    return 1;
}

int stop(unsigned long* programCounter, short int* memory) {
    return 0;
}

void bindingAsmFuncions(){
    
    // Remind that the opcode declared on the documentation is the vector number +1
    
    asmFunctions[0] = add;
    asmFunctions[1] = sub;
    asmFunctions[2] = mult;
    asmFunctions[3] = div;
    asmFunctions[4] = jmp;
    asmFunctions[5] = jmpn;
    asmFunctions[6] = jmpp;
    asmFunctions[7] = jmpz;
    asmFunctions[8] = copy;
    asmFunctions[9] = load;
    asmFunctions[10] = store;
    asmFunctions[11] = input;
    asmFunctions[12] = output;
    asmFunctions[13] = stop;
    
    
    
}