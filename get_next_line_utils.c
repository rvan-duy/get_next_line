/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:31:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/09 14:59:35 by rvan-duy      ########   odam.nl         */
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
void		gnl_parsebuffer(char *buf, int len)
{
	int i;

	i = 0;
	while (buf[len])
	{
		buf[i] = buf[i + len + 1];
		i++;
	}
	buf[i] = '\0';
	return ;
}
