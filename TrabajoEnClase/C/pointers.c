#include <stdio.h>

void swap(int x, int y)
{
   int temp;
   temp = x;
   x = y;
   y = temp;
}

void swapWorking(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(){
    int x=1, y=2;

    printf("Before Swap: x = %i, y = %i\n", x, y);
    swap(x,y);
    printf("After Swap: x = %i, y = %i\n", x, y);

    swapWorking(&x,&y);
    printf("After Swap Working: x = %i, y = %i\n", x, y);
    return 0;
}