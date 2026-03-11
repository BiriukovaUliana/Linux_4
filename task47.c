#include <stdio.h>
#include <stdlib.h>

struct sbar{
    int x;
    int y;
};

int main(){

    struct sbar *ptr;
    struct sbar *newptr;

    ptr = calloc(1000, sizeof(struct sbar));

    if(ptr == NULL){
        printf("calloc failed\n");
        return 1;
    }

    printf("calloc success\n");

    newptr = reallocarray(ptr, 500, sizeof(struct sbar));

    if(newptr == NULL){
        printf("reallocarray failed\n");
        free(ptr);
    }
    else{
        printf("reallocarray success\n");
        free(newptr);
    }

    return 0;
}

