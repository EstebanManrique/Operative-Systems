#include <stdio.h>   
#include <stdlib.h> 
#include <string.h> 
#include <pthread.h>

#define SIZEA 100
#define NHILOS 4;
typedef struct
{
    int id;
    int inicio; 
    int fin;
}tdata;


int arreglo [SIZEA];
int suma = 0;

void* sumaElementos(void * param)
{
    for(int i = 0; i<SIZEA; i++)
    {
        suma = arreglo[i] + suma;
    }
    //return suma;
}

int main()
{
    int arreglo [SIZEA];
    int hiloscant = NHILOS
    int hilos = SIZEA/NHILOS;
    pthread_t hilosA [hilos];
    
    for(int i = 0; i<SIZEA; i++)
    {
        arreglo[i] = i+1;
        printf("%d \n", arreglo[i]);
    }

    for(int i = 0; i < hiloscant; i++)
    {
        int inicio = i*hilos;
        int final;
        if(i==hiloscant-1)
        {
            final = inicio+hilos;
        }
        else
        {
            final = inicio + hilos;
        }

        tdata temp = {i,inicio, final};

        tdata * pdid = (tdata *)malloc(sizeof(tdata));
        memcpy(pdid, &temp, sizeof(tdata));
        pthread_t result = pthread_create(&hilosA[i],NULL,suma,&temp);

        printf(" Hilo con inicio %d, final %d e id %d \n", i, temp.inicio+1, temp.fin);

    }

    //printf("La suma de los elementos del arreglo es de %d", sumaElementos(arreglo));
    return 0;

}