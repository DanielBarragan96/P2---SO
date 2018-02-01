#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int p;
int status;

char* concat(char s1[], char s2[]);
int readTxtFile(char * fname);
int comparar_string(char t1[], char t2[]);

char name[20];
char password [20]; 
char* nameS;

int main()
{
	while(1)
	{
		printf("Nombre de usuario: ");
		scanf("%s",name);
		char puntos[]={":"};
		nameS = concat(name,puntos);
		printf("Contrasena: ");
		scanf("%s",password);
		nameS = concat(name,password);
		printf("\n%s\n",nameS);

	 	if(readTxtFile(nameS))
		{
			p = fork();
			if(!p)
			{
				execlp("Desktop/sh","sh",NULL);
			}
			else
				wait(&status);
		}
		else
		{
			printf("Usuario no disponible \n");
		}
	}
	return 1;
}

char* concat(char s1[20], char s2[20])
{
	int n=0;
	int i=0;
    while(s1[n]!=NULL){
	n++;
	}
    while(s2[i]!=NULL){
	s1[n]=s2[i];
	n++;
	i++;
	}
	printf("%d",n);
    return s1;
}

int comparar_string(char t1[], char t2[])
{
	/*int x=strcmp(t1,t2);
	printf("%d\n",x);*/
	int n=0;
    while(t1[n]!=NULL){
	if(t1[n]!=t2[n])
		return 1;
	n++;
	}
	return 0;
}

int readTxtFile(char * userinfo)
{
		char *fname = "passwd.txt";
		FILE *f = fopen(fname,"r");
		if(!f) //f==NULL
		{
			printf("\nEl archivo no existe\n");
			return 0;
		}
	char linea[256] = {};
	int contLineas =1;
	printf("\ninicio de %s\n",fname);
	int x;
	while(fgets(linea,256, f))
	{
		x = comparar_string(userinfo, linea);		
		printf("%s%d\n",linea,x);
		if(x)
			return 1;
	}
	return 0;
}
