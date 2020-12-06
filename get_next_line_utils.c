/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:31:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/06 17:31:09 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		gnl_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int 	gnl_find_nline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *buf, char **line, int newline)
{
	int		i;
	int		j;
	int 	len1;
	int		len2;
	char	*newstr;

	i = 0;
	j = 0;
	len1 = newline;
	len2 = gnl_strlen(line[0]);
	if (len1 == 0)
		len1 = gnl_strlen(buf);
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
void		gnl_parsebuffer(char *buf, int newline)
{
	int i;
	int len;

	i = 0;
	len = gnl_strlen(buf + newline + 1);
	while (i < len)
	{
		buf[i] = buf[i + newline + 1];
		i++;
	}
	buf[i] = '\0';
	return ;
}

// what if newline is 0, then entire buf needs to be put in line!
// newline is weird
char		*gnl_make_line(char *buf, int newline)
{
	char *line;
	int i;

	i = 0;
	line = malloc((newline + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < newline)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
