#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int main(void) {
    
    char parola[50];
    int i = 0;
    int n = 0;

    srand(time(NULL));
    
    fgets(parola, 50, stdin);

    while (parola[i] != '\n'){
        n = rand();
        if (n % 2 == 0) {
            parola[i] = toupper(parola[i]);
        }
        i++;
    }
    
    fprintf(stdout,"%s", parola);
    return(0);
}