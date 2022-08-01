#include <stdio.h>
#include <stdlib.h>


	
	
	
	typedef struct linked_list
	{
	int x;
	struct linked_list* next; //struct (typ) | linked_list* (jakby rozmiar tego typu czyli to, że ma elemanteny) |  next (nazwa zmiennej adresowej))
	}linked_list;

//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111


	void dodaj_na_koncu(linked_list** pierwszy, int value) //linked_list** dlaczego **? przesyłamy tu &pierwszy.| *&pierwszy = pierwszy. | **&pierwszy = *pierwszy czyli dereferencja wskaźnika wskazującego na adres pierwszej struktury. (czyli przesyłamy jakby strukture)
	{
		
		printf("%x\n", pierwszy);
		
		//tworzymy nowy element
		
		linked_list* nowy_element = malloc(sizeof(linked_list)); //nowy_element to adres zwrocony przez malloc ktory zaalokowal tam pamiec wielkosci 1 elementu linked_list
		
			if(nowy_element == NULL) //w przypadku kiedy np brakuje nam pamieci zeby zaalokowac kolejny element struktury (linked listy)
			{exit(2);}
		
		nowy_element -> next = NULL;
		nowy_element -> x = value;	
		
	
		
	 	//if jesli mamy 0 elementow
		
			if(*pierwszy == NULL) //jeśli struct linked_list pierwszy == NULL
			{
				*pierwszy = nowy_element; //struct linked_list pierwszy = nowy element, bo dodajemy je po koleji
				return;
			}
		
		//ustawiamy ten nowy element na koncu listy
			
			
		 //dlaczego *pierwszy a nie pierwszy? temp = *(wskaźnik na wskaźnik) czyli &temp = &pierwsz	
		linked_list* temp = *pierwszy; 
		
			while(temp -> next != NULL)	
			{
				temp=temp->next;		
			}
			
		temp->next = nowy_element;
	
	}
	
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222	
	
	void dodaj_na_poczatku(linked_list** pierwszy, int value)
	{
		linked_list* nowy_element = malloc(sizeof(linked_list)); //nowy_element to adres zwrocony przez malloc ktory zaalokowal tam pamiec wielkosci 1 elementu linked_list
		
			if(nowy_element == NULL) //w przypadku kiedy np brakuje nam pamieci zeby zaalokowac kolejny element struktury (linked listy)
			{exit(3);}
		
		nowy_element -> next = *pierwszy;
		nowy_element -> x = value;
		
		
		
		*pierwszy = nowy_element;
	}
	

//33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333	
		
		
	void dodaj_po_elemencie(linked_list* wyb_elem,int value)	
	{
		linked_list* nowy_element = malloc(sizeof(linked_list)); 
		
			if(nowy_element == NULL) 
			{exit(4);}
		
		
		nowy_element -> x = value;
		nowy_element -> next = wyb_elem->next;
		wyb_elem -> next = nowy_element;
	}
	
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444

	
	void dodaj_w_kolejnosci(linked_list** pierwszy, int value)
	{
	
		if(*pierwszy==NULL || (**pierwszy).x >= value)
		{
			dodaj_na_poczatku(pierwszy, value);
			return;
		}
	
		linked_list* nowy_element = *pierwszy; 
		while(nowy_element->next != NULL)
		{
		if(nowy_element->next->x >= value)
			{
				dodaj_po_elemencie(nowy_element,value);
				return;
			}
		nowy_element=nowy_element->next;		
		}	
		
		
	dodaj_po_elemencie(nowy_element,value);	
	}
	

//5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555

	
	void usun_element(linked_list* wyb_elem, int j,linked_list** pierwszy)
	{		
		linked_list* pomocniczy = malloc(sizeof(linked_list)); 
		
			if(pomocniczy == NULL) 
			{exit(5);}
			
		if(j==0)
		{	
		pomocniczy=*pierwszy;	
		*pierwszy = (*pierwszy)->next;
		}
		else
		{
		pomocniczy = wyb_elem->next;
		wyb_elem -> next = wyb_elem -> next -> next;	
		}
		free(pomocniczy);		
	}


