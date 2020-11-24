/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 18:43:46 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/11/23 23:30:54 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line returns a line read from a file descriptor, without the newline.
*/

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	
	read(fd, line[0], 13);
	return (1);
}
