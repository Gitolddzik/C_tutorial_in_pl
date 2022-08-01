#include <stdio.h>
#include <stdlib.h>


void function(int *ptr) 
{
	
    printf("%d\n", *ptr);
    (*ptr)++;
}

void function2(int **ptr)  //*= defereranja adresu wskaznika czyli mam wskazik *=dereferancja wskazinka czyli mam wartosc
{
    printf("%d\n", **ptr);
    (**ptr)++;
}

int main(void) 
{
    int variable = 111;
    

    int* ptr = &variable;
    
    function(ptr);
    function2(&ptr);   //przesylam adres wskaznika
    
    
    printf("%d\n", variable);
    
    
    
    return 0;
}