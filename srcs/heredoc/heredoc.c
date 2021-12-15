/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:07:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/15 12:52:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	__eof_called__(t_minishell *minishell, t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	int			count;

	count = 0;
	tmp = minishell->d_lk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
			count += tmp->hd_line_count;
		tmp = tmp->next;
	}
	ft_putstr_fd(" bash: warning: here-document at line ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(dlk->limiter, 2);
	ft_putstr_fd("')\n", 2);
}

static t_dlk_list	*rd_hd(t_minishell *m, t_dlk_list *dlk, char **env, int ef)
{
	char	*buffer;

	while (ef > 0)
	{
		buffer = read_on_hd_pipe(m, buffer, env, &ef);
		if (signal_handler == SIGINT)
			break ;
		if (ef == 0)
			__eof_called__(m, dlk);
		if (ef > 0 && ft_strcmp(dlk->limiter, buffer) == TRUE)
		{
			dlk = end_called(dlk, buffer);
			return (dlk);
		}
		else if (ef > 0)
			write_hd_inside_pipe(dlk, buffer, &dlk->hd_line_count);
	}
	write(dlk->heredoc_pipe[1], '\0', 1);
	return (dlk);
}

static t_dlk_list	*get_heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	t_dlk_list	*tmp;

	tmp = dlk;
	while (tmp != NULL)
	{
		if (tmp->here_doc == 1)
		{
			tmp->hd_line_count = 1;
			tmp = rd_hd(m, tmp, env, 1);
		}
		tmp = tmp->next;
	}
	dlk = close_unused_pipe(dlk);
	return (dlk);
}

void	handler2(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		signal_handler = SIGINT;
	}
}

t_dlk_list	*heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	m->sa.sa_handler = handler2;
	dlk = __init_heredoc_pipes__(m, dlk, 0);
	dlk = get_heredoc(m, dlk, env);
	signal_handler = 0;
	return (dlk);
}
