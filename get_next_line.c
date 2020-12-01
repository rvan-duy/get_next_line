/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/01 21:09:13 by rvan-duy      ########   odam.nl         */
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
	newstr = gnl_calloc(strlen1 + strlen2 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	gnl_memcpy(newstr, str1, strlen1);
	gnl_memcpy(newstr + strlen1, str2, strlen2);
	return (newstr);
}

// Looking for nline or EOF, if found return i.
static int gnl_find_nline(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

// Cutting line and putting it in line. 1 if succesfull, 0 if fails.
static int	gnl_cut_until_nline(char *buf, int newline, char **line)
{
	int i;

	line[0] = malloc((newline + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[0][i] = buf[i];
		i++;
	}
	line[0][i] = '\0';
	return (1);
}

// Needs to grab what comes after the nline and save it
// Can also be EOF, then return ?

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*temp;
	int			strlen;
	int			ret;
	int			newline;
	//char *str;
	//char *newstr;
	
	// Reading buf until newline or EOF is found. Also checking if there is already something in buf.
	while (gnl_find_nline(buf) == 0)
	{
		if (buf[0] && !temp)
		{	
			temp = gnl_strdup(buf);
			strlen = gnl_strlen(temp);
		}	
		else
			strlen = 0;
		ret = read(fd, buf + strlen, BUFFER_SIZE - strlen);
		if (ret == -1)
			return (-1);
		// Implement strjoin somewhere, what if already read something?
		buf[ret + strlen] = '\0';
	}

	// Looking for newline or EOF
	newline = gnl_find_nline(buf);
	printf("[gnl_find_nline] returned %d.\n", newline);
	
	// Cutting line
	if (gnl_cut_until_nline(buf, newline, line) == 1)
		printf("[gnl_cut_until_nline] returned 1: [%s]\n", line[0]);
	else
		printf("[gnl_cut_until_nline] returned 0.\n");

	// Checking if there is still something after the newline
	if (buf[newline + 1] != '\0')
	{
		strlen = gnl_strlen(buf + newline + 1);
		printf("There is more stuff after newline: [%s]\n", buf + newline + 1);
		gnl_strmove(buf, buf + newline + 1, strlen);
	}
	else
		gnl_memset(buf, 0, BUFFER_SIZE);

	
	
	//savedstr = gnl_strdup(buf + newline + 1);
	//printf("after newline: [%s]\n", savedstr);
	//newstr = gnl_strjoin(savedstr, buf);
	//printf("newstr: [%s]\n", newstr);
	
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
