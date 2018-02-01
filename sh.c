#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * SHUT = "shut";
char * EXIT = "exit";

int comparar_string(char t1[], char t2[]);

int main()
{
	printf("SH\n");
	while(1)
	{
		char command[4]; 
		fgets(command,sizeof(command),stdin);
		if(comparar_string(command,SHUT))
		{
			return 2;
		}
		else if(comparar_string(command,EXIT))
		{
			return 0;
		}
		else
		{
			printf("error\n");
		}
	}
	return 0;
}

int comparar_string(char t1[], char t2[])
{
	int n=0;
    while(t1[n]!=NULL){
		if(t1[n]!=t2[n])
			return 0;
		n++;
	}
	return 1;
}

