#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void main() {

    char inSentence[100];

    srand(time(NULL));
    
    fscanf(stdin, "%[^\n]s ", inSentence);

    for (int i = 0; i < 100; i++) {
        if ((rand() % 2 == 0)) {
            inSentence[i] = toupper(inSentence[i]);
        } else {
            inSentence[i] = tolower(inSentence[i]);
        }
    }

    fprintf(stdout, inSentence);
}