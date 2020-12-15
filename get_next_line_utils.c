/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:31:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/15 16:25:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*gnl_strjoin(char *buf, char **line, int len)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = malloc((len + gnl_len(line[0]) + 1) * sizeof(char));
	if (!newstr)
	{
		free(line[0]);
		return (NULL);
	}
	while (line[0][i])
	{
		newstr[i] = line[0][i];
		i++;
	}
	while (buf && *buf != '\n')
	{
		newstr[i] = *buf;
		i++;
		buf++;
	}
	newstr[i] = '\0';
	free(line[0]);
	return (newstr);
}

void	gnl_parsebuffer(char *str, int len)
{
	int i;

	i = 0;
	if (str[len])
		len += 1;
	while (str[len])
	{
		str[i] = str[len];
		i++;
		len++;
	}
	str[i] = '\0';
}
