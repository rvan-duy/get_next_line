/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 19:40:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/01 15:09:15 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
    # define BUFFER_SIZE 128
#endif
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int     get_next_line(int fd, char **Line);
size_t  gnl_strlen(const char *s);
void    *gnl_memset(void *s, int c, size_t n);
void    gnl_bzero(void *s, size_t n);
char    *gnl_strdup(const char *s1);
void    *gnl_calloc(size_t count, size_t size);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
void     gnl_strmove(char *dst, char *src, int n);

#endif
