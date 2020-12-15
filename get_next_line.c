/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/15 13:20:12 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	gnl_make_line(char *buf, char **line, int fd, int ret)
{
	int len;

	if (!buf[0])
	{
		//printf("buf does not exist!\n");
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 || ret == -1)
			return (ret);
		buf[ret] = '\0';
		//printf("read BUFFER_SIZE... buf:\n[%s]\n", buf);
	}
	len = gnl_len(buf);
	//printf("buf:\n[%s]\n", buf);
	line[0] = gnl_strjoin(buf, line, len);
	//printf("line:\n[%s]\n", line[0]);
	gnl_parsebuffer(buf, len);
	//printf("buf:\n[%s]\n", buf);
	if (!buf[0] || buf[len] == '\n')
		return (1);
	return (gnl_make_line(buf, line, fd, ret));
}

int			get_next_line(int fd, char **line)
{
	static char buf[BUFFER_SIZE + 1];
	int ret;

	if (!line || fd < 0)
		return (-1);
	*line = malloc(sizeof(char));
	if (!*line)
		return (-1);
	ret = gnl_make_line(buf, line, fd, ret);
	return (ret);
}
