#include <stdio.h>

int main(int argc, char** argv) {
	printf("Hello world!\n");
	
	
	int arr[] = {1,10,3,9,5,6};
	
	
	
	for(int* i = &arr[0]; i<&arr[5];i++)  //wskaznik na adres pamieci ZAWSZE Z GWAZDKA to jak taki typ zmiennych
	{
		printf("%d\n",i);		//DLACZEGO NIE i+=4? (int ma 4 bajty) bo przez i* wiemy ze mamy skakac po kolejnych ADRESACH W PAMIECI TABLICY a nie po prostu po kolejnuych adresach
	}
	
	
	for(int i = &arr[0]; i<&arr[5];i=i+sizeof(int))  
	{
		printf("%d\n",i);		
	}
	
	int* wsk = arr;
	
	printf("\n\n______________\n%p liczba pod tym adresem: %d", wsk, *(wsk));
	printf("\n%p liczba pod tym adresem: %d", wsk+1, *(wsk+1));
	printf("\n%p liczba pod tym adresem: %d", wsk+2, *(wsk+2));    //mozemy tak skakac po adresach pamieci
	
	int* wsk2 = arr + 1;  //wez adres arr i dodaj do niego 1*sizeof(typ arr)
	
	printf("\n\n______________\n%p liczba pod tym adresem: %d", wsk2, *(wsk2));
	printf("\n%p liczba pod tym adresem: %d", wsk2+1, *(wsk2+1));
	printf("\n%p liczba pod tym adresem: %d", wsk2+2, *(wsk2+2));    
	
	
	return 0;
}