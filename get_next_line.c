/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/26 14:07:05 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line returns a line read from a file descriptor, without the newline.
*/

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int find_nline(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static char *cut_until_nline(char *line)
{
	int i;
	char *newstr;

	newstr = malloc(sizeof(char) * find_nline(line) + 1);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		newstr[i] = line[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int newline;
	static int i = 0;

	int ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	newline = find_nline(buf);
	printf("Newline at: %d\n", newline);

	
	printf("[%d] - [%s]\n", ret, buf);
	char *newstr;
	// Buffer_size has been read
	// 		when a newline is found
	//		when the end of the file is foun
	
	
	/*if (ret != -1)
	{
		printf("[%s]\n", *line);
		newstr = cut_until_nline(*line);
		printf("[%s]\n", newstr);
	}*/
	
	
	
	//printf("[%p]\n", line);
	//printf("[%s]\n", line[0]);
	//printf("[%c]\n", line[0][1]);


	
	return (ret);
}
