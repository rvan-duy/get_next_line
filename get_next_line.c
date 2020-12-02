/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/02 19:26:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    int ret;
    int newline;
    int end;

    end = 0;
    newline = 0;
    while (newline == 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret > 0)
        {
            newline = gnl_find_nline(buf);
            // This needs error handeling but i have no idea how
            line[0] = gnl_strjoin(buf, line, newline);
            printf("newline: %d\n", newline);
        }
        if (ret == -1)
            return (-1);
        if (ret == 0)
            return (ret);
    }
    ///printf("buf: [%s]\n", buf);
    return ret;
}
