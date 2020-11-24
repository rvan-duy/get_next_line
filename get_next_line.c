/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/24 19:20:02 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line returns a line read from a file descriptor, without the newline.
*/

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int findnewline(char *line)
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

int	get_next_line(int fd, char **line)
{
	int i = 0;
	int j = 0;
	*line = calloc(BUFFER_SIZE, sizeof(char));
	int ret = read(fd, *line, BUFFER_SIZE);

	
	// Buffer_size has been read
	// 		when a newline is found
	//		when the end of the file is foun
	if (findnewline(*line) != -1)
		printf("Newline found on index: %d\n", findnewline(*line));
	

	printf("[%s]\n", *line);


	
	return (ret);
}
