                     // file: onepipe.cpp
// author: M. Amine Belkoura
// date: 03/04/2020
// purpose: CS3377
// description:
// this program executes "ls -ltr | grep 3376", by dividing the two commands among the child and parent process
#include <stdio.h>
#include <iostream> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;  

int main(int argc, char **argv){ 
	
	//check arguement count
	//no more than 5 arguments, remember that arv[0] = file name 
	// argv = 5 argument + file name = argc cannot exceed 6
	if(argc > 6){ 
		perror("No more than 5 arguments");
		 exit(1);
	}
	
	//no less than 2 arguments, remember that arv[0] = file name 
	//argv = 2 arguments + file name = arc cannot fall under 3
	if(argc < 3){ 
		perror("No less than 2 arguments");
		exit(1);
	}

	//provided variables
	int status;
	int childpid; 

	//prepare to store arguments entered in command line 
	// like *cat_args = [ls, -ltr, NULL]; 
	char *parameter_args[3]; 

	//prepare communal pipe
	int pipes[2]; 

	//prepare variable to store previous pipe output 
	int output; 
	int maxArgs = 3; 

	//specify index for the last command in argv[]
	int endCommand = argc - 1; 

	//loop through argv, start at index 1 since argv[0] = file name 
	for(int index = 1; index < argc; index++){

		//create the current pipe 
		pipe(pipes); 

		// fork the current child (to execute current command)
		if((childpid = fork()) == -1){
			 perror("Error creating a child process");
			 exit(1);
		}	

		//check if child executable 
		if(childpid == 0){

			//close the previous pipe 
			dup2(output, 0);
			close(output);
			
			//connect every pipes outputs (except for the last command) 
			if(index != endCommand){
				dup2(pipes[1], 1); 
			}

			//close pipes after dup2
			close(pipes[0]);
			close(pipes[1]); 
			
			//record the command in the argument line of first array slot 
			//strtok divides string (argv[index]) into segments using spaces in between 
			parameter_args[0] = strtok(argv[index], " ");
			
			//fill the rest of the array slots with parameters if present 
			//each parameter will be filled with a space between arv[index] string 
			for(int index2 = 1; index2 < maxArgs; index2++){
				parameter_args[index2] = strtok(NULL, " ");
			} 
			
			//execute the command parameters 
			execvp(*parameter_args, parameter_args);
			
			//end current loop 
			exit(0); 

		}

		//keeps track of the previous pipe's output 
		output = pipes[0];

		//close current pipe output 
		close(pipes[1]); 
	
	}

	return(0);


}
