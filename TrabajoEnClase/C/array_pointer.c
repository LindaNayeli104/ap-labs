#include <stdio.h>

int main(){

    int a[5] = {12, 2, 3, 4, 63};
    int *pa = &a[0];
    printf("%i\n", *(pa + 3));

}
