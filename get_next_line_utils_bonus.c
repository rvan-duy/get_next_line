/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:31:09 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/17 22:31:17 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		gnl_len(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, int ret, int len)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	len = gnl_len(s1, '\0');
	newstr = malloc((ret + len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*gnl_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}

char	*gnl_strndup(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((gnl_len(s1, c) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == c)
			break ;
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		gnl_free(int ret, char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (ret);
}
