/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/29 13:18:33 by rvan-duy      ########   odam.nl         */
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

static char *before_nline(char *line, int newline)
{
	int i;
	char *newstr;

	newstr = malloc(sizeof(char) * newline + 1);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		newstr[i] = line[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// Needs to grab what comes after the nline and save it
// Can also be EOF, then return ?

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int newline;
	char *str;
	char *savedstr;

	int ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	newline = find_nline(buf);
	printf("Newline or EOF: %d || ", newline);
	printf("[%d] - [%s] || ", ret, buf);
	str = before_nline(buf, newline);
	printf("cut string: [%s]\n", str);
	printf("-- [%s, %d] --\n", buf, newline);
	savedstr = gnl_strdup(buf + newline + 1);
	printf("after newline: [%s]\n", savedstr);

	
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
