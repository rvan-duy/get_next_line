/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:29:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/01/07 11:44:04 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		gnl_len(char *buf, char c);
int		get_next_line(int fd, char **line);
char	*gnl_strjoin(char *s1, char *s2, int ret, int len);
char	*gnl_strchr(char *s, int c);
char	*gnl_strndup(char *s1, char c);
int		gnl_free(int ret, char *s1, char *s2);

#endif
