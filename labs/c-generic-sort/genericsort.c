#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

void mergesort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

void printInstructions(){
    printf("Ingrese todos los elementos en el orden correcto.\n");
    printf("Ejemplo: genericsort -n numbers.txt -quicksort -o qs_sorted_numbers.txt\n\n");
    printf("Si deseas evaluar strings en lugar de enteros, ingresa 'strings.txt' en lugar de '-n numbers.txt' \n");
    printf("Si deseas utilizar mergesort, ingresa '-mergesort' en lugar de '-quicksort'\n");
    printf("Ingresa el nombre del archivo que contendra el resultado en lugar de 'qs_sorted_numbers.txt', este debe tener el prefijo 'sorted_'\n");
}

int main(int argc, char **argv){
    //printf("numero de args:  %d\n", areNums);
	


    if(argc < 5){
        printInstructions();
        return 0;
    }

    if(argc == 5){

      

         char *inputFile = argv[1];
         char *sortingAlg = argv[2];
         char *outputFile = argv[4];

        if(strcmp(inputFile, "numbers.txt") == 0){
            printf("Ingrese '-n' antes de 'numbers.txt'. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(inputFile, "strings.txt")){
            printf("Ingrese 'strings.txt' o 'numbers.txt' dependiendo de qué desee evaluar. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        
        if(strcmp(sortingAlg, "-mergesort") && strcmp(sortingAlg, "-quicksort")){
            printf("Ingrese '-mergesort' o '-quicksort' dependiendo de qué algoritmo desee usar. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(argv[3], "-o")){
            printf("Ingrese '-o' antes del nombre del archivo donde guardará la respuesta. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        /*Checar esto*/
       /*  if(outputFile != "-mergesort" && sortingAlg != "-quicksort"){
              printInstructions();
              return 0;
        } */
         
    }else if(argc == 6){
        char *inputFile = argv[2];
        char *sortingAlg = argv[3];
        char *outputFile = argv[5];
             
        /* if (strcmp(inputFile, "numbers.txt") == 1){
            printf("res: no equal\n");
            printf("%s\n",argv[2] );
            printf("numbers.txt\n" );
        }else{
            printf("res: equal\n");
            printf("%s\n",argv[2] );
            printf("numbers.txt\n" );
        } */

        if(strcmp(argv[1], "-n")){
            printf("Ingrese -n si desea evaluar enteros. Observe el ejemplo.\n\n");
            printf("O verifique si ingresó elementos extras. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(inputFile, "strings.txt") == 0){
            printf("No ingrese '-n' antes de 'strings.txt', '-n' no es necesario para evaluar strings. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(inputFile, "numbers.txt")){
            printf("Ingrese 'strings.txt' o 'numbers.txt' dependiendo de qué desee evaluar. Observe el ejemplo..\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(sortingAlg, "-mergesort") && strcmp(sortingAlg, "-quicksort")){
            printf("Ingrese '-mergesort' o '-quicksort' dependiendo de qué algoritmo desee usar. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(argv[4], "-o")){
            printf("Ingrese '-o' antes del nombre del archivo donde guardará la respuesta. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
    }else{
        printf("Tiene argumentos extras\n");
        printInstructions();
        return 0;
    }
    

    return 0;
}
