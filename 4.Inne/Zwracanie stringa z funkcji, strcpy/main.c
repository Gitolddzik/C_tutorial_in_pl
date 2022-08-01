#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char* str)
{	
 //char str[] = "okey"; //nie dziala b0 nie zgadzaja sie typy
 strcpy( str, "tenis"); //ale tak to juz spoko
}
  
int main(int argc, char *argv[])
{
  char s[20];
  fun(s);
  printf("%s\n", s);
  return 0;
}