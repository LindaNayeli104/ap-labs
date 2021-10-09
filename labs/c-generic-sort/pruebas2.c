#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void readFile(){
    FILE *inputFile  = fopen("strings.txt", "r"); //cambiar esto por generico
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
    readFile();
}