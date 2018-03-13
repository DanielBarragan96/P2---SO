#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

char * SHUT = "shut";
char * EXIT = "exit";

int comparar_string(char t1[], char t2[]);

char* concat(char s1[20], char s2[20]);

int main()
{
	while(1)
	{
		char command[25]; 
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
			popen(command,"w");
		}
	}
	return 0;
}

int comparar_string(char t1[], char t2[])
{
	int n=0;
    while(t2[n]!=NULL){
		if(t1[n]!=t2[n])
			return 0;
		n++;
	}
	return 1;
}	

char* concat(char s1[20], char s2[20])
{
	int n=0;
	int i=0;
    while(s1[n]!=NULL)	
	{
		n++;
	}
    while(s2[i]!=NULL)
	{
		s1[n]=s2[i];
		n++;
		i++;
	}
    return s1;
}

