#include <stdio.h>

int main() {
    printf("Hello world!\n");
    fprintf(stdout, "Hello world!\n");

    fprintf(stdout, "Test output\n");
    fprintf(stderr, "Test errore\n");

    printf("Leggo il primo carattere di input...\n"); // effettivamente equivalente a fprintf(stdout, "Leggo il primo carattere di input...\n");
    char c = fgetc(stdin);
    printf("Hai scritto %c\n", c);
}
