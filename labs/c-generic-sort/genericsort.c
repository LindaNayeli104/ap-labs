#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

void mergesort(void *lineptr[], int left, int right, int (*comp)(void *, void *)); */

//********************************************************************************************************************

void quicksort(void *v[], int left, int right, int (*comp)(void *, void *)){
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right){
        return;
    }
	    
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++){
	    if ((*comp)(v[i], v[left]) < 0){
	        swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quicksort(v, left, last-1, comp);
    quicksort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//********************************************************************************************************************

void printInstructions(){
    printf("Ingrese todos los elementos en el orden correcto.\n");
    printf("Ejemplo: genericsort -n numbers.txt -quicksort -o qs_sorted_numbers.txt\n\n");
    printf("Si deseas evaluar strings en lugar de enteros, ingresa 'strings.txt' en lugar de '-n numbers.txt' \n");
    printf("Si deseas utilizar mergesort, ingresa '-mergesort' en lugar de '-quicksort'\n");
    printf("Ingresa el nombre del archivo que contendra el resultado en lugar de 'qs_sorted_numbers.txt', este debe tener el prefijo 'sorted_'\n");
}

void readFileIntegers(){
    FILE *inputFile  = fopen("numbers.txt", "r"); //cambiar esto por generico
    if (inputFile == NULL){   
        printf("Error! Could not open file\n"); 
        exit(-1);//Checar esto
    }

    char linea[100];
    int nums[100];
    int i=0;

    while(!feof(inputFile)){
        fgets(linea, 100, inputFile);    // que es este numero
        if((strcmp(linea, "\n"))){
            int num = atoi(linea);
             nums[i] = num;
            i++;
        }
    }

    int lengthArray = sizeof(nums)/sizeof(nums[0]);
    printf(" size= %d\n", lengthArray);
    for(int i=0; i<lengthArray; i++){
           printf(" %d= %d\n", i, nums[i]);
    }
    
}

int main(int argc, char **argv){
	
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
         
        // Todo bien, ya se validó, ahora llamaremos a la función
        //void mergesort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
        readFile();

       

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
