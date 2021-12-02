#include <stdio.h>
#include "socket-lib.h"

#define HOST "wikipedia.org"
#define PORT 80

int main(){
    // inizializzo la socket 
    if(socket_init() !=0) {
        fprintf(stderr, "Socket initialization failed\n");
        return 1;
    }

    // alloco una nuova socket
    SOCKET_T socket = socket_create();
    if(socket == 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    // connetto la socket
    if(socket_connect(socket, HOST, PORT) < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    printf("Connected!\n");

    /*
    
    GET / HTTP/1.1
    Accept: text/html
    Host: example.org

    */

    const char *stringa = "GET / HTTP/1.1\r\nHost: wikipedia.org\r\n\r\n"; //richiesta HTTP
    send(socket, stringa, strlen(stringa) + 1, 0);
    socket_close_send(socket);

    char buffer[512];
    int read = socket_read_all(socket, buffer, 511);
    printf("Ho ricevuto:\n%s\n", buffer);

    if(socket_quit(socket) != 0) {
        fprintf(stderr, "Socket finalization failed\n");
        return 1;
    }

    return 0;
}