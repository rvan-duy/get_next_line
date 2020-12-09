/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/09 15:30:27 by rvan-duy      ########   odam.nl         */
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
	line[0] = gnl_strjoin(buf, line, len1, len2);	
	// error checking!!!
	if (buf[gnl_len(buf)] + 1)
	{
		gnl_parsebuffer(buf, len1);
		return (1);
	}
	buf[0] = '\0';
	gnl_make_line(buf, line, fd, ret);
}

int			get_next_line(int fd, char **line)
{
    static char buf[BUFFER_SIZE + 1];
    int ret;

	if (!line || fd < 0)
		return (-1);
	ret = gnl_make_line(buf, line, fd, ret);
	if (ret == -1)
		return (-1);








	/*newline = 0;
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
    }*/
    return (ret);
}
