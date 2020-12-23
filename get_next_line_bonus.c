/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 14:26:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2020/12/23 10:42:51 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	gnl_read(char **fds, int fd)
{
	char	*tmp;
	int		ret;
	char	*buf;

	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	tmp = gnl_strjoin(fds[fd], buf, 0, 0);
	free(buf);
	if (!tmp)
		return (-1);
	free(fds[fd]);
	fds[fd] = tmp;
	return (ret);
}

static int	gnl_read_line(char **fds, int fd, int ret)
{
	while (!gnl_strchr(fds[fd], '\n') && ret > 0)
		ret = gnl_read(fds, fd);
	if (ret == -1)
		return (gnl_free(ret, fds[fd], NULL));
	if (ret == 0)
		return (0);
	return (1);
}

static char	*gnl_make_line(char **fds, int fd)
{
	char *tmp;
	char *dst;

	dst = gnl_strndup(fds[fd], '\n');
	if (!dst)
	{
		gnl_free(-1, fds[fd], NULL);
		return (NULL);
	}
	tmp = fds[fd];
	fds[fd] = gnl_strndup(fds[fd] + gnl_len(fds[fd], '\n') + 1, '\0');
	if (!fds[fd])
	{
		gnl_free(-1, fds[fd], dst);
		return (NULL);
	}
	free(tmp);
	return (dst);
}

int			get_next_line(int fd, char **line)
{
	static char		*fds[MAX_FD];
	int				ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!fds[fd])
		fds[fd] = gnl_strndup("", '\0');
	ret = gnl_read_line(fds, fd, 1);
	*line = gnl_make_line(fds, fd);
	return (ret);
}
