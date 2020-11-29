/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 19:22:54 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/29 13:20:18 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	*gnl_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void    gnl_bzero(void *s, size_t n)
{
	gnl_memset(s, 0, n);
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	gnl_bzero(str, (size * count));
	return (str);
}

char    *gnl_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = gnl_calloc(gnl_strlen(s1) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}