#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;        // Semaphore for mutual exclusion
sem_t writeblock;   // Blocks writers
int data = 0;       // Shared data
int readcount = 0;  // Number of readers

void *reader(void *arg)
{
    int f = ((int)arg);

    sem_wait(&mutex);
    readcount++;
    if(readcount == 1)
        sem_wait(&writeblock); // First reader locks writer
    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", f, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if(readcount == 0)
        sem_post(&writeblock); // Last reader releases writer
    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    int f = ((int)arg);

    sem_wait(&writeblock); // Writer locks

    data++;
    printf("Writer %d modified data to %d\n", f, data);
    sleep(1);

    sem_post(&writeblock); // Writer unlocks
    return NULL;
}

int main()
{
    pthread_t r[5], w[5];
    int i;

    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);

    for(i = 0; i < 5; i++)
    {
        pthread_create(&w[i], NULL, writer, (void*)i);
        pthread_create(&r[i], NULL, reader, (void*)i);
    }

    for(i = 0; i < 5; i++)
    {
        pthread_join(w[i], NULL);
        pthread_join(r[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&writeblock);

    return 0;
}