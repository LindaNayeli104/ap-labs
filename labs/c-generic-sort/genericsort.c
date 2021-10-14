#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

void mergesort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

//********************************************************************************************************************

int compare(const void *a, const void *b) {
    double n1 = atof(a);
    double n2 = atof(b);
    return (int) (n1 - n2);
}

//********************************************************************************************************************

//---------------------------------------------------------------------- printInstructions()

void printInstructions(){
    printf("Ingrese todos los elementos en el orden correcto.\n");
    printf("Ejemplo: genericsort -n numbers.txt -quicksort -o qs_sorted_numbers.txt\n\n");
    printf("Si deseas evaluar strings en lugar de enteros, ingresa 'strings.txt' en lugar de '-n numbers.txt' \n");
    printf("Si deseas utilizar mergesort, ingresa '-mergesort' en lugar de '-quicksort'\n");
    printf("Ingresa el nombre del archivo que contendra el resultado en lugar de 'qs_sorted_numbers.txt', este debe tener el prefijo 'sorted_'\n");
}





//---------------------------------------------------------------------- main()


int main(int argc, char **argv){
    int left = 0;
    int right = 100; //Checar esto
    if(argc < 5){
        printInstructions();
        return 0;
    }

    if(argc == 5){
         char *inputFileName = argv[1];
         char *sortingAlg = argv[2];
         char *outputFile = argv[4];

        if(strcmp(inputFileName, "numbers.txt") == 0){
            printf("Ingrese '-n' antes de 'numbers.txt'. Observe el ejempLlamartlo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(inputFileName, "strings.txt")){
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
         
        
        //printf("Entra principiooooooooo\n"); 

        // Todo bien, ya se validó, ahora llamaremos a la función

        //------------------------------------------------- Read file
        FILE *inputFile  = fopen(inputFileName, "r"); //cambiar esto por generico
        if (inputFile == NULL){   
            printf("Error! Could not open file\n"); 
            exit(-1);//Checar esto
        }

        char linea[100];
        void *dataPointer[100];

        int i=0;
        while(!feof(inputFile)){
            fgets(linea, 100, inputFile);
           
            if((strcmp(linea, "\n"))){
                dataPointer[i] = malloc(strlen(linea));
                strcpy(dataPointer[i], linea);
                i++;
               
            }
        }
        //-------------------------------------------------
        //Validacion esta mal checar-------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(strcmp(sortingAlg, "-mergesort") == 0){
            mergesort(dataPointer, left, right, (int (*)(void *, void *))strcmp);  
        }else if(strcmp(sortingAlg, "-quicksort") == 0){
            printf("Quicksort");
            quicksort(dataPointer, left, right, (int (*)(void *, void *))strcmp);  
        }

         /* for(int i=0; i<100; i++){
            printf("%s", (char*)dataPointer[i]);
        }  */
        FILE *salida = fopen(outputFile, "w+");
        for(int i = 0; i < 100 ; i++){
            fprintf(salida, "%s", (char *)dataPointer[i]);
        }


        fclose(salida);

    }else if(argc == 6){
        char *inputFileName = argv[2];
        char *sortingAlg = argv[3];
        char *outputFile = argv[5];
             
        /* if (strcmp(inputFileName, "numbers.txt") == 1){
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
        if(strcmp(inputFileName, "strings.txt") == 0){
            printf("No ingrese '-n' antes de 'strings.txt', '-n' no es necesario para evaluar strings. Observe el ejemplo.\n\n");
            printInstructions();
            return 0;
        }
        if(strcmp(inputFileName, "numbers.txt")){
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

        //printf("Entra principiooooooooo\n"); 
        
        // Todo bien, ya se validó, ahora llamaremos a la función
        //readFileIntegers(inputFileName);

        //------------------------------------------------- Read file
        FILE *inputFile  = fopen(inputFileName, "r"); //cambiar esto por generico
        if (inputFile == NULL){   
            printf("Error! Could not open file\n"); 
            exit(-1);//Checar esto
        }

        char linea[100];
        void *dataPointer[100];

        int i=0;
        while(!feof(inputFile)){
            fgets(linea, 100, inputFile);
            if((strcmp(linea, "\n"))){
                dataPointer[i] = malloc(strlen(linea));
                strcpy(dataPointer[i], linea);
                i++;
            }
        }
        //-------------------------------------------------
        if(strcmp(sortingAlg, "-mergesort")){
            mergesort(dataPointer, left, right, (int (*)(void *, void *))compare);  
        }else if(strcmp(sortingAlg, "-quicksort")){
            quicksort(dataPointer, left, right, (int (*)(void *, void *))compare);  
        }

        FILE *salida = fopen(outputFile, "w+");
        for(int i = 0; i < 100 ; i++){
            fprintf(salida, "%s", (char *)dataPointer[i]);
        }

        fclose(salida);
    }else{
        printf("Tiene argumentos extras\n");
        printInstructions();
        return 0;
    }


   
    return 0;
}