//6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
	
		//funckja do dealokowanie danych	
		
	void deallocate(linked_list** pierwszy) //przesylamy tutaj pierwszy element struktury zeby ustawic go jako null jak juz zdealokujemy pamiec
	{
			linked_list* temp = *pierwszy; 
		
			while(temp -> next != NULL)	
			{
				linked_list* pomocniczy = temp;
				temp=temp -> next;	
				free(pomocniczy);	
			}
			
			*pierwszy = NULL; //
				
	} 

int main(int argc, char** argv) 
{
		
	linked_list* pierwszy = NULL; //wskaźnik na pierwszy element = NULL

//1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
    	
	dodaj_na_koncu(&pierwszy,10);
	dodaj_na_koncu(&pierwszy,20);   //wywołanie funkcji dlaczego nie przesyłamy pierwszy? daltego że pierwszy=&pierwszy. &&pierwszy nie ma sensu.
	dodaj_na_koncu(&pierwszy,25);
	

	for(linked_list* temp = pierwszy; temp != NULL; temp=temp->next) //dalczego nie &pierwszy? bo w "linked_list* pierwszy" , pierwszy to &pierwszy
	{
		
		printf("%d\n",temp->x); 
	}


//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

	
	dodaj_na_poczatku(&pierwszy,5);
	printf("\n\n"); 
	
	for(linked_list* temp = pierwszy; temp != NULL; temp=temp->next) //dalczego nie &pierwszy? bo w "linked_list* pierwszy" , pierwszy to &pierwszy
	{
		
		printf("%d\n",temp->x); 
	}
	printf("\n\n"); 


//33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333	
	
	//powiedzmy ze chcemy dodac po naszym 2 elemencie liczbe 2
	//musimy zrobic fora zeby dojsc do elementu ktory chcemy dodac
	
	linked_list* wyb_emem = pierwszy;  //wyrbany element
	int i=0; //iterator
	
	for(wyb_emem; wyb_emem != NULL; wyb_emem=wyb_emem->next)  
	{
	 i++;
	 if(i==2) //dodaj po 2 elemencie
	 break;		
	}
	
	dodaj_po_elemencie(wyb_emem,15); //emelment z x = 15
	
	for(linked_list* temp = pierwszy; temp != NULL; temp=temp->next) //dalczego nie &pierwszy? bo w "linked_list* pierwszy" , pierwszy to &pierwszy
	{
		printf("%d\n",temp->x); 
	}
	printf("\n\n");

//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
	
	dodaj_w_kolejnosci(&pierwszy,2);
	dodaj_w_kolejnosci(&pierwszy,12);
	dodaj_w_kolejnosci(&pierwszy,35);
	
	
	for(linked_list* temp = pierwszy; temp != NULL; temp=temp->next) //dalczego nie &pierwszy? bo w "linked_list* pierwszy" , pierwszy to &pierwszy
	{
		printf("%d\n",temp->x); 
	}
	printf("\n\n");
	
	
//5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555	
	
	linked_list* usun_elem = pierwszy;  
	int j=0; 
	
	for(usun_elem; usun_elem != NULL; usun_elem=usun_elem->next)  
	{
	 if(j==2) //po ktorym elemencie chcemy usunac
	 break;	
	 j++;	
	}

	usun_element(usun_elem, j, &pierwszy);	
	
	
//6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666	
	
	
	for(linked_list* temp = pierwszy; temp != NULL; temp=temp->next) //dalczego nie &pierwszy? bo w "linked_list* pierwszy" , pierwszy to &pierwszy
	{
		printf("%d\n",temp->x); 
	}
	printf("\n\n");
	
	
	deallocate(&pierwszy);//alokowalismy wiec trzeba zdealokowac
	
	return 0;
}