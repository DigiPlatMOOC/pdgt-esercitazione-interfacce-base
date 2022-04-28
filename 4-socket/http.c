#include <stdio.h>
#include "socket-lib.h"

#define HOST "www.google.com"
#define PORT 80

int main() {
    if(socket_init() != 0) {
        fprintf(stderr, "Inizializzazione del socket fallita!!!\n");
        return 1;
    }

    SOCKET_T socket = socket_create();
    if(socket == 0) {
        fprintf(stderr, "Creazione del socket fallita!!!\n");
        return 1;
    }

    if(socket_connect(socket, HOST, PORT) < 0) {
        fprintf(stderr, "Connessione al socket fallita!!!\n");
        return 1;
    }

    printf("Connesso!\n");

    char input[512] = "GET www.google.com HTTP/1.1\n\n";
    //memset(input, 0, sizeof(char) * 512);

    printf("Inviato.\n");
    //fgets(input, 511, stdin);

    send(socket, input, strlen(input), 0);
    socket_close_send(socket);
	
    char output[4096]; 
    int read = socket_read_all(socket, output, 4095);
    printf("Ricevuto: ");
    printf("%s", output);
    printf("\n");

    socket_close(socket);

    if(socket_quit(socket) != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}
