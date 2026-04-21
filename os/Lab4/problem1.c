#include <stdio.h>
#include <pthread.h>

void* msg1(void* arg){
    printf("Thread 1: Hello from thread 1\n");
    return NULL;
}

void* msg2(void* arg){
    printf("Thread 2: Hello from thread 2\n");
    return NULL;
}

void* msg3(void* arg){
    printf("Thread 3: Hello from thread 3\n");
    return NULL;
}

int main(){
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, msg1, NULL);
    pthread_create(&t2, NULL, msg2, NULL);
    pthread_create(&t3, NULL, msg3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
