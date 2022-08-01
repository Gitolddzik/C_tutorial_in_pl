#include <stdio.h>
#include <string.h>


void wypiszbajty(void* arr, int n, int size) //void wypiszbajty(char* arr, int n, int size) to zadziala tak samo! ale daje wraninga
{
	
	printf("\n\n");
	
	
	for(int i=0;i<n*size;i+=size)
	{
	printf("%d ",&arr[i])	;
	}	
	
	printf("\n\n");                //To wszystko jest tylko do odczytu.
	
	
	for(int i=0;i<n*size;i+=size)
	{
	printf("%d ",((char*) arr)[i]);  //to po prostu KONWERSJA! konwersja arr[i] na wksaznik. 
	}
}

int main(int argc, char** argv) {
	int arr[] = {1,2,3,4,5,6};
	long long  arr2[] = {10,20,30,40,50,60,28,2, 256 }; // maksymalna przesylana wartosc to 256
	char arr3[] = "hej";
	
	
	
	wypiszbajty(arr,sizeof(arr)/sizeof(int),sizeof(int));
	wypiszbajty(arr2,sizeof(arr2)/sizeof(long long),sizeof(long long));
	wypiszbajty(arr3,sizeof(arr3)/sizeof(char),sizeof(char));
	
	
	return 0;
}