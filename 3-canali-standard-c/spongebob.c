#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
	char stringa[255]; // Stringa in input di dimensione 255 caratteri
	                   // incluso \n. 
	int  i = 0;        // Contatore per l'inserimento della stringa
	int  j = 0;        // Contatore per la conversione in spongebob
	                   // casing
	
	// Creo il seed per la rand
	srand(time(NULL));
	
	// Dalla stdin prendo tutti i caratteri che passano fino a che non 
	// preme invio o finisce lo spazio del bbuffer
	while ((stringa[i] = fgetc(stdin)) != '\n' && i < 255)
		i++;
	
	// Per ogni carattere ad eccezione dello spazio generiamo un numero
	// pseudo-casuale: se è pari diventa maiuscolo. Questo per dare
	// il 50% di probabilità.
	for (; j < i; j++) {
		if (stringa[j] != ' ')
			if ((rand()) % 2 == 0)
				stringa[j] = toupper(stringa[j]);
	}
	printf("%s", stringa);
    return (0);
}
