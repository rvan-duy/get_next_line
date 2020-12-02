/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:29:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/02 22:00:12 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
    # define BUFFER_SIZE 128
#endif

#include <unistd.h>
#include <stdlib.h>

int     gnl_strlen(const char *s);
int     get_next_line(int fd, char **line);
int     gnl_find_nline(char *buf);
int     gnl_cut_until_nline(char *buf, int newline, char **line);
char    *gnl_strjoin(char *buf, char **line, int newline);
int     gnl_parsebuffer(char *buf, int newline);

#endif
