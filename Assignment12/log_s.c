#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096 /*max text line length*/
#define LISTENQ 8 /*maximum number of client connections */
#define SERV_PORT 3001 /*the port we use to write our logs file*/

int main (int argc, char **argv)
{
//define variables 
int listen_socket; 
int connection;
int n;
socklen_t client_length;
char buffer[MAXLINE];
struct sockaddr_in client_addr;
struct sockaddr_in server_addr;
File *logs; 
time_t currenttime;
struct tm * timeinfo;
int client_ip = argv[1]; 

 //create listen socket 
listen_socket = socket (AF_INET, SOCK_STREAM, 0);


//preparation of the socket addresses
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(SERV_PORT);

//bind listening sockets 
bind (listen_socket, (struct sockaddr *) &(server_addr[i]), sizeof(server_addr));


//listen on each socket for each port number 
listen (listen_socket, LISTENQ);

//infinite loop while listening 
while(1){

  client_length = sizeof(client_addr);

 
  connection = accept (listen_socket, (struct sockaddr *) &client_addr, &client_length);
  printf("%s\n", "Writing in logs..." );

  logs = fopen("echo.log", "a");
  while ( (n = recv(connection, buffer, MAXLINE,0)) > 0)  {
   time ( &currenttime );
   timeinfo = localtime ( &currenttime );
   fprintf(logs, "%s %s %s %d", asctime (timeinfo), buffer, " was recieved from ", client_ip);
  }

  if (n < 0) {
  perror("Read error");
  exit(1);
 }
 close(logs);
 close(connection);

 }
 //close listening socket
 for(int i = 0; i < portNum; i++){
 close (listen_socket[i]);
}
}