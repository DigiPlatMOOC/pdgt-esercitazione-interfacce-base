#include <stdio.h>
#include "socket-lib.h"

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

    const char *stringa = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    send(socket,stringa,strlen(stringa) + 1,0);
    
    char buffer[1024];
    int read = socket_read_all(socket,buffer,1023);
    printf("Ho ricevuto:\n%s\n",buffer);
    
    if(socket_quit(socket) != 0)
    {
    	fprintf(stderr, "Socket finalization failed\n");
    	return 1;
    }   
     return 0;
}
