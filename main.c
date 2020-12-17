#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main_helper()
{
    int fd;
    int fd2;
    int fd3;
    char *buf;
    int ret;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }

    /* Multiple file descriptors*/
    fd2 = open("get_next_line_bonus.h", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }

    fd3 = open("test_copy.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }

    /* Reading 1 file until EOF */
    while ((ret = get_next_line(fd, &buf) > 0))
    {
      printf("[FD:%d] - [RET:%d] - [%s]\n", fd, ret, buf);
      free(buf);
    }

    /* Reading multiple files */
    ret = get_next_line(fd, &buf);
    printf("[FD:%d] - [RET:%d] - [%s]\n", fd, ret, buf);
    free(buf);
    ret = get_next_line(fd2, &buf);
    printf("[FD:%d] - [RET:%d] - [%s]\n", fd2, ret, buf);
    free(buf);
    ret = get_next_line(fd3, &buf);
    printf("[FD:%d] - [RET:%d] - [%s]\n", fd3, ret, buf);
    free(buf);

    //while (1) {};

    return ;
}

int main()
{
  main_helper();



  return 0;
}