#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main () 
{
   int  a= 0;
   //char c;
   
   char str[MAX];
   
   printf("Inserire la stringa\n");
   char *gets( char *str ); 
  
   //while((c=getchar()!='\n')&&(i<MAX))
   //while(str[i]) 
   //{
      //putchar (toupper(str[c]));
      //putchar (toupper (c));
      //str[i] = c;
      //putchar(str[i]);
      //printf("%c", c);
      //i++;
  // }
   
    //for(; a < (strlen(str)); a++)
    while(str !='\n')
    {
        printf("%c",str[a]);
        a++;
    }
   
   return(0);
}

 //for(i=0; i<strlen(c); i++)
   // {
     //   tolower(c[i]);
    //}
