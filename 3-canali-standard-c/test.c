#include <stdio.h>

int main() {
	
	FILE *il_mio_file = fopen("file.txt", "w");
	fprintf(il_mio_file, "Hello World!!!");
	fclose(il_mio_file);
	
    fprintf(stdout, "Test output\n");
    fprintf(stderr, "Test errore\n");

    printf("Leggo il primo carattere di input...\n"); // equivalente a fprintf(stdout...)
    char c = fgetc(stdin);
    char d = fgetc(stdin);
	printf("Hai scritto %c e %c\n", c, d);
}
