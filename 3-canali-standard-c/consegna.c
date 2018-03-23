#include <stdio.h>

int main() {
    char input;

    do {
        /* Get input string */
        fscanf(stdin, "%c", &input);

        /* Check if the letter is lowercase */
        if(97 <= input && input <= 122)
             /* Print it uppercase */
            printf("%c", (input - 32));
        else
             /* Print it normally */
            printf("%c", input);
    }while(input != '\n');

    return 0;
}
