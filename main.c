#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>

void main()
{
    int status;
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo("annai.cs.colorado.edu", "80", &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    int BUF_SIZE = 1024;
    unsigned char readBuffer[BUF_SIZE];

    printf("connecting status = %d\n" , connect(sockfd, res->ai_addr, res->ai_addrlen));

    int nBytesReceived = recv(sockfd, readBuffer, BUF_SIZE, 0);
    if (nBytesReceived == -1)
    {
        perror("recv");
        return 0;
    }
    printf("Receiving signal status = %d bytes received \n\n", nBytesReceived);

    
    int i;
    printf("first char = %c\n" , ntohl(readBuffer[0]));
//    for(i = 0; i < 4; i++)
//    {
 //       printf("i = %d\n", i);
        //char correctEndian = ntohl(readBuffer[i]);
 //       printf("%s\n", readBuffer[i]);
        //send(sockfd, 
//    }
//    freeaddrinfo(res); // free the linked-list

}
    
	
