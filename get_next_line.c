/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/05 21:57:56 by rubenz        ########   odam.nl         */
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

    int i = 0;

    strlen = 0;
    newline = 0;
    while (newline == 0)
    {
	if (buf[0])
	{
		printf("buffer exists already!\n");
		newline = gnl_find_nline(buf);
		printf("newline in buf: %d\n", newline);
		line[0] = gnl_strjoin(buf, line, newline);
		printf("joined buf with line, line: %s\n", line[0]);
		gnl_parsebuffer(buf, newline);			
		printf("parsed buffer, buf: %s\n", buf);
		strlen = gnl_strlen(buf);
		printf("len of buf: %d\n", strlen);
		newline = gnl_find_nline(buf);
		if (newline != 0)
		{
			printf("found newline in old buf! no need to read\n");
			break ;
		}
	}
	printf("now starting normal reading proces\n");
	ret = read(fd, buf + strlen, BUFFER_SIZE - strlen);
	printf("read returned: %d\n", ret);
	if (ret == 0)
		return (0);
	if (ret == -1)
		return (-1);
	buf[ret + strlen + 1] = '\0';
	printf("read buffer: %s\n", buf);
	newline = gnl_find_nline(buf);
	printf("newline in buffer: %d\n", newline);
	line[0]= gnl_strjoin(buf, line, newline);
	printf("joined buf with line, line: %s\n", line[0]);
	gnl_parsebuffer(buf, newline);
	printf("parsed buffer, buf: %s\n", buf);
        /*if (ret > 0)
        {
            newline = gnl_find_nline(buf);
	    if (newline == 0 && ret == 0)
	    {
		line[0] = gnl_strjoin(buf, line, gnl_strlen(line[0]));
	    	return (0);
	    }
	    // This needs error handeling but i have no idea how
	    line[0] = gnl_strjoin(buf, line, newline);
            gnl_parsebuffer(buf, newline);
	}
	i++;*/
    }
    return (1);
}
