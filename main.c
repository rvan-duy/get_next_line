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
    //ret = get_next_line(fd, &buf);
    //printf("main - line: [%s]\n", buf);
    //ret = get_next_line(fd, &buf);
    //printf("main - line: [%s]\n", buf);
    while ((ret = get_next_line(fd, &buf) > 0))
      printf("main - [%d] - [%s]\n", ret, buf);
    printf("main - [%d] - [%s]\n", ret, buf);
    //printf("[%d] - [%s]\n", ret, buf);
    //get_next_line(fd, &buf);
    //while (1) {};

    return 0;
}


// Lorem Ipsum is simply dummy text of the printing and \0typesetting industry._______Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
