#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

/*On dereferencing a pointer expression we get a value pointed
 to by that pointer expression. Pointer to an array points to an 
 array, so on dereferencing it, we should get the array, and the 
 name of array denotes the base address. So whenever a pointer to
  an array is dereferenced, we get the base address of the array 
  to which it points. */

int  main()
{

int (*parr)[5]; //WSKAZNIK na 5 elementowy blok pamieci intow (wieklkosc = 20)
int* p; //zwykly wsakznik (wieklkosc = 8)

int arr[5]={1,2,3,4,5}; //deklaracja i definicja tablicy

for(int i = 0; i<5 ; i++)
    printf("%d\n", (*arr+i)); //wyswietla elementy tablicy

p=arr;
parr=&arr; //ale hej, arr i &arr to to samo. to co to ma znaczyć &arr?
//jesli damy tu parr=arr bedziemy mieli konwersje z int (*)[5] do int *
//w duzym i pol poprawnym skrocie: dzieki temu mozemy w parr trzymac np adres 1 elementu arr

printf(" %u\n", p); //adres arr
printf(" %u\n\n", parr); //adres arr

printf(" %u\n", *p); //1 element arr
printf(" %u\n", *parr); //adres 1 elementu arr :)
printf(" %u\n\n", arr); //to samo co &arr[0]





//okej a jak to sie ma z 2 wymiarowymi tablicami?

int arr2D[3][4] = 
{
{10, 11, 12, 13},
{20, 21, 22, 23},
{30, 31, 32, 33}
};


printf("%u\n", arr2D); //adres wskaznika na 1 element
printf("%u\n", *arr2D); //adres poczatku 1 tablicy 1 wymiarowej
printf("%u\n\n", **arr2D); //wartosc 1 elementu

printf("%u\n",   arr2D); //adres wskaznika na 1 element
printf("%u\n",   *(arr2D+1)); //adres poczatku 2 tablicy 1 wymiarowej (+4*sizeof(int))
printf("%u\n\n", *(*(arr2D+1)+2)); //wartosc 2 elementu 2 tablicy 1 wymiarowej

//to znaczy ze tablica arr2D sklada sie z 4(!) tablic 1(nazijmy "Glowna") tablica zawiera
//3 pointery, ktore wskazują na początki trzech 1 wymiarowych tablic.

//graficznie:

/*
add2D   = p1 czyli wskaznik na adres 1 elementu 1 tablicy
*add2D  = adres 10
**add2D = 10

[     p1      ,     p2      ,     p3      ]
-------------------------------------------
|p1 = adres 10|p2 = adres 20|p3 = adres 30|
| 10,11,12,13 | 20,21,22,23 | 30,31,32,33 |  
-------------------------------------------
*/


int (*parr2D)[4]; //4 elementowa tablica wskaznikow
parr2D = arr2D; //a czemu nie &arr halo?
//dlatego ze nie chcemu zgarniac całej tablcy jesli bysmy chciali zrobili bysmy
//int (*parr2D)[3][4]; i parr2D = &arr2D; jest tu git.
//ale zauwaz ze tak naprawde potrzebujemy tablicy pointerow z ktorej kazdy element ma w sobie
//adres poczatku jendowymiarowej tablicy (tablica 2d [3][4] to trzy 4 elementowe tablice jednowymiarowe i to ich poczatkow adresy chcemy)

   printf("%u %u %u\n", arr2D, arr2D + 1, arr2D + 2);
   printf("%u %u %u\n", *arr2D, *(arr2D + 1), *(arr2D + 2));
   printf("%u %u %u\n", **arr2D, *(*(arr2D + 1) + 2), *(*(arr2D + 2) + 3));
   printf("%u %u %u\n\n", arr2D[0][0], arr2D[1][2], arr2D[2][3]); 


   printf("%u %u %u\n", parr2D, parr2D + 1, parr2D + 2);
   printf("%u %u %u\n", *parr2D, *(parr2D + 1), *(parr2D + 2));
   printf("%u %u %u\n", **parr2D, *(*(parr2D + 1) + 2), *(*(parr2D + 2) + 3));
   printf("%u %u %u\n", parr2D[0][0], parr2D[1][2], parr2D[2][3]); 

   //tak nawiasem mowiac mozna zrobic cos takiego, ale trzeba potrojnej dereferencji
   //zeby dostac sie do jakiegokolwiej elementu co troche utrudnia czytelnosc kodu:

   int (*ptr)[3][4];
   ptr = &arr2D;

   printf("%u\n",***ptr);

return 0;
}