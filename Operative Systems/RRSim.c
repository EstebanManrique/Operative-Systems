/**
<Rodrigo Quiroz Reyes>:<A01026546>
<Esteban Manrique de Lara Sirvent>:<A01027077>
*/

#include <stdio.h>
#include <stdlib.h>
int count=0;

#define SLICE 4

typedef struct Processes
{
	int id;
	int remainingTime;
	struct Processes *next;
} Process;

Process *front;

Process *createProcess(int id, int remainingTime)
{
	Process *toAdd=(Process *)malloc(sizeof(Process));
	toAdd->id=id;
	toAdd->remainingTime=remainingTime;
	toAdd->next=NULL;
	return toAdd;
}
void enqueue(Process *toAdd)
{
	if(front==NULL)
    {
		front=toAdd;
	}
    else
    {
		Process *temp=front;
		while(temp->next!=NULL){
		temp=temp->next;
	}
		temp->next=toAdd;
	}
	count++;
}

Process *dequeue()
{
	Process *toReturn=front;
	front=front->next;
	count--;
	toReturn->next=NULL;
	return toReturn;
}

void printQueue()
{
	Process *temp=front;
	printf("Total:%d;", count );
	while(temp!=NULL)
    {
        printf("id:%d, rT:%d; ",temp->id, temp->remainingTime);
        temp=temp->next;
	}
	printf("\n");
}

int main()
{
    srand(time(NULL));
    Process *processCreated;
    int burst;
    int waitingTime[5] = {0,0,0,0,0};
    
    printf("Quantum of %d \n", SLICE);

    for(int i = 0; i<5; i++)
    {
        burst = rand()%30+1;
        processCreated = createProcess(i+1,burst);
        printf("Adding process %d with timing run of %d. \n", i+1, burst);
        enqueue(processCreated);
    }

    Process *temporal;
    
    temporal = front;
    
    while (count != 0)
    {
        int elimin = 0;
        int tempTime;

        printf("Running process with id %d. \n", temporal->id);
        for(int i = 0; i<SLICE; i++)
        {
            int blocking;
            blocking = rand()%100 + 1;
            if(blocking>10)
            {
                int id = (temporal->id) - 1;
                tempTime = (temporal->remainingTime) - 1;
                temporal->remainingTime = (tempTime);
                waitingTime[id]++;
                if(tempTime==0)
                {
                    printf("Process with id %d has finished execution. \n", temporal->id);
                    elimin = 1;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if(elimin==0)
        {
            printf("Process with id %d blocked for IO and was preempted with remaining time of %d. \n", temporal->id, temporal->remainingTime);
            enqueue(temporal);
            temporal = temporal->next;
            dequeue();
        }
        else
        {
            temporal = temporal->next;
            dequeue();
        }
        elimin = 0;
        
    }

    int sum = 0;
    float average = 0.f;
    for(int i=0; i<5; i++)
    {
        sum = sum + waitingTime[i];
        printf("Waiting time for process %d was %d \n", i+1, sum);
        average = sum / 5.f;
        if(i==4)
        {
            printf("Average waiting time of %0.3f seconds.\n", average);
        } 
    }

	return 0;
}