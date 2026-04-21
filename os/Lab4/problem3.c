#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


sem_t wrt;
int readcount = 0;
int data = 5;


void* reader(void* arg){
    sem_wait(&wrt);
    readcount++;


    printf("Reader reads data = %d\n", data);


    readcount--;
    sem_post(&wrt);


    return NULL;
}


void* writer(void* arg){
    sem_wait(&wrt);


    data++;
    printf("Writer writes data = %d\n", data);


    sem_post(&wrt);


    return NULL;
}


int main(){
    pthread_t r1, r2, w1;


    sem_init(&wrt,0,1);


    pthread_create(&r1,NULL,reader,NULL);
    pthread_create(&r2,NULL,reader,NULL);
    pthread_create(&w1,NULL,writer,NULL);


    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);


    sem_destroy(&wrt);


    return 0;
}
