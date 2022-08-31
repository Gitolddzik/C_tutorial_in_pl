#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // int arr[3][3]
    // {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9},
    // }

    int i;
    int** arr = malloc(sizeof(int*) * 3); //alokujemy 3 pointery (p1,p2,p3)
/*
[     p1      ,     p2      ,     p3      ]
-------------------------------------------
|p1 = adres 1 |p2 = adres 2 |p3 = adres 3 |
|    1,2,3    |    4,5,6    |    7,8,9    |  
-------------------------------------------
*/
    for (i = 0; i < 3; i++)
    {
        *(arr+i) = malloc(sizeof(int) * 3);
    }
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;
    arr[2][0] = 7;
    arr[2][1] = 8;
    arr[2][2] = 9;
    
    printf("%llu\n",sizeof(arr)); //wielkosc pointera wsakzujacego na poczatek tablicy 3 pointerow.
    printf("%llu\n",sizeof(arr[0])*3); //wielkosc 3 pointerow
    printf("%llu\n",sizeof(int) * 3 * 3); //wielkosc 9 intow

    printf("Size is %llu\n", sizeof(arr) + sizeof(arr[0]) * 3 + sizeof(int) * 3 * 3);
    //wielkosc tablivy


    // Deallocation
    for (i = 0; i < 3; i++) {
        free(*(arr+i)); //dealokujemy najpierw 3 tablice wewnatrz macierzy
        arr[i] = NULL;
    }
    free(arr); //dealokujemy tablice pointerow;
    arr = NULL;

    return 0;
}