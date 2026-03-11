#include <stdio.h>
#include <stdlib.h>

int main() {

    void *ptr = NULL;

    for(int i = 0; i < 3; i++) {

        if(!ptr) {
            ptr = malloc(10);
            printf("malloc called\n");
        }

        printf("iteration %d\n", i);

        free(ptr);
    }

    return 0;
}
