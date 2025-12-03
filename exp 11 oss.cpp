#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    printf("Thread is running!\n");
    return NULL;
}

int main() {
    pthread_t t1;
    pthread_create(&t1, NULL, task, NULL);
    pthread_join(t1, NULL);
    return 0;
}
