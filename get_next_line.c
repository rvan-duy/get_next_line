/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/02 22:05:01 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    // dont forget to put last element on \0 after read
    int ret;
    int newline;
    int end;
    int strlen;

    strlen = 0;
    end = 0;
    newline = 0;
    while (newline == 0)
    {
        ret = read(fd, buf + strlen, BUFFER_SIZE - strlen);
        buf[ret + 1] = '\0';
        if (ret > 0)
        {
            newline = gnl_find_nline(buf);
            // This needs error handeling but i have no idea how
            line[0] = gnl_strjoin(buf, line, newline);
            if (buf[newline + 1] != '\0')
                strlen = gnl_parsebuffer(buf, newline);
        }
        if (ret == -1)
            return (-1);
        if (end == 1)
            return (0);
    }
    ///printf("buf: [%s]\n", buf);
    return ret;
}
