#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Current user ID: %d\n", getuid());
    printf("Effective user ID: %d\n", geteuid());
    return 0;
}

