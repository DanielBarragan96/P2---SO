#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int p [6];
int status;

int searchDeadChild();
int shutChild();

void my_handler()
{//https://stackoverflow.com/questions/6168636/how-to-trigger-sigusr1-and-sigusr2
        printf("Received SIGUSR1!\n");
        kill(p[0], SIGKILL);
        kill(p[1], SIGKILL);
        kill(p[2], SIGKILL);
        kill(p[3], SIGKILL);
        kill(p[4], SIGKILL);
        kill(p[5], SIGKILL);
        exit(0);
}

int main()
{
        signal(SIGUSR1, my_handler);

		p[0] = fork();
		if(!p[0])//hijo uno
		{	
            char father[10];
            sprintf(father,"%d",getppid());
			execlp("/usr/bin/xterm","xterm","-e","./getty",father,NULL);
		}
        p[1] = fork();
		if(!p[1])//hijo dos
		{	
            char father[10];
            sprintf(father,"%d",getppid());
			execlp("/usr/bin/xterm","xterm","-e","./getty",father,NULL);
		}
		p[2] = fork();
		if(!p[2])//hijo tres
		{	
            char father[10];
            sprintf(father,"%d",getppid());
			execlp("/usr/bin/xterm","xterm","-e","./getty",father,NULL);
		}
		p[3] = fork();
		if(!p[3])//hijo cuatro
		{	
            char father[10];
            sprintf(father,"%d",getppid());
			execlp("/usr/bin/xterm","xterm","-e","./getty",father,NULL);
		}
		p[4] = fork();
		if(!p[4])//hijo cinco
		{	
            char father[10];
            sprintf(father,"%d",getppid());
			execlp("/usr/bin/xterm","xterm","-e","./getty",father,NULL);
		}
		p[5] = fork();
		if(!p[5])//hijo seis
		{	
            char father[10];
            sprintf(father,"%d",getppid());
			execlp("/usr/bin/xterm","xterm","-e","./getty",father,NULL);
        }
		
        printf("Procesos: \n");
        printf("    %d \n",p[0]);
        printf("    %d \n",p[1]);
        printf("    %d \n",p[2]);
        printf("    %d \n",p[3]);
        printf("    %d \n",p[4]);
        printf("    %d \n",p[5]);

	while(1)
	{
		wait(&status);
        else
        {
            int deadChild = searchDeadChild();
		    p[deadChild] = fork();
		    if(!p[deadChild])
		    {	
			    execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		    }
        }
	}
	return 0;
}

int searchDeadChild()
{
    printf("pid: %d : %d \n",p[0], getpgid(p[0]));
    printf("pid: %d : %d \n",p[1], getpgid(p[1]));
    printf("pid: %d : %d \n",p[2], getpgid(p[2]));
    printf("pid: %d : %d \n",p[3], getpgid(p[3]));
    printf("pid: %d : %d \n",p[4], getpgid(p[4]));
    printf("pid: %d : %d \n",p[5], getpgid(p[5]));
    printf("-------------Current process\n");

    for(int i = 0; i<6; i++)
    {
        if(-1 == getpgid(p[i]))
        {
            return i;
        }
    }
    return 6;
}

