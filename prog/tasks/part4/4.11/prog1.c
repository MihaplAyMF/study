#include <stdio.h>
//#include <string.h> FORBIDDEN

#define MAX_WORD_LEN 256

int m_strlen(char* message)
{
    int length = 0;
    for(int i = 0; message[i] != '\0'; i++)
        length++; 
    return length;
}

void m_strcpy(char* dest, char* src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

void m_strcat(char* dest, char* src)
{    
    int i = m_strlen(dest);

    for(int j = 0; src[j] != '\0'; j++)
    {
        dest[i] = src[j]; 
        i++;
    }

    dest[i] = '\0';
}

void LongestWord(char* message, int* max, int argc, char* argv[])
{
    *max = 0;
    for (int i = 1; i < argc; i++)
    {
        int length = m_strlen(argv[i]);
        if (length > *max)
        {
            m_strcpy(message, argv[i]);
            *max = length;
        }
    }
}

void NotSameSymb(char* message, int argc, char* argv[])
{
    int isSame;
    char tmpMessage[MAX_WORD_LEN];
    
    message[0] = '\0';

    for (int i = 1; i < argc; i++)
    {
        isSame = 0;
        m_strcpy(tmpMessage, argv[i]);
        
        int length = m_strlen(tmpMessage);
        for (int j = 0; j < length; j++)
            for (int k = j + 1; k < length; k++)
                if (tmpMessage[j] == tmpMessage[k])
                    isSame = 1;

        if (!isSame)
        {
            m_strcat(message, tmpMessage);
            m_strcat(message, " ");
        }     
    }
};

void IsValidMessage(char* message, int argc, char* argv[])
{
    char tmpMessage[MAX_WORD_LEN];
    int isDot;
    int isAt;

    message[0] = '\0';
    
    for (int i = 1; i < argc; i++)
    {
        isDot = 0;
        isAt = 0;
        
        m_strcpy(tmpMessage, argv[i]);

        int length = m_strlen(tmpMessage);
        for (int j = 0; j < length; j++)
        {
            if (tmpMessage[j] == '@')
                isAt++;
            if (tmpMessage[j] == '.')
                isDot = 1;
        }
        
        if ((isDot) && (isAt == 1))
        {
            m_strcat(message, tmpMessage);
            m_strcat(message, " ");
        }           
    }
}

void IsDigit(char* message, int argc, char* argv[])
{
    char tmpMessage[MAX_WORD_LEN];
    int isDigit;

    message[0] = '\0';

    for (int i = 1; i < argc; i++)
    {
        isDigit = 1;
        m_strcpy(tmpMessage, argv[i]);

        int length = m_strlen(tmpMessage);
        for (int j = 0; j < length; j++)
            if ((tmpMessage[j] <= '0') || (tmpMessage[j] >= '9'))
                isDigit = 0;

        if (isDigit) 
        {
            m_strcat(message, tmpMessage);
            m_strcat(message, " ");
        }
    }
}

void SameSymb(char* message, int argc, char* argv[])\
{
    char tmpMessage[MAX_WORD_LEN];
    char symb;
    int sameSymb;

    message[0] = '\0';
    
    for (int i = 1; i < argc; i++)
    {
        sameSymb = 1;
        m_strcpy(tmpMessage, argv[i]);
        symb = tmpMessage[0];

        int length = m_strlen(tmpMessage);
        for (int j = 1; j < length; j++)
            if (symb != tmpMessage[j])
                sameSymb = 0;
    
        if (sameSymb)
        {
            m_strcat(message, tmpMessage);
            m_strcat(message, " ");
        }

    }
}

void IsLatinSymb(char* message, int argc, char* argv[])
{
    char tmpMessage[MAX_WORD_LEN];
    int isLatin = 0;
    
    message[0] = '\0';

    for (int i = 1; i < argc; i++)
    {
        isLatin = 0;
        m_strcpy(tmpMessage, argv[i]);

        int length = m_strlen(tmpMessage);
        for(int j = 0; j < length; j++)
        {
            if ((tmpMessage[j] >= 'A' && tmpMessage[j] <= 'Z')
                || (tmpMessage[j] >= 'a' && tmpMessage[j] <= 'z'))
            {
                isLatin = 1;
                break;
            }    
        }

        if (isLatin)
        {
             m_strcat(message, tmpMessage);
             m_strcat(message, " ");
        }
    }
}

void IsSymbFirstWord(char* message, int argc, char* argv[])
{
    char tmpMessage[MAX_WORD_LEN];
    int isSymbFirstWord = 0;

    message[0] = '\0';
    
    for (int i = 0; i < argc; i++)
    {
        isSymbFirstWord = 0;

        m_strcpy(tmpMessage, argv[i]);

        int length = m_strlen(tmpMessage);
        for (int j = 1; j < length; j++)
        {
            if (tmpMessage[0] == tmpMessage[j])
            {
                isSymbFirstWord = 1;
                break;
            }
        }

        if (isSymbFirstWord)
        {
             m_strcat(message, tmpMessage);
             m_strcat(message, " ");
        }
    }
}


int main(int argc, char* argv[])
{
    char message[MAX_WORD_LEN];
    int num;

    LongestWord(message, &num, argc, argv);
    
    printf("Longest word: %s\nlength: %d\n", message, num);
   
    NotSameSymb(message, argc, argv);
    printf("Not same symb: %s\n", message);

    IsValidMessage(message, argc, argv);
    printf("One @ and at least one dot: %s\n", message);
    
    IsDigit(message, argc, argv);
    printf("Only digit: %s\n", message);
    
    SameSymb(message, argc, argv);
    printf("Same symb: %s\n", message);
    
    IsLatinSymb(message, argc, argv);
    printf("Least one latin symb: %s\n", message);
    
    IsSymbFirstWord(message, argc, argv);
    printf("With repeating first symb: %s\n", message);

    return 0;
}
