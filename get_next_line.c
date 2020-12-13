/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/13 17:33:17 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	gnl_make_line(char *buf, char **line, char *temp, int fd, int ret)
{
	int len;
	int i;
	
	if (!temp)
	{
		printf("temp does not exist!\n");
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			return (0);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = malloc(sizeof(char) * ret);
		while (i < ret)
		{
			temp[i] = buf[i];
			i++;
		}
		printf("read BUFFER_SIZE... filled temp with buf:\n[%s]\n", temp);
	}
	// temp bestaat, zit er een newline in?
	len = gnl_len(temp);
	printf("checking for len %d, [%c]\n", len, temp[len]);
	if (temp[len] == '\n')
	{
		line[0] == gnl_strjoin();
	}
	

	
	//len1 = gnl_len(buf);
	//len2 = gnl_len(*line);
	//line[0] = gnl_strjoin(temp, line, len1, len2);
	//printf("joined temp and line together:\n[%s]\n", line[0]);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *temp;
	int ret;

	if (!line || fd < 0)
		return (-1);
	*line = malloc(sizeof(char));
	if (!*line)
		return (-1);
	ret = gnl_make_line(buf, line, temp, fd, ret);
	return (ret);
}
