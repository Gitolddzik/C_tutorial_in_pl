#include <stdio.h>

/*1) A static int variable remains in memory
 while the program is running. A normal or auto 
 variable is destroyed when a function call where the 
 variable was declared is over.
 
 Static variables are allocated memory in data segment, not stack segment */
 
 //https://www.geeksforgeeks.org/static-variables-in-c/
 
int funstaticvariables()
{
  static int count = 0;
  count++;
  return count;
}


int fun()
{
   int count = 0;
  count++;
  return count;
}

int initializer(void)
{
    return 50;
}
  


int main(int argc, char** argv) 
{
	printf("%d ", funstaticvariables());
	printf("%d ", funstaticvariables());
    printf("%d\n\n", funstaticvariables());
    
 	 printf("%d ", fun());
 	 printf("%d ", fun());
 	 printf("%d\n\n", fun());
 	 
 	 
 	//static int i = initializer(); //wywyala blad (w c++ nie wywali) wywala daltego ze wszystkie statyczne objekty musza miec nadana wartosc przed wykonaniem sie funkcji main
 	static int i = 5; //dzia;a
    printf("value of i = %d", i);  
    
	return 0;
}