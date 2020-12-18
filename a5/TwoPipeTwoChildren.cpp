// file: onepipe.cpp
// author: M. Amine Belkoura
// date: 03/04/2020
// purpose: CS3377
// description:
// this program executes "ls -ltr | grep 3376", by dividing the two commands among the child and parent process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv){

	int status;
	int ls_to_grep_childpid;
	int grep_to_wc_childpid;
	char *cat_args[] = {"ls", "-ltr", NULL};
	char *grep_args[] = {"grep", "3376", NULL};
	char *wc_args[] = {"wc", "-l", NULL}; //add the new arguments for the double pipe command 

	// create one pipe to send the output of "ls" process to "grep" process
	int ls_to_grep_pipes[2];

	//create another pipe to send "grep" output to "wc" 
	int grep_to_wc_pipes[2];
	
	//use pipe command to create the pipes 
	pipe(ls_to_grep_pipes);
	pipe(grep_to_wc_pipes);


	// fork the first child (to execute cat)
	if((ls_to_grep_childpid = fork()) == -1){
		 perror("Error creating a child process");
		 exit(1);
	}

	// fork the second child (to execute grep)
	if((grep_to_wc_childpid = fork()) == -1){
		 perror("Error creating a child process");
		 exit(1);
	}

	//run the grep child first
	if (grep_to_wc_childpid == 0) {
		// passes ls output into grep input 
		//pipe 1 -> pipe 2 
		 dup2(grep_to_wc_pipes[0], 0);
		 dup2(ls_to_grep_pipes[1], 1); 
		
		 //close pipes
		 close(ls_to_grep_pipes[0]);
		 close(ls_to_grep_pipes[1]);
		 close(grep_to_wc_pipes[0]);
		 close(grep_to_wc_pipes[1]);


		 //execute grep 
		 execvp(*grep_args, grep_args);

		 //end 
		 exit(0);
	
	//execute ls as grep child is in process
	//when grep needs input, ls will complete and provide them
	} else if (ls_to_grep_childpid == 0) {
		//empty first pipe, pass ls to grep in second pipe 
		 dup2(grep_to_wc_pipes[1], 1);
		
		 //close pipes
		 close(grep_to_wc_pipes[1]);
		 close(grep_to_wc_pipes[0]);
		 close(ls_to_grep_pipes[0]);
		 close(ls_to_grep_pipes[1]);

		 //execute cat 
		 execvp(*cat_args, cat_args);

		 //end 
		 exit(0);

	//all children piped, execute wc and end program 
	}else {
		
		//empty second pipe 
		 dup2(ls_to_grep_pipes[0], 0);

		 //close pipes
		 close(ls_to_grep_pipes[0]);
		 close(ls_to_grep_pipes[1]);
		 close(grep_to_wc_pipes[0]);
		 close(grep_to_wc_pipes[1]);
		
		 //execute wc arguments 
		 execvp(*wc_args, wc_args);
	}

	return(0);

}
