#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000000
#define POOL_SIZE 100000

__thread void* pool[POOL_SIZE];
__thread int pool_index = 0;

void* my_malloc() {

    if(pool_index > 0)
        return pool[--pool_index];

    return malloc(64);
}

void my_free(void* ptr) {

    if(pool_index < POOL_SIZE)
        pool[pool_index++] = ptr;
    else
        free(ptr);
}

void* worker(void* arg) {

    for(int i = 0; i < N; i++) {

        void* p = my_malloc();
        my_free(p);

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

    printf("Finished with %d threads (thread-local pool)\n", threads);

    return 0;
}
