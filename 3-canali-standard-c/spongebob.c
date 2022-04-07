#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void){
    int j, i = 0;                                                           /*Variabili di lavoro*/
    char input[21] ;                                                        /*Variabile di input*/
    srand(time(NULL));                                                      /*Inizializzazione numero pseudocasuale*/


    fprintf(stdout, "Inserisci la parola che vuoi spongebobbizzare\n(massimo 20 caratteri): ");
    fgets(input,20,stdin);                                                  /*Acquisizione input*/
    
    while(input[i] != '\n'){                                                /*Processazione dell'input*/
                                                              
        j = rand()%2;

        if(j == 0) 
            input[i] = tolower(input[i]);                                                                        
        else
            input[i] = toupper(input[i]);
                
        i++;                                                                    /*Incremento variabile di controllo*/
    }
    fprintf(stdout, "La parola ottenuta e' %s\n", input);                   /*Erogazione dell'output*/

    return 0;
    }