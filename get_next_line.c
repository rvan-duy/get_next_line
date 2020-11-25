/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/25 15:50:57 by rvan-duy      ########   odam.nl         */
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
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char *cut_until_nline(char **line)
{
	int i;
	char *newstr;

	newstr = malloc(sizeof(char) * find_nline(*line) + 1);

	i = 0;
	while (i < i)
	{
		printf("%d ", i);
		newstr[i] = line[i];
		i++;
	}	
}

int	get_next_line(int fd, char **line)
{
	*line = calloc(BUFFER_SIZE, sizeof(char));
	int ret = read(fd, *line, BUFFER_SIZE);
	char *newstr;
	newstr = calloc(1000, sizeof(char));
	// Buffer_size has been read
	// 		when a newline is found
	//		when the end of the file is foun
	/*if (newline != -1)
	{
		printf("Newline found on index: %d\n", newline);
		printf("[%s]", *line);
		newstr = cut_until_nline(*line, newline);
	}*/
	printf("[%p]\n", line);
	printf("[%s]\n", line[0]);
	printf("[%c]\n", line[0][1]);


	
	return (ret);
}
