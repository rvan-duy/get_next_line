/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:29:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/09 14:53:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
    # define BUFFER_SIZE 128
#endif

#include <unistd.h>
#include <stdlib.h>

int     gnl_len(char *buf);
int     get_next_line(int fd, char **line);
char    *gnl_strjoin(char *buf, char **line, int len1, int len2);
void	gnl_parsebuffer(char *buf, int len);

#endif
