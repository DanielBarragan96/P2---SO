#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * SHUT = "shutdown";
const char * EXIT = "exit";
const char * ECHO = "echo";

int main()
{
	printf("SH\n");
	while(1)
	{
		char command[10];
		printf("Nombre de usuario: "); 
		fgets(command,sizeof(command),stdin);
		if(strcmp(command,SHUT))
		{
			exit(4);
		}
		else if(strcmp(command,EXIT))
		{
			return 0;
		}
		else if(strcmp(command,ECHO))
		{
			//TODO echo -  kill(childpid, SIGKILL);
		}
		else
		{
			printf("error\n");
		}
	}
}
