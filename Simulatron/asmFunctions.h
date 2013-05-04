//
//  asmFunctions.h
//  Simulatron
//
//  Created by Daniel Sandoval on 04/05/2013.
//  Copyright (c) 2013 LoopEC. All rights reserved.
//

#ifndef Simulatron_asmFunctions_h
#define Simulatron_asmFunctions_h

int (*asmFunctions[14])(unsigned long* programCounter, short int* memory);
void bindingAsmFuncions();
extern short int accumulator;

#endif
