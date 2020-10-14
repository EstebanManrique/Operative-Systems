#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int Zombie()
{
    pid_t created=fork();
	pid_t ownPID=getpid();
    if(created==0)
    {//CHILD
			printf("This is the child of a Zombie process\n");

	}
    else
    {//PARENT
		sleep(3);
        char *args[]={"/bin/ps", NULL};
	    execv(args[0], args);
		wait(NULL);
		printf("My pid is %d, and my child is %d\n", ownPID, created);
	}
	return 0;
}

int Suspended()
{
    pid_t created=fork();
	pid_t ownPID=getpid();
    if(created==0)
    {//CHILD
			getchar();
            
	}
    else
    {//PARENT
        char *args[]={"/bin/ps", NULL};
	    execv(args[0], args);
		printf("My pid is %d, and my child is %d\n", ownPID, created);
	}
	return 0;
}

int Terminated()
{
    pid_t created=fork();
	pid_t ownPID=getpid();
    if(created==0)
    {//CHILD
			printf("This is the child of a Terminated process\n");

	}
    else
    {//PARENT
		sleep(3);
        wait(NULL);
        char *args[]={"/bin/ps", NULL};
	    execv(args[0], args);
		printf("My pid is %d, and my child is %d\n", ownPID, created);
	}
	return 0;
}

int main()
{
    //Zombie();
    //Terminated();
    Suspended();
	return 0;
}