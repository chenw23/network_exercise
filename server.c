#include "csapp.h"

void server_session(int clientfd);

int main() {
    int listenfd = Open_listenfd("2333");
    int fd = Accept(listenfd, NULL, NULL);
    server_session(fd);
    return 0;
}

void server_write(int clientfd, char *data, int len) {
    char buf[MAXBUF];
    sprintf(buf, "Content-Length: %d\n%s", len, data);
    Rio_writen(clientfd, buf, strlen(buf));
}

void server_session(int clientfd) {
    char *words[2] = {"Hello", "World!"};
    int i;
    for (i = 0; i < 2; ++i) {
        server_write(clientfd, words[i], strlen(words[i]));
        sleep(1);
    }
}