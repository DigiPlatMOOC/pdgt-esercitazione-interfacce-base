#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){
    int n_casuale;
    char l;

    srand(time(NULL));
    while(fscanf(stdin, "%c", &l) != EOF){
        n_casuale = rand() % 100 + 1;
        if(n_casuale % 2 == 0)
            printf("%c", tolower(l));
        else 
            printf("%c", toupper(l));
    }
    printf("\n\n");
}