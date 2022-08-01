#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
	int x;
	struct linked_list* next;	//wskaznik na kolejny elelment w "tablicy struktur rozmieszczonej nieciagle w pamieci;
}linked_list;

int main(int argc, char** argv) {
	
	linked_list first;
	linked_list second;
	linked_list third;
	
	first.x = 15;
	first.next = &second;
	second.x = 20;
	second.next = &third;
	third.x = 30;
	
	third.next = NULL;
	
	
	printf("%d\n",first.x);
	printf("%d\n",second.x);
	printf("%d\n\n",third.x);
	
	//a mozna inaczej? tak
	
	printf("%d\n",first.x);
	printf("%d\n",first.next->x); //  (*first.next).x to to samo
	printf("%d\n\n",first.next->next->x); // First.next = wskaznik na element second (adres second (&second)) ||teoretycznie to to samo co (*&second).x
										// first.next->next = &second->next = (adres third (&third)) 
										//first.next->next->x = &third->x = third.x :)
										
	//dobra ale po co nam w takim razie second i third jak nie musimy ich potem uzywac?
	//no po nic nie?
	
	//zrobmy to jeszcze raz ale bez nich
	
	linked_list pierwszy;
	
	pierwszy.x = 15;
	pierwszy.next = malloc(sizeof(linked_list)); //zamiast &drugi zajmujemy mu pamiec przez malloc
	pierwszy.next->x = 20;
	pierwszy.next->next = malloc(sizeof(linked_list)); //za kazda nowa struktura musimy alokowac pamiec
	pierwszy.next->next->x = 30;
	pierwszy.next->next->next = NULL;
	
	third.next= NULL;
	
	
	printf("%d\n",pierwszy.x);
	printf("%d\n",second.x);
	printf("%d\n\n",third.x);
	
	printf("%d\n",pierwszy.x);
	printf("%d\n",pierwszy.next->x); //  (*pierwszy.next).x to to samo
	printf("%d\n\n",pierwszy.next->next->x);
	
	free(pierwszy.next);
	
									
	return 0;
}