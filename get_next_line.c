/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/06 17:31:57 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// doesn't work with only \n\n\n\n\n
int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    int ret;
    int newline;
    int strlen;

	newline = -1;
    strlen = 0;
    while (newline < 0)
    {
		printf("buf is now: %s\n", buf);
		if (buf[0])
		{
			newline = gnl_find_nline(buf);
			line[0] = gnl_strjoin(buf, line, newline);
			if (line[0] == NULL)
				return (-1);
			gnl_parsebuffer(buf, newline);
			strlen = gnl_strlen(buf);
			newline = gnl_find_nline(buf);
			if (newline != 0)
				break ;
		}
		ret = read(fd, buf + strlen, BUFFER_SIZE - strlen);
		//printf("ret: %d - buf: %s\n", ret, buf);
		if (ret == 0)
			return (0);
		if (ret == -1)
			return (-1);
		buf[ret + strlen + 1] = '\0';
		newline = gnl_find_nline(buf);
		//printf("newline: %d\n", newline);
		line[0] = gnl_make_line(buf, newline);
		if (line[0] == NULL)
			return (-1);
		gnl_parsebuffer(buf, newline);
    }
    return (1);
}
