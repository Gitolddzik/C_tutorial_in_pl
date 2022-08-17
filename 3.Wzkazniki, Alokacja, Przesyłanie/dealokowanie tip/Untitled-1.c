#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

void coss(int** arr) //"mowimy" funkcji co dostała aa dostała pointer na pointer
{
printf("%d \n", &arr); //bez sensu
printf("%d \n", arr);  //wartosc pointera na pointer (podwojnego wsakznika)
printf("%d \n", *arr); //dereferencja 1 -> daje nam pointer
printf("%d \n", **arr); //derferencja 2 -> daje nam wartosc 0 elementu
printf("%d \n", **arr+1); //1 element
printf("%d \n", **arr+2); //2 element

free(arr);
}

int main(int argc, char** argv) 
{
int* arr = calloc(3, sizeof(int)); //arr to wskaznik na zaalokowanmy obszar na hepaie

arr[0]=1;
arr[1]=2;
arr[2]=3;


printf("%d \n", &arr);
printf("%d \n", arr);
printf("%d \n\n\n", *arr);

coss(&arr); //przkazujemy adres wsakznika czyli pointer na pointer

_CrtDumpMemoryLeaks();
	return 0;
}