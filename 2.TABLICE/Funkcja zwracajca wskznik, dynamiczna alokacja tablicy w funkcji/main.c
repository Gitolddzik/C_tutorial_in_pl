#include <stdio.h>
#include <stdlib.h>

int* nextcount(int x)
{
	int* wynik = malloc(x*sizeof(int));  //alokujemy pamiec
	
	for(int i=0;i<x;i++)
	{
		wynik[i] = x+i;  //tu mozemy dowolna operacje na tej macierzy tak naprawde wykonac
	}
	
	return wynik; //zwracamy tablice
}

int main(int argc, char** argv)
{
	
// dynamiczne tworzenie tablicy w funkcji.

	int x;
	
	scanf("%d",&x);  
	
	int* arr = nextcount(x);
	
		for(int i=0;i<x;i++)
	{
		printf("%d\n",arr[i]);  //dlaczego nie *arr[i]? Dlatego ze arr[i] jest tez wskaznikiem(!!!) na i- element tablicy [] te kwadratowe nawiasy (tak naprawdę to nie ale na początek łatwiej zrozumieć) znacza to samo co * :)
	}
	free(arr);
	return 0;
}