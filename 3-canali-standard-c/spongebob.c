
/***********************************************************************/
/* programma per l'applicazione dello 'SpongeBob Casing" a una stringa */
/***********************************************************************/

/*****************************/
/* inclusione delle librerie */
/*****************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***********************************/
/* definizione della funzione main */
/***********************************/

int main(void)
{
    /* dichiarazione delle variabili locali alla funzione */
    char c;

    /* inizializzazione del generatore di numeri pseudo-casuali */
    srand(time(NULL));

    printf("\n");

    /* applicazione dello 'SpongeBob Casing" alla stringa di ingresso */
    while ((c = getchar()) != EOF && (c != '\n'))
    {
        if ((rand() % 2) == 0)
        {
            /* conversione del carattere in minuscolo (50% di probabilità) */
            putchar(tolower(c));
        }
        else
        {
            /* conversione del carattere in maiuscolo (50% di probabilità) */
            putchar(toupper(c));
        }
    }

    printf("\n\n");

    return(0);
}

