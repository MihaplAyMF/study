#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_WORD_LEN 256 

void CountWords(char* message, int* num)
{
    *num = 0;
    int isSpace = 1; 

    int length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ')
        {
            isSpace = 1;
        }
        if (message[i] >= '!' && message[i] <= '~')
        {
            if (isSpace)
            {
                (*num)++;
                isSpace = 0;
            }
        }
    }
}

void WordsLength(char* message, int* num1, int* num2)
{
    int n = 0;
    *num1 = 0;
    *num2 = 0;
 
    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if(message[i] == ' ' || message[i] == '\t' || message[i] == '\0')
        {
            if (n != 0)
            {
                if (n % 2 != 0) 
                {
                    (*num1)++;
                }
                else    
                {
                    (*num2)++;
                }
                n = 0;
            }
        }
        if(message[i] >= '!' && message[i] <= '~')
        {
            n++;
        }
    }
}

void WordsValid(char* message, int* num1, int* num2)
{
    int n = 0;
    int isSpace = 1;
    *num1 = 0;
    *num2 = 0;
    
    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if(message[i] == ' ' || message[i] == '\t' || message[i] == '\0')
        {
            if ((n >= 0) && (n < 2) && !isSpace) 
            {
                (*num1)++;
            }
            if ((n > 7) && !isSpace)
            {
                (*num2)++;
            }
            n = 0;
            isSpace = 1;
        }
        else
        {
            n++;
            isSpace = 0;
        }
    }
}

void WordsAZ(char* message, int* num)
{
    int isSpace = 1;
    *num = 0;
    char first = ' ';
    char last = ' ';
    
    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ' || message[i] == '\t' || message[i] == '\0')
        {
            if ((first == 'A' || first == 'a') && (last == 'Z' || last == 'z'))
                (*num)++;
            isSpace = 1;
        }
        else
        {
            if (isSpace)
            {
                first = message[i];
            }
            else
            {
                last = message[i];
            }
            isSpace = 0;
        }
    }
}

void MinMaxWordsLength(char* message, int* num1, int* num2)
{
    int n = 0;
    int has_word = 0;
    *num1 = INT_MAX;
    *num2 = 0;
    
    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ' || message[i] == '\t' || message[i] == '\0') 
        {
            if (n != 0)
            {
                has_word = 1;
                if (*num1 > n) 
                {
                    *num1 = n;
                } 
                if (*num2 < n)
                {
                    *num2 = n;
                }
            }
            n = 0;
        }
        if(message[i] >= '!' && message[i] <= '~')
        {
            n++;
        }
        if (!has_word)
            *num1 = 0;
    }
}

void MaxSpaces(char* message, int* num)
{
    int n = 0;
    *num = 0;
    
    int length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ') 
        {
            n++;
            if (*num < n) 
                *num = n;
        }
        else 
        {
            n = 0;
        }
    }
}

void BalanceBrackets(char* message)
{
    int brackets = 0;
    
    int length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        if (message[i] == '(')
            brackets++;
        else if (message[i] == ')')
            brackets--;
            if (brackets < 0)
                break;
    }

    if (!brackets)
        printf("Balance brackets: YES\n");
    else 
        printf("Balance brackets: NO\n");
}

void CountBrackets(char* message, int* num)
{
    *num = 0;

    int length = strlen(message) + 1;
    for (int i = 0; i < length; i++)
    {
        if (message[i] == '(' && message[i + 1] == ')')
        {
            (*num)++;
        }
    }
}

int main() 
{
    char message[MAX_WORD_LEN];
    int c;
    int index = 0;
    
    printf("Write message: ");

    while ((c = getchar()) != EOF)
    {
        int num1, num2;
        if(c == '\n')
        {
            message[index] = '\0';
  
            printf("=========================\n");
            CountWords(message, &num1);
            printf("Count words: %d\n", num1);
            WordsLength(message, &num1, &num2);
            printf("Count of odd: %d\n", num1);
            printf("Count of even: %d\n", num2);
            WordsValid(message, &num1, &num2);
            printf("Words less 2: %d\n", num1);
            printf("Words more 7: %d\n", num2);
            WordsAZ(message, &num1);
            printf("Wods a..z: %d\n", num1);
            MinMaxWordsLength(message, &num1, &num2);
            printf("Min word: %d\n", num1);
            printf("Max word: %d\n", num2);
            MaxSpaces(message, &num1);
            printf("Max space: %d\n", num1);
            BalanceBrackets(message);
            CountBrackets(message, &num1);
            printf("Brackest: %d\n", num1);
            printf("=========================\n");
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
}
