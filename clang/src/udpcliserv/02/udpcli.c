#include "unp.h"

int main(int argc, char const *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    if(argc != 2)
        err_sys("usage: ./udpcli <IP Address>");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_UDP_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    dg_cli(stdin, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    return 0;
}
