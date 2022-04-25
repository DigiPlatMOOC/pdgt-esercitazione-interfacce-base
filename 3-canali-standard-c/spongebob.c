/* inclusione di librerie */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* definizione della funzione main */ 
int main(void) 
{
	/* dichiarazione delle variabili locali */
	int i;		  /* lavoro: valore posizione */
	int j;		  /* lavoro: valore per la funzione rand */
	char parole[255]; /* input: parole che si vogliono processare */
	
	/* inizializzazione del numero pseudo - casuale */
	srand(time(NULL));   
	
	/* stampare messaggio per l'input */
	fprintf(stdout, "Inserire le parole(max.256): "); 
	
	/* acquisire l'input */
	fgets(parole, 255, stdin);
	
	/* calcolo spongebob */
	for(i = 0, j = 0; (parole[i] != '\n'); i++, j = rand() % 2) 
	{
		if(j == 0) 
            		parole[i] = toupper(parole[i]);                                                                        
       	else
            		parole[i] = tolower(parole[i]);
               
	}

	fprintf(stdout, "Parole spongebob: %s\n", parole);

    return 0;
}

