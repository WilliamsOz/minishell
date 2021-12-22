/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:03:18 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 15:02:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_first_read(char *line, char *buffer)
{
	line = (char *)malloc(sizeof(char) * 2);
	if (line == NULL)
		return (NULL);
	line[0] = buffer[0];
	line[1] = '\0';
	return (line);
}

static char	*get_next_reads(char *line, char *buffer)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = line;
	len = ft_strlen(line);
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	line[len] = buffer[0];
	line[len + 1] = '\0';
	i = 0;
	while (tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (line);
}

void	handler(int signum)
{
	if (signum == SIGINT)
		signal_handler = SIGINT;
}

static int	hd_gnl(t_minishell *m, int fd, char **line)
{
	char	buffer[1];
	int		eof;

	buffer[0] = '\0';
	sigaction(SIGINT, &m->sa, NULL);
	eof = read(fd, buffer, 1);
	if (buffer[0] == '\n' || eof == 0)
		return (eof);
	if (eof > 0)
		*line = get_first_read(*line, buffer);
	if (*line == NULL && eof > 0)
		return (-1);
	while (eof > 0 && buffer[0] != '\n')
	{
		eof = read(fd, buffer, 1);
		if (buffer[0] == '\n' || eof == 0)
			return (eof);
		*line = get_next_reads(*line, buffer);
		if (*line == NULL)
			return (-1);
	}
	return (eof);
}

char	*read_on_hd_pipe(t_minishell *m, char *buf, char **env, int *ptr_eof)
{
	buf = NULL;
	write(1, "> ", 2);
	*ptr_eof = hd_gnl(m, 0, &buf);
	if (*ptr_eof > 0)
		buf = get_new_hd(m, buf, env, 0);
	return (buf);
}
