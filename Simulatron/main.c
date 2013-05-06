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
// MEMSIZE defines the amout of mamory (code and data) our CPU have.
#define MEMSIZE 65535
// define DEBUGER to see all steps the simulator executes.
//#define DEBUGER
short int accumulator;

int main(int argc, const char * argv[])
{
    unsigned short int codigo = 0;
    unsigned long programCounter = 0;
    short int memory[MEMSIZE];
    accumulator = 0;
    /*
        // If to verify if any parameter was passed is gratter than 2
        // If gratter, we have 3 main options:
        //      1 - Manual Mode
        //          In manual mode, if passed 2 parameters, the seccond will be used to store the code sequence manually inserted
        //      2 - Help
        //      3 - Load file mode
    */
    
    if (argc < 2) {
        printf("\n\tEntre com a opção --help para obter ajuda\n\n");
        exit(1);
    }
    else{
         if((strcmp(argv[1],"-m") == 0) || (strcmp(argv[1],"-M") == 0) || (strcmp(argv[1],"--manual") == 0)){


            
            printf("Entre manualmente o código do programa (para finalizar entre com o código 65535):\n");
        
            register long i = 0;
            while (1) {
                scanf("%hud", &codigo);
                if (codigo == 65535)
                    break;
                memory[i] = codigo;
                i++;
            }
             if (argc == 3) {
                 FILE *fp;
                 fp = fopen(argv[2], "wb");
                 fwrite(memory, sizeof(short int), i, fp);
                 fclose(fp);
             }
        }
        else if((strcmp(argv[1],"-h") == 0) || ( strcmp(argv[1],"-H") == 0) || ( strcmp(argv[1], "--help") ==0 )){
            printf("\nManual de funcionamento do Simulatron:\n\n");
            printf("\t --help, -h, -H\t - Instruções\n\n");
            printf("\t --manual, -m, -M\t - Modo manual\n");
            printf("\t\t Modo de insersao de codigo manual\n\n");
            printf("\t\t - Entre cada short int por vez e aperte enter para inserir o proximo.\n\t\t   Para encerrar a insercao, digite o codigo 65535\n");
            printf("\t\t - Para salvar o código inserido manualmente, utilize a opcao manual e\n\t\t   adicionando como parâmetro o nome do arquivo em que sera salvo o codigo.\n\n");
            printf("\t [nome do .bin]\n");
            printf("\t\t Executa o arquivo .bin especificado\n\n");
            printf("\n\n -- Created by Daniel Sandoval and Pedro Salum --\n -- Copyright (c) 2013 LoopEC. All rights reserved. -- \n\n");
            exit(2);
            
        }else if (strlen(argv[1]) >= 3) {
            FILE *file;
            file = fopen(argv[1], "rb");
            if(file == NULL){
                printf("\nErro ao ler arquivo\n");
                fclose(file);
                exit(3);
            }
            fread(memory, sizeof(short int), MEMSIZE, file);
            fclose(file);
            
            printf("\nArquivo lido com sucesso\n");
            
    
        }
        
        // function to bind all pointer functions to the implemented CPU
        bindingAsmFuncions();
        
        // one line only simulator ;)
        while (asmFunctions[memory[programCounter]-1](&programCounter, memory)) {
            
#ifdef DEBUGER
            // debuger to see operation by operation
            printf("\nAcc: %hd\tPC: %ld\tMem: %hd", accumulator, programCounter, memory[programCounter]);
#endif
        
        }

#ifdef DEBUGER
        // prints the accumulator final result
        printf("\nResultado do acumulador: %hd\n", accumulator);
        
#endif
    
    return 0;
    }
}

