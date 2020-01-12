#include <stdio.h>
#include <stdlib.h>



int main(){

    int* array_test = (int*) malloc (sizeof(int)*5);


    for (int i= 0; i < 4; i++)
    {
        array_test[i] = i + 1;
 
    }

    printf("array_test test\n\n");


    // int* top = &array_test;

    printf("%d\n\n", *(array_test + 1));
    

    printf("%d\n\n", *array_test);



    printf("Printing array reversed\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", array_test[3 - i]);
    }

    return 0;






}