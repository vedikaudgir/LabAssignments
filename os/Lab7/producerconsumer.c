#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define bufferSize 5

int buffer[bufferSize];
int inIndex = 0;
int outIndex = 0;

sem_t emptySlots;
sem_t fullSlots;
sem_t mutexLock;

void *producerFunction(void *arg)
{
    int producedItem;

    for (int i = 0; i < 10; i++)
    {
        producedItem = rand() % 100;

        sem_wait(&emptySlots);
        sem_wait(&mutexLock);

        buffer[inIndex] = producedItem;
        printf("Produced %d at %d\n", producedItem, inIndex);
        inIndex = (inIndex + 1) % bufferSize;

        sem_post(&mutexLock);
        sem_post(&fullSlots);

        sleep(1);
    }
}

void *consumerFunction(void *arg)
{
    int consumedItem;

    for (int i = 0; i < 10; i++)
    {
        sem_wait(&fullSlots);
        sem_wait(&mutexLock);

        consumedItem = buffer[outIndex];
        printf("Consumed %d from %d\n", consumedItem, outIndex);
        outIndex = (outIndex + 1) % bufferSize;

        sem_post(&mutexLock);
        sem_post(&emptySlots);

        sleep(1);
    }
}

int main()
{
    pthread_t producerThread;
    pthread_t consumerThread;

    sem_init(&emptySlots, 0, bufferSize);
    sem_init(&fullSlots, 0, 0);
    sem_init(&mutexLock, 0, 1);

    pthread_create(&producerThread, NULL, producerFunction, NULL);
    pthread_create(&consumerThread, NULL, consumerFunction, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    sem_destroy(&mutexLock);

    return 0;
}