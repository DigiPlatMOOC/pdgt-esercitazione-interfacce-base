#include <stdio.h>
#include "socket-lib.h"

#define HOST "google.com"
#define PORT 443

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

    char* input = "GET / HTTP/1.1\n\n";

    printf("Sent > %s", input);

    send(socket, input, strlen(input), 0);
    socket_close_send(socket);
    
    char output[4096];

    int read = socket_read_all(socket, output, 4095);
    printf("Received: \n");
    printf("----------------------------------------------------\n");
    for(int i = 0; i < read; ++i) {
        fputc(input[i], stdout);
    }
    printf("\n");
    printf("----------------------------------------------------\n");

    socket_close(socket);

    if(socket_quit(socket) != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}
