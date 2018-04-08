#include <stdio.h>
#include <ctype.h>

int main () {
   int i = 0;
   char str[] = "ciao mondo";
   
   while(str[i]) {
      putchar (toupper(str[i]));
      i++;
   }
   
   return(0);
}

