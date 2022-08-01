#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	
	int arr1[] = {1,2,3};
	int arr2[] = {1,2,3};
	
	if(memcmp(arr1, arr2, 3 * sizeof(int))==0)   //TA FUNCJA POROWNUJE BAJT BO BAJCIE
	{
		printf("arays are the same\n");
	}
	else
	{
		printf("arays are NOOOT the same\n");
	}
	
	//_____________________________________________]
	
	int arr3[] = {1, 2, 3};  //00 01 0002 0003
	short int arr4[] = {0, 1, 3}; // 00 01 
	
	if(memcmp(arr3, arr4, 2 * sizeof(short int))==0)  //ZAWSZE DAWAJ TU MNIEJSZY TYP
	{
		printf("arays are the same\n");
	}
	else
	{
		printf("arays are NOOOT the same\n\n");
	}
	
	//_____________________________________________]
	
	
	
	int arr5[] = {1,2,3};
	int arr6[] = {4,5,6};
	
	memcpy(arr5, arr6, 3 * sizeof(int));
	
	printf("%d\n",arr5[0]);
	printf("%d\n",arr5[1]);
	printf("%d\n\n",arr5[2]);
	
	//____________________________________
	
	
	int arr7[] = {1,2,3};

	memset(arr7, 0, 3 * sizeof(int));  //ustawia kazdy bajt na 0
	
	printf("%d\n",arr7[0]);
	printf("%d\n",arr7[1]);
	printf("%d\n\n",arr7[2]);
	
	memset(arr7, 1, 3 * sizeof(int));  //ustawia kazdy bajt na 1
	
	printf("%d\n",arr7[0]);
	printf("%d\n",arr7[1]);  //dlatego wywala nam jakies dziwne liczby
	printf("%d\n\n",arr7[2]);
	
	
	//____________________________________
		
	int arr8[] = {1,2,3};
	
	if(memchr(arr8, 2, 3 * sizeof(int)) != 0) //znaleziono 2
	{
		printf("found byte\n");
	}
	else
	{
		printf("not found byte\n\n");
	}
	
	
	
	
		if(memchr(arr8, 2, 3 * sizeof(int)) != 0) //Nie znaleziono 2
	{
		printf("found byte\n");
	}
	else
	{
		printf("not found byte\n\n");
	}
		
		
	
		if(memchr(arr8, 0, 3 * sizeof(int)) != 0) // znaleziono 0????
	{	//no ta bo liczby w tej tablicy w bajtach sa zapisane tak 0001 0002 0003 no to 0 jest 
		printf("found byte\n");
	}
	else
	{
		printf("not found byte\n\n");
	}
				
		
	
	return 0;
}