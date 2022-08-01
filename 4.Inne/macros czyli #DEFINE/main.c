#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define  DLUGOSC  5  //dlaczego to jest lepsze niz int dlugosc = 100;?
//NIE ZAJMUJE 3 BAJTOW PAMIECI, na początku programu po prostu podstawia wszedzie 100 


//PAMIETAJ ZEBY KAZDA LICZBE W NAWIASIE DAWIAC BO KIEDY LICZ(a+1,b,c)); ZROBITMY TAK TO NIE ZADZIALA!!!!!!! (to zwykly kopiuj wklej)
#define LICZ(a, b, c) (a)*(b)+(c)/((a)+(b))  //fajny sposób na czysty kod i robienie funkcji obliczenowcyb


#define PRINT(X) printf(#X " is %d at adress %p\n", X &X) //to #X na poczatku WYSWIETLA NAZWE ZMIENNEJ I TO JEST SPOKO!

#define ZAMIEN(A,B) A ^= B ^= A ^= B  //TO DZIALA Z KAZDYM TYPEM!!!

int main(int argc, char** argv) {
	for(int i; i<(DLUGOSC*DLUGOSC) ; i+=DLUGOSC )
	{
	printf(" %d\n", DLUGOSC)	;  
	}
	
	///////////////////////////////////////a tu mamy elegancką funkcję
	int a=6;
	int b=4;
	int c=2;
	
	printf("tego liczenia mozemy uzyc wszedzie! :  %d \n\n", LICZ(a,b,c));
	
	//////////////////////////mozesz przeslac NAZWE funkcji za pomocą tego, mega
	int zmienna = 5;
	
	PRINT(zmienna);
	
	//zamienianie wartosci na fascie i ladnie
	
	int x=1;
	int y=10;
	
	printf("%d  %d\n",x,y);
	ZAMIEN(x,y);
	printf("%d  %d\n",x,y);
	return 0;
}