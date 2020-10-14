#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct order
{
    long mtype;
    char mtext[50];
};

int main()
{
    key_t key = ftok("Users/Esteban Manrique/Documents/Operative Systems/SupportFile.txt",60);
    int queue = msgget(key, 0666|IPC_CREAT);
    struct order o;
    msgrcv(queue, &o, sizeof(o), 1, IPC_NOWAIT);
    printf("Recibido: %s\n", o.mtext);
}