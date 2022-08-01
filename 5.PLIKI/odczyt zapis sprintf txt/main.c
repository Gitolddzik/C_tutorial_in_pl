#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int find_result(int* wys, int n)
{
	
		int tmp=0;
		int location=0;
		int result=0;
		
	while(1)
    {	
    	
    	location=0;
    
        for (int i = 1; i < n+1; i++)  
	  	{  
	  		
		    if(wys[i]!=0)
		    {
		    location = i;	
		    break;  //ustawienie lokacjji
			}
		    	    	
		}	       
	    
		
	  	for (int i = 1; i < n+1; i++)  
	  	{  
	  		
		    if (wys[i] < wys[location] && wys[i]!=0) 
		    {	
		    	location = i;
			    	
			}	       //WYSZUKIWANIE NAJMNIEJSZEJ WARTOSCI
	    }
	    
	   tmp=location;
	   location = wys[location]; //przypisanie do wartosci wartosci z array
	    
	    for (int i = tmp ; i < n+1; i++) 
	  	{  

			if(wys[i] == location && wys[i] != 0)
			 {
				tmp = i;
				
				while(wys[tmp] != 0)
				{
					wys[tmp] -= location;
					tmp--;	
				}
				
				
				tmp=i;
				wys[tmp] = location;
				
				while(wys[tmp] != 0)
				{
					wys[tmp] -= location;
					tmp++;
					i++;	
				}
				result++;
				
			}
			 
			if(wys[i-1] == 0 && wys[i+1] == 0 && wys[i] != 0 ) 
	  	 	 {
			  	 result++;
				 wys[i] = 0; //eliminowanie "wiezowcow"	 
		 	 } 	         
	    }
	    
	    
	    if(location==0)
	    {
	    return result;
		}
 
	}
}

int main(int argc, char** argv) 
{
	
	int n;
	int wys[270000];
	int result=0;
	long long unsigned cntr;
	
   /*	scanf("%d\n", &n);
      
	    for(int i=1;i<n+1;i++)
		{      	
			scanf("%d %d\n", &wys[i] , &wys[i]); //szerokosc jest kompletnie nie potrzebna, daltego nie tworzyłem nawet zmiennej dla niej, zostaje nadpisana  za każdym razem.	
		}
	*/	
	
	FILE* in;
		
	char bufor_in[20];
		
	fopen_s( &in , "point.dat", "r");
	
	
	if(in == NULL)
	{
	printf("xdf");
	return 1; //jak nie ma pliku
		
	}
	
	if(fgets(bufor_in, 20, in)==NULL)
	{
	fclose(in);  //jka plik jest ale nie mozna odczytac tego co jest w srodku
	printf("xd");
	return 1;	 
	}
	        
	           
	sscanf_s(bufor_in,"%d %d\n", &n);
	printf("%s", bufor_in); 
	
 	for(int i=1;i<n+1;i++)
 	{
 			fgets(bufor_in, sizeof(bufor_in), in);
 			
 			 char *token = strtok(bufor_in, " ");
    
 
      token = strtok(NULL, " ");
      wys[i]=atoi(token);
     // printf( "%d\n", wys[i] );
      token = strtok(NULL, " ");
   	}
	

	


	fclose(in);

	result=find_result(wys, n);
	
	printf("%d",result);
	
 return 0;
}
