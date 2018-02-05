#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int p [6];
int status;
static int shut = 0;

int searchDeadChild();
int shutChild();

int main()
{
        int pipefd[2];
        pipe(pipefd);
		p[0] = fork();
		if(!p[0])//hijo uno
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
		p[1] = fork();
		if(!p[1])//hijo dos
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
		p[2] = fork();
		if(!p[2])//hijo tres
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
		p[3] = fork();
		if(!p[3])//hijo cuatro
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
		p[4] = fork();
		if(!p[4])//hijo cinco
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
		p[5] = fork();
		if(!p[5])//hijo seis
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
        printf("Procesos: \n %d \n",p[0]);
        printf("%d \n",p[1]);
        printf("%d \n",p[2]);
        printf("%d \n",p[3]);
        printf("%d \n",p[4]);
        printf("%d \n",p[5]);

	while(1)
	{
		wait(&status);
		if(1 == shut)
		{
			kill(p[0], SIGKILL);
            kill(p[1], SIGKILL);
            kill(p[2], SIGKILL);
            kill(p[3], SIGKILL);
            kill(p[4], SIGKILL);
            kill(p[5], SIGKILL);

			return 1;
		}
        else
        {
            int deadChild = searchDeadChild();
            //printf("Dead Child: %d\n",deadChild);
            //printf("Process: %d Killed\n", p[deadChild]);
		    p[deadChild] = fork();
		    if(!p[deadChild])//hijo uno
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
    printf("-------------\n");

    for(int i = 0; i<6; i++)
    {
        if(-1 == getpgid(p[i]))
        {
            return i;
        }
    }
    return 6;
}

int shutChild()
{
    shut = 1;
}

