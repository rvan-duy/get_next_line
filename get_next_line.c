/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/06 12:18:52 by rubenz        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    int ret;
    int newline;
    int strlen;

    strlen = 0;
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
		strlen = gnl_strlen(buf);
		newline = gnl_find_nline(buf);
		if (newline != 0)
			break ;
	}
	ret = read(fd, buf + strlen, BUFFER_SIZE - strlen);
	if (ret == 0)
		return (0);
	if (ret == -1)
		return (-1);
	buf[ret + strlen + 1] = '\0';
	newline = gnl_find_nline(buf);
	line[0]= gnl_strjoin(buf, line, newline);
	if (line[0] == NULL)
		return (-1);
	gnl_parsebuffer(buf, newline);
    }
    return (1);
}
