#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

char * SHUT = "shut";
char * EXIT = "exit";
char *words[25];

int comparar_string(char t1[], char t2[]);

char* concat(char s1[20], char s2[20]);

int getwords(char *line, int maxwords);

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
			//char* commandS = concat("/usr/bin/",command);
			//execlp(commandS,command,NULL);
			//execlp("/usr/bin/sh","sh","-c",NULL);
			//char *cmd = "sh";
			/*
			char* argv[3];
			argv[0]="sh";
			argv[1]=command;
			argv[2]=NULL;
			execvp(cmd,argv);
			*/
			/*
			char *cmd = "sh";
			char* argv[3];
			argv[0]="sh";
			argv[1]=command;
			argv[2]=NULL;
			execvp(cmd,argv);
			*/
			/*
			char commandDummy[] = command;
			while(commandDummy[0]!=NULL)
			{
				char* p = strtok(commandDummy," ");
				commandDummy = command;
			}
			
			char* p = strtok(commandDummy," ");
			printf("%s\n",p);
			p = strtok(command," ");
			printf("%s\n",p);
			printf("%s\n",command);
			*/
			/*
			char* string;
			int n = 0;
			while(command[n]!=NULL)
			{
				string += command[n];
				printf("%s\n",string);
				n++;
			}
			*/
			
			char* d = &command[0];
			printf("%s",d);
			popen(command,"w");
			
			/*
			char* Pcommand = &command;
			char *cmd = Pcommand;
			char *argv[3];
			argv[0] = Pcommand;
			argv[1] = "-la";
			argv[2] = NULL;
			execvp(cmd, argv);
			*/
			//execlp("sh",command,0);
			//execlp("sh","exit",0);
			//execlp("./sh","sh",NULL);
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


int getwords(char *line, int maxwords)
{
	char *p = line;
	int nwords = 0;

	while(1)
		{
		while(isspace(*p))
			p++;

		if(*p == '\0')
			return nwords;

		words[nwords++] = p;

		while(!isspace(*p) && *p != '\0')
			p++;

		if(*p == '\0')
			return nwords;

		*p++ = '\0';

		if(nwords >= maxwords)
			return nwords;
	}
}
