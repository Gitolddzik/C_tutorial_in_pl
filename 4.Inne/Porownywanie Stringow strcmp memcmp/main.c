#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
	char str1[] ="abcd4";
	char str2[] ="abcdf";
	char str3[] ="abcd4";
	
	printf("%d\n",strcmp(str2,str1)); //zwraca 1
	printf("%d\n",strcmp(str1,str2)); //zwraca -1  //dlatego ze pierwsza roznoaca sie liera jest wyzej w asciii stad 1 albo -1
	printf("%d\n_______________\n",strcmp(str1,str3)); //zwraca 0 prawda
	
	printf("%d\n",strncmp(str2,str1,4)); //porownuje pierwsze 4 zwraca 1
	printf("%d\n_______________\n",strncmp(str2,str1,5)); //porownuje pierwsze 4 zwraca 0
	
	printf("%d\n",memcmp(str2,str1,4));
	printf("%d\n_______________\n",memcmp(str2,str1,5));  //porownanie pamieci
	
	//POROWNYWANIE TABLIC
	
	int arr[] = {1,2,3,5};
	int arr2[] = {1,2,3,8};
	
	printf("%d\n",memcmp(arr,arr2,4));  //daje 0 :( czemu? bo tutaj lecimy po BAJTACH(!!!) char ma 1 bajt (dlatego wyzej dzialalo) a int ma 4 bajty.....
	printf("%d , %d\n",memcmp(arr,arr2,4*sizeof(int))); //teraz porownuje 12 bajtow
	
	return 0;
}