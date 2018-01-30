#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p;
int status;

char* concat(const char *s1, const char *s2);
int readTxtFile(char * fname);
int comparar_string(char * t1, char * t2);

int main()
{
	while(1)
	{
		printf("Nombre de usuario: ");
		char name[100]; 
  		fgets(name,sizeof(name),stdin);
		char *nameS = concat(name,(char*)':');
		printf("Contrasena: ");
		char password[100];
		scanf("%s",password);
		nameS = concat(name,password);
		printf("\n %s\n",nameS);

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
			printf("Usuario no disponible \n")
		}
	}
	return 1;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int comparar_string(char * t1, char * t2)
{
	return strcmp(t1,t2);
}

int readTxtFile(char * userinfo)
{
		char *fname = "psswd.txt";
		FILE *f = fopen(fname,"r");
		if(!f) //f==NULL
		{
			printf("\nEl archivo no existe\n");
			return 0;
		}

	char linea[256] = {};
	int contLineas =1;
	printf("\ninicio de %s\n",fname);
	while(fgets(linea,256, f))
	{
		if(comparar_string(userinfo, linea))
			return 1;
	}
	return 0;
}
