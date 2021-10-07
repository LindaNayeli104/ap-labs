#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void readFile(){
    FILE *in_file  = fopen("numbers.txt", "r"); //cambiar esto por generico
    if (in_file == NULL){   
        printf("Error! Could not open file\n"); 
        exit(-1);
    }

    char linea[100];  // que es este numero
    int nums[100];
    int i=0;
    while(!feof(in_file)){
        fgets(linea, 100, in_file);    // que es este numero
        if(!(strcmp(linea, "\n"))){
             nums[i] = atoi(linea);
            i++;
        }
       
    }
    printf(" sizeeeeeeeeeeeeeeeeeeeeeeeee= %d\n", i);
    fclose(in_file);
    printf(" sizeeeeeeeeeeeeeeeeeeeeeeeee= %ld\n", sizeof(nums));
    printf(" pruebaaaaaaaaaaaaaaaaaaaaaa= %d\n", nums[101]);
    //for(int i=0; i<sizeof(nums); i++){            // porque me da 400
    for(int i=0; i<100; i++){
           //printf(" %d= %d\n", i, nums[i]);
    }
}

int main(int argc, char **argv){
    readFile();
}