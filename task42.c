#include <stdio.h>
#include <stdlib.h>

int main() {

    int x = -100;

    size_t size = x * x;

    void *ptr = malloc(size);

    printf("size = %zu\n", size);

    if(ptr == NULL)
        printf("malloc failed\n");
    else {
        printf("malloc success\n");
        free(ptr);
    }

    return 0;
}
