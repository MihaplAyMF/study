#include <stdio.h>

char* FindSubString(char* str, char* substr)
{
    int j = 0;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != substr[j])
            j = 0;
        else 
            j++;
        
        if (substr[j] == '\0')
            return &str[i - j + 1];
    }

    return NULL;
}

int main(int argc, char* argv[])
{  
    if (argc < 3) {
        printf("Not enough arguments!\n");
        return 1;
    }
    
    if (argv[1][0] == '\0')
    {
        printf("Not correct arguments!\n");
        return 1;
    }
 
    char* result;
    for (int i = 2; i < argc; i++)
    {
        int num = 0;

        result = FindSubString(argv[i], argv[1]);
        while(result)
        {
            num++;
            result = FindSubString(result + 1, argv[1]);
        }
        
        if (num)
        {
            printf("%s\n", argv[i]);
            printf("%d\n", num);
        } 
    }

    return 0;
}

