#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hello, world!\n");
    fork();
    return 0;
}
