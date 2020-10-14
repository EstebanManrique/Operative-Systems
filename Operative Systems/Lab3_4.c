/*
Andrés Barragán Salas			A01026567
Rodrigo Quiroz Reyes			A01026546
Esteban Manrique de Lara Sirvent	A01027077
Luis Emilio Alcántara Guzmán		A01027304 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handler1(int sig)
{
    if(sig == SIGINT)
    {
        printf("Son has received SIGNIT \n");
        fflush(stdout);
    }
    else if(sig == SIGUSR1)
    {
        printf("Son has received SIGUSR1 \n");
        fflush(stdout);
    }
    else if(sig == SIGUSR2)
    {
        printf("Son has received SIGUSR2 \n");
        fflush(stdout);
    }
    else
    {
        printf("Process ended \n");
        fflush(stdout);
    }     
}

void handler2(int sig)
{
    if(sig == SIGINT)
    {
        printf("Parent has Received SIGNIT \n");
        fflush(stdout);
    }
}
int main()
{
    pid_t ownPID=fork();

    if(ownPID==0)
    {
        signal(SIGINT, handler1);
        signal(SIGUSR1, handler1);
        signal(SIGUSR2, handler1);
        while(1);
    }
    else
    {
        while(1)
        {
            signal(SIGINT, handler2);
            printf("Señal: \n");
            char input[1];
	        fgets(input, 10, stdin);

            char* pch=strchr(input,'1');
            char* pch2=strchr(input,'2');
            char* pch3=strchr(input,'3');
            if(pch!=NULL)
            {
                kill(ownPID, SIGINT);
                printf("Parent has sent SIGNIT \n");
                fflush(stdout);
                sleep(1);
            }
            else if(pch2!=NULL)
            {
                kill(ownPID, SIGUSR1);
                printf("Parent has sent SIGUSR1 \n");
                fflush(stdout);
                sleep(1);
            }
            else if(pch3!=NULL)
            {
                kill(ownPID, SIGUSR2);
                printf("Parent has sent SIGUSR2 \n");
                fflush(stdout);
                sleep(1);
            }
            else
            {
                exit(0);
            }
        }
    }
}