/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/08 12:36:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    int ret;
    int newline;

	newline = 0;
    while (newline == 0)
    {
		if (buf[0])
		{
			newline = gnl_find_nline(buf);
			line[0] = gnl_strjoin(buf, line, newline);
			if (line[0] == NULL)
				return (-1);
			gnl_parsebuffer(buf, newline);
		}
		else
		{
			ret = read(fd, buf, BUFFER_SIZE);
			printf("ret: [%d]\n", ret);
			if (ret == 0)
				return (0);
			///////////// what to when read returns 0 or -1?
			buf[ret + 1] = '\0';
			printf("buf: [%s]\n", buf);
			newline = gnl_find_nline(buf);
			printf("newline: [%d]\n", newline);
			line[0] = gnl_strjoin(buf, line, newline);
			printf("after joining line: [%s] || buf: [%s]\n", line[0], buf);
			///////////// this strjoin needs error handling, also free stuff but how?
			if (line[0] == NULL)
				return (-1);
			gnl_parsebuffer(buf, newline);
			printf("after parsing: line: [%s] || buf: [%s]\n", line[0], buf);
		}
    }
    return (1);
}
