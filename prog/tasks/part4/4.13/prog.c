#include <stdio.h>
#include <stdlib.h>

int count_digit(int number)
{
    return number / 10 == 0 ? 1 : count_digit(number / 10) + 1;
}

int main (int argc, char* argv[])
{
    int start_pos = atoi(argv[1]);
    int end_pos = atoi(argv[2]);
    
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
