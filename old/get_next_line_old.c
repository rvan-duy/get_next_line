/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_old.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/02 15:27:52 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line returns a line read from a file descriptor, without the newline.
*/

#include "get_next_line_old.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Buffer grab the stuff after nline, and move to front.
static int	gnl_parsebuffer(char *buf, int newline)
{
	int i = 0;
	//printf("[%s] - [%d]\n", buf, newline);
	while (i < newline)
	{
		printf("[%c]", buf[i]);
		//buf[i] = buf[i + newline];
		i++;
	}
	return (1);
}

// almost?
static int	gnl_strjoin(char *buf, char **line)
{
	int len1;
	int	len2;

	len1 = gnl_strlen(buf);
	len2 = gnl_strlen(line[0]);
	line[0] = malloc((len1 + len2 + 1) * sizeof(char));
	if (!line)
		return (0);
	gnl_strlcpy(line[0], buf, len1 + len2 + 1);
	line[0][len1 + len2 + 1] = '\0';
	return (1);
}

// Looking for nline or EOF, if found return i.
static int	gnl_find_nline(char *line)
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
		buf[ret + strlen] = '\0';
		newline = gnl_find_nline(buf);
		gnl_cut_until_nline(buf, newline, line);
		//printf("[%s] -", buf);
		gnl_parsebuffer(buf, newline);
		//printf("[%s]\n", buf);
		
		//gnl_strjoin(buf, line);
		//printf("[%s] - [%s]\n", line[0], buf);
	}

	ret = 0;
	// Looking for newline or EOF
	/*newline = gnl_find_nline(buf);
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
		gnl_memset(buf, 0, BUFFER_SIZE);*/

	
	
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
