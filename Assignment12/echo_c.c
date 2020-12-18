#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define MAXLINE 4096 /*max text line length*/
main(int argc, char **argv)
{

 //checks that a port number was provided 
 if (argc !=3) {
  printf("[ERROR] Please provide a port number to send from.");
  return 1; 
 }

 int socket_client;
 struct sockaddr_in server_addr;
 char sendline[MAXLINE], recvline[MAXLINE];
 int SERV_PORT = atoi(argv[2]); 

 //Create a socket for the client
 //If sockfd<0 there was an error in the creation of the socket
 if ((socket_client = socket (AF_INET, SOCK_STREAM, 0)) <0) {
  perror("Problem in creating the socket");
  exit(2);
 }

 //Creation of the socket
 memset(&server_addr, 0, sizeof(server_addr));
 server_addr.sin_family = AF_INET;
 server_addr.sin_addr.s_addr= inet_addr(argv[1]);
 server_addr.sin_port =  htons(SERV_PORT); //convert to big-endian order

 //Connection of the client to the socket
 if (connect(socket_client, (struct sockaddr *) &server_addr, sizeof(server_addr))<0) {
  perror("Problem in connecting to the server");
  exit(3);
 }

 while (fgets(sendline, MAXLINE, stdin) != NULL) {

  send(socket_client, sendline, strlen(sendline), 0);

  if (recv(socket_client, recvline, MAXLINE,0) == 0){
   //error: server terminated prematurely
   perror("The server terminated prematurely");
   exit(4);
  }
  printf("%s", "String received from the server: ");
  fputs(recvline, stdout);
 }

 exit(0);
}