#include <stdio.h>

int m_strlen(char* message)
{
    int length = 0;
    for(int i = 0; message[i] != '\0'; i++)
        length++; 
    return length;
}

void WordCount(int* wordCount, char* argv[])
{
    int isSpace = 0;
    *wordCount = 1;

    int length = m_strlen(argv[1]);
    for (int i = 1; i < length; i++)
    {
        if (argv[1][i] == ' ')
            isSpace = 1;
        if ((argv[1][i] >= '!') && (argv[1][i] <= '~'))
        {
            if (isSpace)
            {
                (*wordCount)++;
                isSpace = 0;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        int num;
        WordCount(&num, argv);
        printf("Word count: %d\n", num);
    } 
    else 
    {
        printf("input 1 argument\n");
    }
        
    return 0;
}
