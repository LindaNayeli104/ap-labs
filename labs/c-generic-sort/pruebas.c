#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void readFileStrings(){
    FILE *inputFile  = fopen("strings.txt", "r"); //cambiar esto por generico
    if (inputFile == NULL){   
        printf("Error! Could not open file\n"); 
        exit(-1);//Checar esto
    }

    char linea[100];
    void *stringsPointer[100];

    int i=0;
    while(!feof(inputFile)){
        fgets(linea, 100, inputFile);    // que es este numero
        if((strcmp(linea, "\n"))){
            stringsPointer[i] = malloc(100);//32
            stringsPointer[i] = linea;
            printf("%s", (char*)stringsPointer[i]);   //Checar
            i++;
        }
    }

    //int lengthArray = sizeof(strings)/sizeof(strings[0]);
    //printf(" size= %d\n", lengthArray);
    /*
    for(int i=0; i<lengthArray; i++){
           //printf(" %d= %s\n", i, strings[i]);
    }   
    */
}

int main(int argc, char **argv){
    readFileStrings();
}