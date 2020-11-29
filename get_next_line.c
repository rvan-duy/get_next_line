/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/29 14:44:16 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line returns a line read from a file descriptor, without the newline.
*/

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *gnl_strjoin(char *str1, char *str2)
{
	char *newstr;
	int strlen1;
	int strlen2;

	strlen1 = gnl_strlen(str1);
	strlen2 = gnl_strlen(str2);
	printf("[%s, %s, %d, %d]\n", str1, str2, strlen1, strlen2);
	newstr = gnl_calloc(strlen1 + strlen2 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	gnl_memcpy(newstr, str1, strlen1);
	gnl_memcpy(newstr + strlen1, str2, strlen2);
	return (newstr);
}

static int gnl_find_nline(char *line)
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

static char *gnl_before_nline(char *line, int newline)
{
	int i;
	char *newstr;

	newstr = gnl_calloc(newline + 1, sizeof(char));
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		newstr[i] = line[i];
		i++;
	}
	return (newstr);
}

// Needs to grab what comes after the nline and save it
// Can also be EOF, then return ?

int	get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int newline;
	char *str;
	char *newstr;
	static char *savedstr;

	int ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	newline = gnl_find_nline(buf);
	printf("Newline or EOF: %d || ", newline);
	str = gnl_before_nline(buf, newline);
	printf("cut string: [%s]\n", str);
	savedstr = gnl_strdup(buf + newline + 1);
	printf("after newline: [%s]\n", savedstr);
	newstr = gnl_strjoin(savedstr, buf);
	printf("newstr: [%s]\n", newstr);
	
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
