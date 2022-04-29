#include <stdio.h>
#include "socket-lib.h"
#include <string.h>

#define HOST "www.google.com"
#define PORT 80

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

    sprintf(input, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");

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
