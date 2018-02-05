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

int main()
{
	while(1)
	{
        char name[20] = "";
        char password [20] = ""; 
        char* nameS = "";

		printf("Nombre de usuario: ");
		scanf("%s",name);
		char puntos[]={":"};
		nameS = concat(name,puntos);
		printf("Contrasena: ");
		scanf("%s",password);
		nameS = concat(nameS,password);
		//printf("%s\n",nameS);

	 	if(readTxtFile(nameS))
		{
			p = fork();
			if(!p)
			{				
                execlp("./sh","sh",NULL);
			}
			else
				wait(&status);
				status = status >> 8;
				if(2 == status)
				{
					return 0;
				}
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
	int x;
	while(fgets(linea,256, f))
	{
		x = comparar_string(userinfo, linea);
        //printf("%s \n",linea);
        //printf("%d \n--------\n", x);
		if(x)
			return 1;
	}
	return 0;
}
