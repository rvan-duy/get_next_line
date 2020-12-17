/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_lars.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 18:17:41 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/17 21:32:40 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	unfinished(int *array, int n)
{
	int i = 0;
	while (i < n)
	{
		if (array[i] > 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int n = argc - 1;
	char **line;
	int fd[n];
	int ret[n];
	int lines[n];
	int i = 0;
	int stdinret = 1;

	line = malloc (1 * sizeof(char *));
	if (n == 0)
	{
		while (stdinret > 0)
		{
			stdinret = get_next_line(0, line);
			printf("FD:[0] - return:[%i] = %s\n", stdinret, line[0]);
			free(line[0]);
		}
		return (0);
	}

	while (i < n)
	{
		fd[i] = open(argv[i+1], O_RDONLY);
		ret[i] = 1;
		lines[i] = 1;
		i++;
	}
	i = 0;
	while (1)
	{
		if (ret[i] == 1)
		{
			ret[i] = get_next_line(fd[i], line);
			printf("FD:[%i] - return:[%i] - line:[%i] = %s\n", fd[i], ret[i], lines[i], line[0]);
			free(line[0]);
			lines[i]++;
		}
		if (i == n-1)
			i = 0;
		else
			i++;
		if (!unfinished(ret, n))
			break ;
	}
	free(line);
	//while (1){}
	return (0);
}