#include <stdio.h>

void DeleteSpace(char* message)
{
    char* ptr = message;
    int i;
    for (i = 0; *ptr != '\0'; i++)
    {
        while (*ptr == ' ')
            ptr++;

        message[i] = *ptr;         
        ptr++;
    }
    message[i] = *ptr;
}

int main(int argc, char* argv[])
{
    char* message = argv[1]; 

    DeleteSpace(message);
    
    printf("%s\n", message);

    return 0;
}
