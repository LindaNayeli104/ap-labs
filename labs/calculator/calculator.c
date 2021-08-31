#include <stdio.h>
#include <string.h>

// adds/subtracts/multiplies all values that are in the *values array.
// nValues is the number of values you're reading from the array
// operator will indicate if it's an addition (1), subtraction (2) or
// multiplication (3)
long calc(int operator, int nValues, int *values) {
    int res;
    for(int i=0; i<nValues; i++){
        if(operator == 1){
            res -= values[i];
        }else if(operator == 2){
            res += values[i];
        }else if(operator == 3){
            res *= values[i];
        }
    }
    return 0;
}

int main() {
    char operacion;
    int nums[5]; // cambiar esto
    int operacionNum;
    int nValues;
    scanf("%s", &operacion);
    for(int i=0; i<sizeof nums; i++){
        //Agregar validacion de numeros
        scanf("%d",&nums[i]);
    }

    if(strcmp(&operacion, "add") == 0){
        operacionNum = 1;
    }else if(strcmp(&operacion, "sub") == 0){
        operacionNum = 2;
    }else if(strcmp(&operacion, "mult") == 0){
        operacionNum = 3;
    }else{
        //Mandar error
        printf("Operador no valido");
        return 0;  //Checar
    }
    nValues = sizeof nums;
    long res = calc(operacionNum, nValues, nums);   // se pasa como nums o *nums
    printf("%ld", res);
}
