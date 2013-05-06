//
//  asmFunctions.h
//  Simulatron
//
//  Created by Daniel Sandoval and Pedro Salum on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#ifndef Simulatron_asmFunctions_h
#define Simulatron_asmFunctions_h

// pointer vector array to list all 14 functions
int (*asmFunctions[14])(unsigned long* programCounter, short int* memory);

void bindingAsmFuncions();
extern short int accumulator;

#endif
