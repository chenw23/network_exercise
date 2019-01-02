#include "csapp.h"

void client_read(int serverfd) {
    rio_t rio;
    char buf[MAXBUF];
    int n, len;
    Rio_readinitb(&rio, serverfd);
    while (Rio_readlineb(&rio, buf, MAXBUF) > 0) {
        if (sscanf(buf, "Content-Length: %d", &len) > 0) {
            n = Rio_readn(serverfd, buf, len);
            buf[n] = '\0';
            printf("Client received data: '%s'\n", buf);
        } else {
            printf("Couldn't determine content length\n");
        }
    }
}

int main() {
    int serverfd = Open_clientfd("127.0.0.1", "2333");
    client_read(serverfd);
}
