#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {

    void *ptr = malloc(16);

    if(ptr == NULL){
        printf("initial malloc failed\n");
        return 1;
    }

    printf("Initial allocation success\n");

    size_t huge = (size_t)1 << 62;

    void *newptr = realloc(ptr, huge);

    if(newptr == NULL){
        printf("realloc failed\n");
        free(ptr);
    }
    else{
        printf("realloc success\n");
        free(newptr);
    }

    return 0;
}
