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
    char *buf;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }

    int ret;
    ret = get_next_line(fd, &buf);
    printf("[%d] main - line: [%s]\n", ret, buf);
    //ret = get_next_line(fd, &buf);
    //printf("[%d] main - line: [%s]\n", ret, buf);
    //ret = get_next_line(fd, &buf);
    //printf("[%d] main - line: [%s]\n", ret, buf);
    //while ((ret = get_next_line(fd, &buf) > 0))
      //printf("main - [%d] - [%s]\n", ret, buf);
    //printf("main - [%d] - [%s]\n", ret, buf);
    //printf("[%d] - [%s]\n", ret, buf);
    //get_next_line(fd, &buf);
    while (1) {};

    return 0;
}
