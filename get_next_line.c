/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/12 12:15:29 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	gnl_make_line(char *buf, char **line, int fd, int ret)
{
	int len1;
	int len2;

	if (!buf[0])
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			return (0);
		else if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	len1 = gnl_len(buf);
	len2 = gnl_len(line[0]);
	printf("--- len1: %d - len2: %d\n", len1, len2);
	line[0] = gnl_strjoin(buf, line, len1, len2);
	printf("--- line[0]\n[%s]\n", line[0]);
	printf("--- buf\n[%s]\n", buf);
	// error checking!!!
	if (buf[gnl_len(buf)] + 1)
	{
		printf("--- parsing buffer\n");
		gnl_parsebuffer(buf, len1);
		return (1);
	}
	buf[0] = '\0';
	printf("--- buf - %s\n", buf);
	//gnl_make_line(buf, line, fd, ret);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    int ret;

	if (!line || fd < 0)
		return (-1);
	ret = gnl_make_line(buf, line, fd, ret);
    return (ret);
}
