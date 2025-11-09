#define _LARGEFILE64_SOURCE // for lseek64 

#include <stdio.h>  // printf, scanf
#include <fcntl.h>  // open and macros
#include <unistd.h> // lseek64, close

int main(int argc, char* argv[])
{
    if (argc < 2) 
    {
        printf("Usage: /program <filename>\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    
    if (fd == -1) 
    {
        printf("Failed to open file\n");
        return 1;
    }

    long long file_size = lseek64(fd, 0, SEEK_END);
    if (file_size == -1)
    {
        printf("Failed to determine file size\n");
        close(fd);
        return 1;
    }
    
    printf("File size: %lld bytes\n", file_size);

    if (close(fd) == -1)
    {
        printf("Failed to close file\n");
        return 1;
    }

    return 0;
}
