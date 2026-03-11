#include <stdio.h>
#include <stdlib.h>

int main() {

    void *ptr = malloc(0);

    if(ptr == NULL)
        printf("NULL returned\n");
    else {
        printf("Pointer returned: %p\n", ptr);
        free(ptr);
    }

    return 0;
}
