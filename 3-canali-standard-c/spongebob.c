/*Autore: Berardi Martin*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(){
	char c; 	/* singolo carattere della stringa */
	int n;		/* numero casuale tra 1 e 2 che indica la probabilita' del 50% di */
				/* ottenere una lettera maiuscola o minuscola */
	time_t t;	/* variabile temporale per il seme della rand */
	
	fprintf(stdout, "Inserisci la stringa: ");	/* acquisisco la stringa da stdin */
	srand((unsigned) time(&t));					/* cambio il seme ogni volta che eseguo il programma */
												/* per ottenere risultati diversi */
	
	do{
		c = fgetc(stdin);			/* leggo un carattere */
		n = rand() % 2 + 1;			/* 50% di probabilita', estraggo tra 1 e 2 */
		if(n == 1){				
			c = tolower(c);			/* trasformo il carattere in minuscolo */
		}else if(n == 2){
			c = toupper(c);			/* trasformo il carattere in maiuscolo */
		}
		fprintf(stdout, "%c", c);	/* stampo i caratteri man mano, otterro' la stringa completa */
	}while(c != '\n');				/* eseguo fino alla fine della riga */
	
	return 0;
}
