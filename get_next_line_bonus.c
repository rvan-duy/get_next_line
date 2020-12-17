/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/17 22:40:12 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	gnl_read(char **fds, char *buf, int fd)
{
	char	*tmp;
	int		ret;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	tmp = gnl_strjoin(fds[fd], buf, ret, 0);
	free(fds[fd]);
	if (!tmp)
		return (gnl_free(-1, buf, NULL));
	fds[fd] = tmp;
	return (ret);
}

static int	gnl_make_line(char **fds, char **line, int fd, int ret)
{
	char	*tmp;
	char	*buf;

	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	while (!gnl_strchr(fds[fd], '\n') && ret > 0)
		ret = gnl_read(fds, buf, fd);
	free(buf);
	if (ret == -1)
		return (gnl_free(ret, fds[fd], NULL));
	if (ret == 0)
		return (0);
	line[0] = gnl_strndup(fds[fd], '\n');
	if (!line[0])
		return (gnl_free(-1, fds[fd], NULL));
	tmp = fds[fd];
	fds[fd] = gnl_strndup(fds[fd] + gnl_len(fds[fd], '\n') + 1, '\0');
	if (!fds[fd])
		return (gnl_free(-1, fds[fd], line[0]));
	free(tmp);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*fds[1000];
	int				ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!fds[fd])
		fds[fd] = gnl_strndup("", '\0');
	line[0] = gnl_strndup("", '\0');
	if (!line[0])
		return (-1);
	ret = gnl_make_line(fds, line, fd, 1);
	return (ret);
}
