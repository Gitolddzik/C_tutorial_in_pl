#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
  double x,y;
}Person;

Person sredia (Person a,Person b)
{
	Person Personmid_temp;
	Personmid_temp.y = (a.y + b.y)/2;
	Personmid_temp.x = (a.x + b.x)/2;
	
	return Personmid_temp;
}


Person* sredia_DYN (const Person* a, const Person* b) //const bo tutaj mozemy je zmienic, a nie chcemy ich zmieniac
{
	Person* Personmid_temp = malloc(sizeof(Personmid_temp)); 
	Personmid_temp->x = (a->x + b->x)/2;
	Personmid_temp->y = (a->y + b->y)/2;
	
	return Personmid_temp;
}

void sredia_ref(const Person* a, const Person* b, Person* Personmid_mid)
{
	Personmid_mid->x = (a->x + b->x)/2;
	Personmid_mid->y = (a->y + b->y)/2;
}


int main(int argc, char** argv) {
	
//1 NIEZOPTYMALIZOWANY SPOSOB slaba wydajnosc	
	
  Person person1;
  
  person1.x = 1984; 
  
  person1.y = 2500;


  printf("x: %f\n", person1.x);
  printf("y: %f\n", person1.y);


  Person person2;
  
  person2.x = 194;
  
  person2.y = 220;

  printf("x: %f\n", person2.x);
  printf("y: %f\n", person2.y);
	

  Person Personmid; 

  Personmid = sredia ( person1 , person2 );
  
  printf("x: %f\n", Personmid.x);
  printf("y: %f\n", Personmid.y);
  
  
  
  //2 ŚREDNI SPOSOB Z DYNAMICZNA ALOKACJA (średni bo trzeba zwalniać zaalokowaną pamięć)
  
  Person* Personmid_dyn; 

  Personmid_dyn = sredia_DYN ( &person1 , &person2 );
  
  printf("x: %f\n", Personmid_dyn->x);
  printf("y: %f\n", Personmid_dyn->y);
  
  free(Personmid_dyn);
  
  
  //3 NAJLEPSZY sposob (referencja) bez zwalniania pamieci i alokacji
  
  Person Person_mid;
  
  sredia_ref ( &person1 , &person2, &Person_mid);
  
  printf("x: %f\n", Person_mid.x);
  printf("y: %f\n", Person_mid.y);
  
   
  return 0;
}