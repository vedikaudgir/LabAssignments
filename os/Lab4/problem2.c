#include <stdio.h>
#include <pthread.h>


void* square(void* arg){
    int num = *(int*)arg;
    printf("Square of %d = %d\n", num, num*num);
    return NULL;
}


int main(){
    pthread_t t;
    int n;


    printf("Enter number: ");
    scanf("%d", &n);


    pthread_create(&t, NULL, square, &n);
    pthread_join(t, NULL);


    return 0;
}
