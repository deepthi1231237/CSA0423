#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t1, t2;

void* run1() {
    printf("Thread1 running\n");
    pthread_exit(NULL);
}

void* run2() {
    printf("Thread2 running\n");

    if (pthread_equal(t1, pthread_self()))
        printf("This is Thread1\n");
    else
        printf("This is not Thread1\n");

    pthread_exit(NULL);
}

int main() {
    pthread_create(&t1, NULL, run1, NULL);
    pthread_create(&t2, NULL, run2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread done\n");
    return 0;
}