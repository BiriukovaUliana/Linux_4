#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
size_t size = (size_t)1 << 62;
void *ptr = malloc(size);
if(ptr == NULL)
printf("malloc failed\n");
else {
printf("malloc success\n");
free(ptr);
}
return 0;
}
