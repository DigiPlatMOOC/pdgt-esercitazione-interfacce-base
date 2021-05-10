#include <stdio.h>
#include "socket-lib.h"

#define HOST "www.google.com" 	
#define PORT 80			

int main() {
	/*inizializzo la socket e verifico l'avvenuta inizializzazione*/
    if(socket_init() != 0) {
        fprintf(stderr, "Socket initialization failed\n");
        return 1;
    }
	
	/*creo la socket e verifico il valore di ritorno*/
    SOCKET_T socket = socket_create();
    if(socket == 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }
	
	/*mi connetto alla socket dell'host e verifico*/
    if(socket_connect(socket, HOST, PORT) < 0) {
        fprintf(stderr, "Failed to connect socket\n");
        return 1;
    }

    printf("Connected!\n");

    // Put code here!
	const char *stringa = "GET / HTTP/1.1\r\nhost: www.google.com\r\n\r\n";/*HTTP*/
	/*invio la richiesta HTTP*/
	send(socket, stringa, strlen(stringa)+1, 0);
	/*notifico terminazione invio dei dati*/ 
	socket_close_send(socket);	
	
	char buffer[1024];
	/*Leggo e scrivo su stdin la risposta HTTP del server*/
	int read = socket_read_all(socket, buffer, 1023);
	printf("Ho ricevuto %s\n", buffer);

	/*chiudo la socket altrimenti scrivo su stderr*/
    if(socket_quit(socket) != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}