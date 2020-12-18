//Just a warning, I started off using the code provided during the video lectures
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 4096 /*max text line length*/
#define LISTENQ 8 /*maximum number of client connections */

int main (int argc, char **argv){

  //check for at least one argument
  if(argc < 2){
    printf("%s \n", "[ERROR] Must provide a port number." );
    return 1;
  }

  //check that args are less than 3
  if(argc > 4){
    printf("%s \n", "[ERROR] That's too many ports! Please only provide a max of 3 ports." );
    return 1;
  }

  //define variables
  int portNum = argc - 1; 
  int listen_socket[portNum]; 
  int connection;
  int n;
  socklen_t client_length;
  char buffer[MAXLINE];
  struct sockaddr_in client_addr;
  struct sockaddr_in server_addr[portNum];
  struct sockaddr_in log_addr;
  int SERV_PORT[portNum]; 
  int LOG_PORT = 3001; 
  int socket_client;  

  //collect server ports 
  for(int i = 0; i < portNum; i++){
    SERV_PORT[i] = atoi(argv[i + 1]);
  }

  //create socket for each port argument 
  for(int i = 0; i < portNum; i++){
    listen_socket[i] = socket (AF_INET, SOCK_STREAM, 0);
  }

  //preparation of the socket addresses
  for(int i = 0; i < portNum; i++){
    server_addr[i].sin_family = AF_INET;
    server_addr[i].sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr[i].sin_port = htons(SERV_PORT[i]);
  }

  //bind listening sockets 
  for(int i = 0; i < portNum; i++){
    bind (listen_socket[i], (struct sockaddr *) &(server_addr[i]), sizeof(server_addr[i]));
  }

  //listen on each socket for each port number 
  for(int i = 0; i < portNum; i++){
    listen (listen_socket[i], LISTENQ);
  }
 
  printf("%s\n","Server running...waiting for connections.");

  //infinite loop while listening 
  while(1){

    client_length = sizeof(client_addr);

    for(int i = 0; i < portNum; i++){
      connection = accept (listen_socket[i], (struct sockaddr *) &client_addr, &client_length);
    }

    printf("%s\n","Received request...");

    socket_client = socket (AF_INET, SOCK_STREAM, 0);
    memset(&log_addr, 0, sizeof(log_addr));
    log_addr.sin_family = AF_INET;
    log_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    log_addr.sin_port =  htons(LOG_PORT);
    connect(socket_client, (struct sockaddr *) &log_addr, sizeof(log_addr));

    while ( (n = recv(connection, buffer, MAXLINE,0)) > 0)  {
     printf("%s","String received from and resent to the client:");
     puts(buffer);
     send(socket_client, buffer, strlen(buffer), 0);
     send(connection, buffer, n, 0);
    }
  }

    if (n < 0) {
    perror("Read error");
    exit(1);
   }

   close(connection);

   
   //close listening socket
   for(int i = 0; i < portNum; i++){
   close (listen_socket[i]);
  }

}