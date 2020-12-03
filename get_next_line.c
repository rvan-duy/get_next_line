/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/03 20:50:44 by rubenz        ########   odam.nl         */
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

    newline = 0;
    while (newline == 0)
    {
	strlen = gnl_strlen(buf);	
	printf("%d before read - [%s] [%d]\n", i, buf, strlen);
	ret = read(fd, buf + strlen, BUFFER_SIZE - strlen);
	printf("%d after read - [%s] [%d]\n", i, buf + strlen, strlen);
	printf("%d after read (buf) - [%s] [%d]\n", i, buf, gnl_strlen(buf));
	buf[ret + 1] = '\0';
        if (ret >= 0)
        {
            newline = gnl_find_nline(buf);
	    printf("%d after newline - [%d]\n", i, newline);
	    if (newline == 0 && ret == 0)
	    {
		line[0] = gnl_strjoin(buf, line, gnl_strlen(line[0]));
	    	return (0);
	    }
	    // This needs error handeling but i have no idea how
            printf("%d before strjoin - [%s] [%s] [%d]\n", i, buf, line[0], newline);
	    line[0] = gnl_strjoin(buf, line, newline);
            gnl_parsebuffer(buf, newline);
	    printf("%d after strjoin - [%s] [%s]\n", i, line[0], buf);
	}
        else
            return (-1);
	i++;
    }
    return ret;
}
