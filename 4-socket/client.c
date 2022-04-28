#include <stdio.h>
#include "socket-lib.h"

#define HOST "127.0.0.1" /* http://www.google.com/ -> faccio una richiesta a google*/
#define PORT 1234 /* 80 -> http */

int main() {
    if(socket_init() != 0) {
        fprintf(stderr, "Socket initialization failed\n");
        return 1;
    }

    SOCKET_T socket = socket_create();
    if(socket == 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    if(socket_connect(socket, HOST, PORT) < 0) {
        fprintf(stderr, "Failed to connect socket\n");
        return 1;
    }

    printf("Connected!\n");

    char input[512];
    memset(input, 0, sizeof(char) * 512);

    printf("Send > ");
    fgets(input, 511, stdin); /* creo una stringa statica in cui scrivo la richiesta http con la sintassi della richiesta senza header */

    send(socket, input, strlen(input), 0);
    socket_close_send(socket);

    int read = socket_read_all(socket, input, 511);
    printf("Received: ");
    for(int i = 0; i < read; ++i) {
        fputc(input[i], stdout);
    }
    printf("\n");

    socket_close(socket);

    if(socket_quit(socket) != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}
