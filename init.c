#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int p;
int status;

int main()
{
p = fork();
		if(!p)//hijo uno
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
p = fork();
		if(!p)//hijo dos
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
p = fork();
		if(!p)//hijo tres
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
p = fork();
		if(!p)//hijo cuatro
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
p = fork();
		if(!p)//hijo cinco
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
p = fork();
		if(!p)//hijo seis
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}

	while(1)
	{
		wait(&status);
		p = fork();
		if(!p)//hijo uno
		{	
			execlp("/usr/bin/xterm","xterm","-e","./getty",NULL);
		}
	}
	return 0;
}
