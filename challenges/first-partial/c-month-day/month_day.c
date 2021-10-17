#include <stdio.h>
#include <stdlib.h>


int isLeapYear(int year){
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    return leap;
}


void month_day(int year, int yearday, int *pmonth, int *pday){

    static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    *pday = yearday;
    *pmonth = 1;
    int current = 1;
    int leap = isLeapYear(year);

    while(*pday > daytab[leap][current]){
        *pday -= daytab[leap][current];
        *pmonth += 1;
        current++;
    }
}


 /* month_name:  return name of n-th month */
char *month_name(int n) {

   static char *name[] = {
       "Illegal month",
       "Jan", "Feb", "Mar",
       "Apr", "May", "Jun",
       "Jul", "Aug", "Sep",
       "Oct", "Nov", "Dec"
   };

   return (n < 1 || n > 12) ? name[0] : name[n];
}   


int main(int argc, char **argv) {

    if(argc < 3){
        printf("Por favor ingrese un año mayor a 0 y un día entre 1 y 365 (366 si es año bisiesto)\n");
        return 0;
    }

    int year = atoi(argv[1]);
    int yearday = atoi(argv[2]);

    int leapYear = isLeapYear(year);

    //Validate inputs
    if(year <= 0 ){
        printf("Por favor ingrese un año mayor a 0\n");
        return 0;
    } 

    if(yearday < 0 || (!leapYear && yearday > 365) || ((leapYear && yearday > 366))){
        printf("Por favor ingrese un día entre 1 y 365 (366 si es año bisiesto)\n");
        return 0;
    } 

    //Get day and month
    int pmonth;
    int pday;

    month_day(year, yearday, &pmonth, &pday);
    printf("%s %02d, %d\n", month_name(pmonth), pday, year);

    return 0;
}

//Existe año <= 0?