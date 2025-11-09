#include <stdio.h>

int main(int argc, char *argv[]) 
{
    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] != '-')
            printf("%s\n", argv[i]);
    }
    return 0;
}
