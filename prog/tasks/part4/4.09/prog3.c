#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 256

void Word2SameSymb(char* message)
{
    char tmpMessage[MAX_WORD_LEN] = "";
    char aword[MAX_WORD_LEN] = ""; 

    char first = ' ';
    char second = ' ';
    
    int isValid = 1; 

    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ' || message[i] == '\t' || message[i] == '\0')
        {
            if ((first != ' ') && (second != ' ') && isValid)
            {
                strcat(tmpMessage, aword);
                strcat(tmpMessage, " ");
            }
            first = ' ';
            second = ' ';
            aword[0] = '\0';
            isValid = 1;
        }
        else 
        {
            if (first == ' ')
                first = message[i];
            else if ((second == ' ') && message[i] != first)
                second = message[i];
            else if ((message[i] != first) && (message[i] != second))
                isValid = 0;
            int len = strlen(aword);
            aword[len] = message[i];
            aword[len + 1] = '\0';
        }
    }
    strcpy(message, tmpMessage); 
}

int main() 
{
    char message[MAX_WORD_LEN];
    int c;
    int index = 0;

    printf("Write message: ");
    
    while ((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            message[index] = '\0';
            Word2SameSymb(message);
            printf("=======================\n");
            printf("%s\n", message);
            printf("=======================\n");
            printf("Write message: ");
            index = 0;
        }
        else if (index < MAX_WORD_LEN - 1)
        {
            message[index++] = c;
        }
        else 
        {
            printf("Line too long\n");
        }
    }

    return 0;
}
