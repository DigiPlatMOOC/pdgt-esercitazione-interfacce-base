#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){
	char c;
	srand(time(0));

	do{
		c = fgetc(stdin);
		if(rand() % 2 == 0){
			if(isupper(c)){
				c = tolower(c);
			} else {
				c = toupper(c);
			}
		}
		fprintf(stdout, "%c", c);
	} while(c != EOF);

	return 0;
}
