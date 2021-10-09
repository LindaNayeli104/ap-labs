#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void readFile(){
    char ch;
    int nums[100];
    
    FILE *inputFile;
    inputFile = fopen("numbers.txt", "r");

   
    if (inputFile == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    int i=0;
    while((ch = fgetc(inputFile)) != EOF){
        printf("%c", ch);
        nums[i] = (int)ch- 48;
        //printf(" %d\n", nums[i]);
        i++;
    }
    printf(" i =    %d\n", i);
        

    fclose(inputFile);
    
    int lengthArray = sizeof(nums)/sizeof(nums[0]);

    for(int i=0; i<lengthArray; i++){
           //printf(" %d= %d\n", i, nums[i]);
    }
}


    int main(int argc, char **argv){
        readFile();
    }