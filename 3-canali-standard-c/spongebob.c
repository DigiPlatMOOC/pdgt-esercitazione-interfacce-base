#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	char attuale;
	srand(time(NULL));
	
	for(attuale = fgetc(stdin); attuale != EOF; attuale = fgetc(stdin) ){
		if((rand() % 2) == 1){	
			if(attuale >= 'a' && attuale <= 'z')
				attuale = toupper(attuale);
			else if(attuale >= 'A' && attuale <= 'Z')
				attuale = tolower(attuale);
		}
		fputc(attuale, stdout);
	}

	return 0;
}

