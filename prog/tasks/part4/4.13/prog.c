#include <stdio.h>
#include <stdlib.h>

int count_digit(int number)
{
    return number / 10 == 0 ? 1 : count_digit(number / 10) + 1;
}

int str_to_int(char* str)
{
    int num = 0;
    int sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    } 
    else if (*str == '+') 
    {
        str++;
    }

    while(*str != '\0')
    {
        if (*str < '0' || *str > '9')
        {
            printf("You entered the wrong number.\n");
            return 1;
        }

        num = num * 10 + (*str - '0');
        str++;
    }

    return num * sign;
}

int main (int argc, char* argv[])
{
    if (argc != 3) 
    {
        printf("EROOR: Expected 2 arguments.\n");
        return 1;
    }

    int start_pos = str_to_int(argv[1]);
    int end_pos = str_to_int(argv[2]);
  
    if (start_pos <= 0 || end_pos <= 0)
    {
        printf("EROOR: Not correct arguments.\n");
        return 1;
    }

    int current_pos = 0;
    long num = 1;

    while(current_pos + count_digit(num*num) < start_pos)
    {
        current_pos += count_digit(num*num);
        num++;
    }

    int print_count = 0;
    int start_in_number = start_pos - current_pos - 1;
    
    int count = end_pos - start_pos;
    while(print_count <= count)
    {
        long square = num * num;
        char square_str[20];
        sprintf(square_str, "%d", square);
        for (int i = start_in_number; square_str[i] != '\0'; i++) {
            putchar(square_str[i]);
            print_count++;
            if (print_count > count) {
                break;
            }
        }
        num++;
    }
    
    printf("\n");

    return 0;
}
