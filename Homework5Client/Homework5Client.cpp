// Homework 5 client Application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 9876 //define the port you will use

int main(int argc, char const* argv[])
{
    char buffer[300];
    int socketfd=0;
    int newsockfd=0;
    int portnum=0;
    socklen_t clilen;
    struct sockaddr_in serv_address, cli_address;
    int num;
    
}





//https://www.geeksforgeeks.org/socket-programming-cc/
//https://www.bogotobogo.com/cplusplus/sockets_server_client.php