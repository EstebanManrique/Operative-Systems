/**
<Rodrigo Quiroz Reyes>:<A01026546>
<Esteban Manrique de Lara Sirvent>:<A01027077>
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <pthread.h>

#define A 3
#define B 2
#define C 3

int array1 [A][B] = {{1,4}, {2,5}, {3,6}};
int array2 [B][C] = {{8,7,6},{5,4,3}};
int result [A][C];
pthread_t threads [A][C];

struct threadData
{
    int x;
    int y;
};

void *arithmethicOperations(void *args)
{
    struct threadData* data = (struct threadData*)args;
    int i = 0;
    int resultSpace = 0;

    for(i; i<B; i++)
    {
        resultSpace = resultSpace + array1[data->x][i] * array2[i][data->y];
    }

    result[data->x][data->y] = resultSpace;

}

int main()
{
    for(int i = 0; i<A; i++)
    {
        for(int j = 0; j<C; j++)
        {
            struct threadData* data = (struct threadData*) malloc(sizeof(struct threadData*));
            data->x = i;
            data->y = j;  
            pthread_create(&threads[i][j], NULL, &arithmethicOperations, (void*)data);
        }
    }

    sleep(1);

    printf("Resultant Matrix");
    for(int i = 0; i<A; i++)
    {
        printf("\n");
        for(int j = 0; j<C; j++)
        {
            printf("%d\t", result[i][j]);
        }
    }

    printf("\n");
    printf("Threads addresses");
    sleep(2);

    for(int i = 0; i<A; i++)
    {
        printf("\n");
        for(int j = 0; j<C; j++)
        {
            printf("%d\t", threads[i][j]);
            pthread_join(threads[i][j], NULL);
        }
    }
    return 1;  
}