//
//  asmFunctions.h
//  Simulatron
//
//  Created by Daniel Sandoval on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#ifndef Simulatron_asmFunctions_h
#define Simulatron_asmFunctions_h

int soma(unsigned long* programCounter, short int* codeMemory, short int* dataMemory);
int stop(unsigned long* programCounter, short int* codeMemory, short int* dataMemory);

int (*asmFunctions[14])(unsigned long* programCounter, short int* codeMemory, short int* dataMemory);

extern short int accumulator;

#endif
