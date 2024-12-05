#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 256

void DecorateBrackets(char* message)
{
    char newMessage[MAX_WORD_LEN];
    int index = 0;
    int isSpace = 1;

    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if (index > MAX_WORD_LEN)
        {   
            strncpy(message, "New message too long", MAX_WORD_LEN);
            message[MAX_WORD_LEN - 1] = '\0';
            return;
        }

        if (message[i] == ' ' || message[i] == '\0')
        {
            if (!isSpace)
                newMessage[index++] = ')';
            if (message[i] != '\0')
                newMessage[index++] = message[i]; 
            isSpace = 1;
        }
        else if (message[i] >= '!' && message[i] <= '~')
        {
            if (isSpace) 
                newMessage[index++] = '(';
            newMessage[index++] = message[i];
            isSpace = 0;
        }
    }

    strncpy(message, newMessage, index);
    message[index] = '\0';
}

void ReadLine(char* buffer)
{
    int c;
    int index = 0;

    while ((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            buffer[index] = '\0';
            return;
        }
        else if (index < MAX_WORD_LEN - 1)
        {
            buffer[index++] = c;
        }
        else 
        {
            printf("Input too long\n");
            while ((c = getchar()) != '\n' && c != EOF);
            buffer[0] = '\0';
            return;
        }
    }
    buffer[index] = '\0';
}

int main()
{
    char message[MAX_WORD_LEN];

    while(1) 
    {    
        printf("Write message: ");
        ReadLine(message);   
        
        if(strlen(message) == 0)
        {
            printf("Empty message or EOF. Exiting.\n");
            break;
        }

        DecorateBrackets(message);
        printf("=====================\n");
        printf("%s\n", message);
        printf("=====================\n");
    }

    return 0;
}


