#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	
	/*	


	char text2 [100];
	
	printf("tell me something intesting\n");

	scanf("%[^\n]s", &text2);  //[^\n] wszytaj wszystko az to tekstu enter
	
	printf("%s\n", text2);
	
	
*/

//Problem jest taki ze nie mozesz uzwac tego z innymi, scanf bedzie odczytywac wszystko do momentu napotkania \n (pozostawiajac \n nieprzeczytane)

//mozesz cheatowac i zrobic tak:

	char text2 [100];
	
	printf("tell me something intesting mozesz ze spacja\n");

	scanf("%[^\n]s", &text2);  //[^\n] wszytaj wszystko az to tekstu enter
	
	getchar();//cheat
	
	printf("%s\n", text2);
	
	
	
	
	
	
printf("______________________________\n");
	



	
	char text [100];
	
	printf("tell me something intesting ale bez spacji input zostanie i przy nastepnej probie odczytania sie wczyta psujac program\n");

	scanf("%s", &text);
	
	getchar(); // jak dajesz same scanf to nie musi tego byc ale jak tu tego nie dam to fgets nie zadziala
	
	printf("%s\n", text);
	
	//Wszystko spoko i ladnie ale wpisz jakies zdanie albo 2 wyrazy ze spacja, i co? nie dziala.
	
	
		
	
	printf("______________________________\n");
	
	
	//NAJLEPSZY SPOSOB

	printf("tell me something intesting mozesz jak chcesz i elo\n");
	
	char text3 [100];
	
	fgets(text3, 100, stdin); //zmienna, liczba znakow, wejscie konsoli
	
	text3[strlen(text3)-1] = '\0'; //=0 fgets ma wade ze automatycznie dajne na koncu znaj nowej linii, zamiast niego dajemy 0, tak jak powinno byc w stringu \n -> \0
	
	printf("%s\n", text3);
	
	
	return 0;
}