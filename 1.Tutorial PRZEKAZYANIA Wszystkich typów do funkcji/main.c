#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intiger_func(int intiger)
{
	
	++intiger;
	//*ptr++; nie dziala 
}

void intiger_ref_func(int* intiger_ref)
{
	
	++*intiger_ref;
	//*ptr++; nie dziala 
}

void array_func(int array[4])
{
array[3] = 5;	//a int array[] w tym kontekscie to wlasciwie to samo co *
}

void array_multi_func(int (*arr)[2][2], const int dim1, const int dim2, const int dim3)
{
// int *arr

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                *(*(*(arr + i) + j) + k) = 0;
                arr[i][j][k] = 0;
            }
        }
    }
    
    
}

void czar(char c)
{
	c= 'd'	;
}

void czar_ref(char* d)
{
	
	*d= 'e'	;
}

void strnig_fun_ref(char* string_ref)
{																																
	string_ref[0]='P';	
}																										


void sort(char** string_database, int n)  //to co dostajmey to &string_database[0] (WSKAŹNIK NA POCZĄTEK TABLICY WSKAZNIKOW NA STRINGI) 
{  //w skrócie jak to wygląda:
// string_database - pierwszy element tablicy wskaznikow (czyli wskaznik)
// *string_database - Dereferencja wskaznika czyli mamy adres w formie jakiegos long intigera
// **string_database - Druga dereferencja tego wskaznika dająca nam już F w napisie "Florida" czyli tak jakby dokopaliśmy się do elementu [0][0] w dwu wymiarowej tablicy, możemy zacząć działać


   printf(" %c\n\n", **string_database); //F w napisie "Florida" czyli element [0][0]
   printf(" %s\n", *string_database);  //napis Florida 
   printf(" %s\n",  string_database[0]);  //napis Florida 
   printf(" %s\n\n",  string_database[1]);  //napis Oregon
   
    for (int i=0; i<n; i++)
	{
        printf("String: %s\n", string_database[i]);   // no to wypisujemy wszystko
    }
    string_database[0]="Grzegorz Floryda";  //mozna zmieniac
}



	typedef struct Person 
	{	
 	 double x,y;
	}Person;
	


void STRUCT_sredia (Person a, Person b)
{
	Person Personmid_temp;
	Personmid_temp.y = (a.y + b.y)/2;
	Personmid_temp.x = (a.x + b.x)/2;	
	
	printf("x: %f\n", Personmid_temp.x);
	printf("y: %f\n\n", Personmid_temp.y);
}



void STRUCT_sredia_ref(const Person* a, const Person* b, Person* Personmid_mid)
{
	Personmid_mid->x = (a->x + b->x)/2;
	Personmid_mid->y = (a->y + b->y)/2;
}








int main()
{
	//Przekazywanie int 
	
	int intiger = 5;
	printf("%d\n", intiger);
	intiger_func(intiger);
	printf("%d\n\n", intiger);
	
	//Przekazywanie int z referencją
	
	int intiger_ref = 5;
	printf("%d\n", intiger_ref);
	intiger_ref_func(&intiger_ref);
	printf("%d\n\n", intiger_ref);
	
	//Przekazywanie array NIE DA SIE BEZ REFERENCJI
	
	//Przekazywanie array int z referencją
	
	int array[] = {1,2,3,4,5};
	printf("%d\n", array[3]);
	array_func(array);      //a no zmienia się dlatego że array to adres pierwszego elemnu w tabliy ->cdn w funkcji
	printf("%d\n\n", array[3]);
	
	//Przekazywanie WIELOWYMIAROWEJ array int z referencją
	int arr[3][2][2]={0,1,2,3,4,5,6,7,8,9,3,2};
	
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				printf("%d ",arr[i][j][k]);
				if(k==3)
				{
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	
	array_multi_func(arr,3+1,2+1,2+1);   //+1 bo zaczynamy liczenie od 0
	
	for(int i=1;i<=2;i++)
	{
		
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				printf("%d ",arr[i][j][k]);
				if(k==3)
				{
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	
	
	//Przekazywanie char

	char c = 'c';
	printf("%c\n", c);
	czar(c);
	printf("%c\n\n", c);
	
	//Przekazywanie char z referencją
	
	char d = 'd';
	printf("%c\n", d);
	czar_ref(&d);
	printf("%c\n\n", d);

	//Przekazywanie string  //string to tablica so nie ma jak jej przekazać bez referencji

	//Przekazywanie string z referencją
	
	char string_ref[] = "tekst";
	printf("%s\n", string_ref);
	strnig_fun_ref(string_ref);  //string ref jest rzutowany na wskaznikiem   
	printf("%s\n\n",string_ref);
	
	//Przekazywanie array string z referencją
	
    char* string_database[4];  //dlaczego nie char string_database[4]? bo w zasadzie to robisz coś takiego string_database[wskaźniki na początki stringów] czyli tablice 4 wskaźników a KAŻDY z nich wskazuje na ADRES POCZĄTKU STRINGA
    string_database[0]="Florida"; 
    string_database[1]="Oregon";
    string_database[2]="California";
    string_database[3]="Georgia";
    sort(string_database, 4);  // string_database oznacza tyle samo co &string_database[0] czyli wskazuje na wskaźnik wskasujący na F w napisie "Florida> cdn w funkcji
	printf("String: %s\n", string_database[0]);
	
	//Przesylanie STRUCT bez referencji
	
	  Person person1;
	  person1.x = 1984; 
	  person1.y = 2500;
	  printf("\n\nx: %f\n", person1.x);
	  printf("y: %f\n", person1.y);
	  Person person2;
	  person2.x = 194;
	  person2.y = 220;
	  printf("x: %f\n", person2.x);
	  printf("y: %f\n\n", person2.y);
		
	  STRUCT_sredia ( person1 , person2 );
	  
	  //Przesyłanie STRUCT Z REFERENCJĄ
	  
	Person Person_mid;
  
  	STRUCT_sredia_ref ( &person1 , &person2, &Person_mid);
  
 	printf("x: %f\n", Person_mid.x);
 	printf("y: %f\n", Person_mid.y);
	
	
                      
     return 0;                  
}
                          