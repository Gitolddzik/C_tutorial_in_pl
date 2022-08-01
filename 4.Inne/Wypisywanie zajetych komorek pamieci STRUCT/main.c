#include <stdio.h>
#include <stdlib.h>

struct Things{
	int x;
	short xs;
	long xl;
	char ona[20];
	int* wsk;
	
};

int main(int argc, char** argv) {
	int i;
	struct Things thing = {9,10,11000," O kurwa woah",&i};
	printf("%llu\n\n",sizeof(thing));
	
	unsigned char data;
	
	for(int i=0 ; i<sizeof(thing) ; i++)
	{
	data=*(((unsigned char*)&thing)+i);  //tak musi byc zeby wypisac to co jest w pamieci.
	printf("%2x ",data);
	
	if(i%4==3)
	{
	printf("\n");	
	}
	}
	
	return 0;
}