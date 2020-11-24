#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;
    char **buf;
    int i;

    fd = open("test.txt", O_RDONLY);
    if (!fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }

    get_next_line(fd, &buf);
    return 0;
}
