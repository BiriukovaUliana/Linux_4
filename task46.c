#include <stdio.h>
#include <stdlib.h>

int main(){

    void *ptr;

    ptr = realloc(NULL, 100);

    if(ptr == NULL){
        printf("realloc(NULL,100) failed\n");
        return 1;
    }

    printf("realloc(NULL,100) works like malloc\n");

    ptr = realloc(ptr, 0);

    printf("realloc(ptr,0) frees memory\n");

    return 0;
}
