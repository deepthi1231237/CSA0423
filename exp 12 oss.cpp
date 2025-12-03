#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t chopstick[5];

void* philosopher(void* n) {
    int i = *(int*)n;
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i+1)%5]);

    printf("Philosopher %d is eating.\n", i);

    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i+1)%5]);
    return NULL;
}

int main() {
    pthread_t p[5];
    int i, id[5];

    for (i=0;i<5;i++) sem_init(&chopstick[i],0,1);

    for (i=0;i<5;i++){
        id[i]=i;
        pthread_create(&p[i],NULL,philosopher,&id[i]);
    }

    for (i=0;i<5;i++) pthread_join(p[i],NULL);

    return 0;
}
