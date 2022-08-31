#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) 
{   
    char arr[32];
    char str[32];
    int x=5;
    for(int i=0 ;i<32 ;i++)
    {
        arr[i]=(char)(x%2); 
        x/=2;
    }

    int temp;
    for(int i = 0; i<16; i++){
        temp = arr[i];
        arr[i] = arr[32-i-1];
        arr[32-i-1] = temp;
    }

    for(int i=0 ;i<32 ;i++)  
        printf("%d", arr[i]);             
                           

    return 0;
}