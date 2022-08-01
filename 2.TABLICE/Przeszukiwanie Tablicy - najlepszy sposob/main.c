#include <stdio.h>
#include <stdlib.h>



int main(int argc, char** argv) {
	
	//NAJLEPSZY SPOSOB JESLI ARR NIE JEST PRZESYLANY DO FUNKCJI
	int arr[] = {5,3,6,3,6,7,89,3,6,3,6};
	
	int i= sizeof(arr)/sizeof(int);
	
	for(i; i>=0 ; i--)
	{
		if(arr[i]==7)
		break;
	}
	
	printf("7 is on %d number of array\n", i);
	
	int arr2[] = {1,2,4,5,6,6,7,8};
	
	
	
	return 0;
}
















