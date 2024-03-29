/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:07:16 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 17:24:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	get_len(t_minishell *m, char *line, int i, int len)
{
	while (line[i] != '\0')
	{
		if (line[i] == '$' && line[i + 1] == '?')
			len += get_status_len(&i, g_signal_handler);
		else if (line[i] == SIMPLE_COTE || line[i] == DOUBLE_COTE)
		{
			i++;
			len++;
		}
		if (line[i] == '$'
			&& existing_expand(line + i + 1, m->env, 0) == TRUE)
			len += get_expanded_len(line + i + 1, &i, 0, m->env);
		else
			i = skip_unk_exp(line, i);
	}
	return (len);
}

static char	*get_new_line(char *line, char *new_line, t_env *env, int i)
{
	int	j;

	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$' && line[i + 1] == '?')
			new_line = cpy_status(new_line, &i, &j);
		else if (line[i] == '$'
			&& existing_expand(line + i + 1, env, 0) == TRUE)
		{
			new_line = copy_expanded_value(line + i + 1, env, new_line, &j);
			i += get_end_of_expansion(line + i + 1, 0);
		}
		else if (line[i] == '$')
			i = skip_unk_exp(line, i);
		else
		{
			new_line[j] = line[i];
			i += 1;
			j += 1;
		}
	}
	return (new_line);
}

static void	trim_line(t_minishell *m, char *line, t_env *env, int fd)
{
	char	*new_line;
	int		len;

	new_line = NULL;
	len = get_len(m, line, 0, 0);
	new_line = (char *)malloc(sizeof(char) * (len + 1));
	if (new_line == NULL)
		mall_trimed_line_failed(m);
	new_line[len] = '\0';
	new_line = get_new_line(line, new_line, env, 0);
	free(line);
	write(fd, new_line, ft_strlen(new_line));
	write(fd, "\n", 1);
	free(new_line);
}

t_minishell	*w_inside_child(t_minishell *m, t_dlk_list *tmp)
{
	char	*line;

	while (1)
	{
		line = NULL;
		line = readline("> ");
		if (line == NULL)
		{
			m = eof_called(m, tmp);
			return (m);
		}
		else if (line != NULL)
		{
			if (ft_strcmp(line, tmp->limiter) == TRUE)
				return (m);
			else
				trim_line(m, line, m->env, tmp->heredoc_pipe[1]);
		}
	}
	return (m);
}

t_minishell	*heredoc(t_minishell *m, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;

	handle_heredoc();
	tmp = dlk;
	while (tmp != NULL && g_signal_handler != 130)
	{
		if (tmp->here_doc == 1 && g_signal_handler != 130)
		{
			tmp = hd_prepare_dlk(tmp);
			tmp = call_child(m, tmp, 0);
		}
		tmp = tmp->next;
		if (g_signal_handler == 130)
		{
			if (m->d_lk != NULL)
				m->d_lk = double_lk_destroyer(m->d_lk);
			if (m->parsing_err != NULL)
				m->parsing_err = parsing_err_destroyer(m->parsing_err);
			m->line = free_line(m->line);
			close_heredoc_pipes(m->d_lk);
			g_signal_handler = 0;
			break ;
		}
	}
	return (m);
}
