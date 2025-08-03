#include <stdio.h>
#include <pthread.h>

int counter = 0;  // Shared variable

void* increment(void* arg) {
    int val = counter;
    val = val + 1;
    counter = val;

    printf("Thread %ld incremented counter to %d\n", (long)pthread_self(), counter);
    return NULL;
}

int main() {
    pthread_t threads[3];

    // Create 3 threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", counter);
    return 0;
}