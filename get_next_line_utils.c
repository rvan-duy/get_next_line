/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:31:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/02 15:52:24 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// Returns position of newline or EOF.
// 0 if no newline of EOF is found.
int 	gnl_find_nline(char **line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[0][i])
	{
		if (line[0][i] == '\n' || line[0][i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

// Cut buf until newline, put result in line.
// Return 1 if succesfull.
// Return 0 if fails.
int 	gnl_cut_until_nline(char *buf, int newline, char **line)
{
	int i;

	line[0] = malloc((newline + 1) * sizeof(char));
	if (!line[0])
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

// Returns a joined string.
// First put line in newstr, then free line.
// Then put buf in line.
char	*gnl_strjoin(char *buf, char **line)
{
	int		i;
	int		j;
	int 	len1;
	int		len2;
	char	*newstr;

	i = 0;
	j = 0;
	len1 = gnl_strlen(buf);
	len2 = gnl_strlen(line[0]);
	newstr = malloc((len1 + len2 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (line[0][i] != '\0')
	{
		newstr[i] = line[0][i];
		i++;
	}
	while (buf[j] != '\0')
	{
		newstr[i] = buf[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
