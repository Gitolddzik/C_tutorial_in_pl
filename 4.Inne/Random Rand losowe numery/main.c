#include <stdio.h>
#include <time.h> //!!!!!!!!!!!!!!!!!!!!!!!!!11


int main(int argc, char** argv) 
{
 /*time_t secondsFromepoch = time(NULL);
 srand(secondsFromepoch);*/
 
 
srand(time(NULL)); //szybsza wersja
 printf("%d\n",rand());
  printf("%d\n",rand());
   printf("%d\n",rand());
	

	return 0;
}