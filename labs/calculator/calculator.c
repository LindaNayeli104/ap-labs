#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// adds/subtracts/multiplies all values that are in the *values array.
// nValues is the number of values you're reading from the array
// operator will indicate if it's an addition (1), subtraction (2) or
// multiplication (3)
long calc(int operator, int nValues, int *values) {
    int res = values[0];

    for(int i=1; i<nValues; i++){
        if(operator == 1){
            res += values[i];
        }else if(operator == 2){
            res -= values[i];
        }else if(operator == 3){
            res *= values[i];
        }
    }
    return res;
}

int isInteger(double num)
{
    int truncated = (int)num;
    return (num == truncated);
}


int main(int argc, char **argv){

    if(argc <= 2){
        printf("Ingresa add, sub o mult y los enteros necesarios para la operacon\n");
        return 0;
    }
    char *operacion = argv[1];
    int operacionNum;
    int nValues = argc-2;
    int nums[nValues];
    char cadena[25];

    for(int i=0; i<nValues; i++){
        int numInt = atoi(argv[i+2]);
        sprintf(cadena, "%d", numInt);

        if(strcmp(argv[i+2], "0") && atoi(argv[i+2]) == 0 || strcmp(argv[i+2],cadena) != 0){
            printf("Por favor ingresa solo numeros enteros\n");
            return 0;
        }
        nums[i] = atoi(argv[i+2]);
    }
  
    if(strcmp(operacion, "add") == 0){
        operacionNum = 1;
    }else if(strcmp(operacion, "sub") == 0){
        operacionNum = 2;
    }else if(strcmp(operacion, "mult") == 0){
        operacionNum = 3;
    }else{
        printf("Operador no valido\n");
        return 0;
    }

    long res = calc(operacionNum, nValues, nums);
    for(int i=0; i<nValues-1; i++){
        if(operacionNum == 1){
            printf("%d + ", nums[i]);
        }else if(operacionNum == 2){
            printf("%d - ", nums[i]);
        }else if(operacionNum == 3){
            printf("%d * ", nums[i]);
        }
    }
    printf("%d = %ld\n", nums[nValues-1], res);
    return 0;
}