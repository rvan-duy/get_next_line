/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:31:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/12 19:57:51 by rubenz        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int 	gnl_len(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

char	*gnl_strjoin(char *buf, char **line, int len1, int len2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc((len1 + len2 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < len2)
	{
		newstr[i] = line[0][i];
		i++;
	}
	while (j < len1)
	{
		newstr[i] = buf[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// might not have to do +1 since newline is gonna be the null terminator
char	*gnl_parsebuffer(char *buf, int len)
{
	int i;
	char *ptr;

	i = 0;
	ptr = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		ptr[i] = buf[i + len];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
