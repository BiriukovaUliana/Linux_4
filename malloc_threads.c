#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000000

void* worker(void* arg) {

    for(int i = 0; i < N; i++) {
        void* p = malloc(64);
        free(p);
    }

    return NULL;
}

int main(int argc, char* argv[]) {

    int threads = atoi(argv[1]);

    pthread_t t[threads];

    for(int i = 0; i < threads; i++)
        pthread_create(&t[i], NULL, worker, NULL);

    for(int i = 0; i < threads; i++)
        pthread_join(t[i], NULL);

    printf("Finished with %d threads\n", threads);

    return 0;
}
