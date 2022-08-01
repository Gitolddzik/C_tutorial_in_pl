#include <stdio.h>

typedef struct linked_list{
	int x;
	struct linked_list* next;
}linked_list;

int main(int argc, char** argv) {
	
	linked_list pierwszy;
	
	pierwszy.x = 15;
	pierwszy.next = malloc(sizeof(linked_list)); 
	pierwszy.next->x = 20;
	pierwszy.next->next = malloc(sizeof(linked_list)); //za kazda nowa struktura musimy alokowac pamiec
	pierwszy.next->next->x = 30;
	pierwszy.next->next->next = NULL;

	//moge!
	linked_list* temp = &pierwszy;
	
	while(temp != NULL)	
	{
	printf("%d\n",temp->x);
	temp=temp->next;
	}	
	
	
	printf("\n");
	
	//to samo:
	
	temp = &pierwszy;
	
	for(temp; temp != NULL; temp=temp->next)
	{
	printf("%d\n",temp->x);	
	}
	
	
	free(pierwszy.next);
	return 0;
}