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
    char *buf;
    char *buf2;
    int ret;
    int ret2;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }

    fd2 = open("get_next_line_bonus.h", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open and read the file.\n");
        exit(1);
    }


    ret = get_next_line(0, &buf);
    printf("[%d] [%d] [%s]\n", fd, ret, buf);
    free(buf);
    //ret = get_next_line(fd, &buf);
    //printf("[%d] main - line: [%s]\n", ret, buf);
    //free(buf);
    //ret = get_next_line(fd, &buf);
    //printf("[%d] main - line: [%s]\n", ret, buf);
    //while ((ret = get_next_line(fd, &buf) > 0) && (ret2 = get_next_line(fd2, &buf2) > 0))
    //{
      //printf("[%d] - [%d] - [%s]\n", fd, ret, buf);
      //printf("[%d] - [%d] - [%s]\n", fd2, ret2, buf2);
      //free(buf);
    //}
    //printf("main 3 - [%d] - [%s]\n", ret, buf);
    //free(buf);
    //printf("[%d] - [%s]\n", ret, buf);
    //get_next_line(fd, &buf);
    //while (1) {};

    return ;
}

int main()
{
  main_helper();



  return 0;
}