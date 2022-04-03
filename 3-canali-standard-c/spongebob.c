#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
	/* variabilli locali */
	int numero_casuale;
	char c;
	char *parola;
	
	/* sincronizzazione generatore con clock di sistema */
 	srand(time(NULL));
	
	while (fscanf(stdin, "%c", &c) != EOF) {
		/* generazione numero pseudo-casuale */
        	numero_casuale = rand() % 100 + 1;
	
		/* conversione carattere */
        	if (numero_casuale % 2 == 0) {
			printf("%c", tolower(c));
        	} else {
			printf("%c", toupper(c));
		}
	}
	printf("\n");
}
