#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

int main(int argc, char** argv) 
{
	
	//Does pointer have a data type?
   
    //C does not recognize pointers as data types; they are just integers. An address is simply a pointer in general.
	
	
	int* p,r; // = int *p, int r
	
	int* q,*t; // = int*q, int *t
	
	int (*arr)[10];  //Pointer na tablice 10 elementow do intow
	int *arrr[10];   //TABLICA 10 POINTEROW(!) do intow
	
	
	int x=1;
	int* wsk = &x;
	printf("%d \n", x);  //wyswietl wartos x
	printf("%d  \n", &x);   //wyswiatl adres w pamieco jaki zajmuje x
	printf("%d   \n", wsk);  //wyswietl to co poprzednio bo (wsk = &x;)
	printf("%d    \n", *wsk);   // *- wyswitel wartosc zmiennej znajdujacej sie w adresie wsk
	printf("%d     \n", *(&x));  // *- wyswitel wartosc zmiennej znajdujacej sie w adresie x
	printf("%d      \n", &wsk);   //wyswietl adres zmiennej wsk
	
	int* wskx;
	wskx = &x;
	x=x+5;         //TO SAMO
	x=*wskx + 5 ;     ///TO SAMO
	*wskx = *wskx + 5;   // TO SAMO
	/*w skrocie:
	
	int* -ZMIENNA WSKAZNIKOWA definicja typu wskaznika, ta gwiazdka mowi ze dana zmienna ma wskazywac na 4 bajty pamieci czyli tyle ile zajmuje int
	
	* wyswietla wartosc ZMIENNEJ znajdujacej sie po danym adresem pamieci
	
	& wyswietla adres w pamieci ZMIENNEJ.
	________________
	*x  ZLE
	
	&x DOBRZE     -adres w pamieci x
	
	*&x DOBRZE    -wartosc zmiennej x
	________________
	wsk           -adres w pamieci x
	
	*wsk DOBRZE   -wartosc zmiennej x
	
	&wsk DOBRZE   -adres w pamieci wsakznika
	_______________
	
	*/
	
	
		printf("_________________________________\n");
		
		
	//dynamiczna alokacja 1 zmiennej
	//__________________________________________
	int* a = (int*) malloc(sizeof(int));
	
	*a = 5;
	
	printf("Wartosc a = %d\n", *a);
	
	free(a);
	
	
	
	//____________________________________
	//dynaimczna alokacja paru zmiennych na raz
	int* b = (int*) malloc(3*sizeof(int));
	
	b[1]=5;
	b[2]=3;
	
	printf("Wartosc b = %d , %d , %d\n", b[0],b[1],b[2]);
	
	free(b);
	
		
	
	//_____________________________________________________________________________
	//dynamiczna alokacja ale c alloc zamienia wartosci we wszystich adresach najpierw na 0 tak w razie co zeby bledow uniknac
	
		int* c = (int*) calloc(3, sizeof(int));  //ROZNICA
	
	c[1]=5;
	c[2]=3;
	
	printf("Wartosc c = %d , %d , %d\n", c[0],c[1],c[2]);
	
	free(c);
	
	
	
	
	//_______________________________________________________________________
	
		
		
		
	
	return 0;
}