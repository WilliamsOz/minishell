/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:07:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/22 21:35:19 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*rd_hd(t_minishell *m, t_dlk_list *dlk, char **env, int ef)
{
	char	*buffer;

	while (ef > 0)
	{
		buffer = read_on_hd_pipe(m, buffer, env, &ef);
		if (signal_handler == 130)
			break ;
		if (ef == 0)
			eof_called(m, dlk);
		if (ef > 0 && ft_strcmp(dlk->limiter, buffer) == TRUE)
		{
			dlk = end_called(dlk, buffer);
			return (dlk);
		}
		else if (ef > 0)
			write_hd_inside_pipe(dlk, buffer, &dlk->hd_line_count);
	}
	return (dlk);
}

// static t_dlk_list	*get_heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
// {
// 	t_dlk_list	*tmp;

// 	tmp = dlk;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->here_doc == 1 && tmp->limiter != NULL)
// 		{
// 			tmp->hd_line_count = 1;
// 			tmp = rd_hd(m, tmp, env, 1);
// 		}
// 		tmp = tmp->next;
// 	}
// 	dlk = close_ununsed_pipes(dlk);
// 	return (dlk);
// }

// static int	is_there_heredoc(t_minishell *minishell)
// {
// 	t_dlk_list	*tmp;

// 	tmp = minishell->d_lk;
// 	while (tmp != NULL)
// 	{
// 		if (tmp->here_doc == 1)
// 			return (TRUE);
// 		tmp = tmp->next;
// 	}
// 	return (FALSE);
// }

t_minishell	*write_inside_child(t_minishell *m, t_dlk_list *tmp, char *limiter)
{
	char	*line;
	int		eof;

	eof = 1;
	while (eof > 0)
	{
		line = NULL;
		line = readline("> ");
		// write(1, "> ", 2);
		// eof = get_next_line(0, &line);
		if (line == NULL)
		{
			eof_called(m, m->d_lk);
			return (m);
		}
		else if (line != NULL)
		{
			tmp->hd_line_count++;
			if (ft_strcmp(line, limiter) == TRUE)
				return (m);
		}
	}
	return (m);
}

t_dlk_list	*child_called(t_minishell *m, t_dlk_list *tmp, char **env, int sts)
{
	pid_t	pid;
	int		ret;

	(void)env;
	ret = pipe(tmp->heredoc_pipe);
	if (ret == -1)
		pipe_failed(m);
	pid = fork();
	// if (pid == -1)
		// fork_failed();
	if (pid == 0)
	{
		close(tmp->heredoc_pipe[1]);
		dup2(STDIN_FILENO, tmp->heredoc_pipe[0]);
		m = write_inside_child(m, tmp, tmp->limiter);
	}
	else
	{
		PD(signal_handler)
		close(tmp->heredoc_pipe[0]);
		waitpid(pid, &sts, WUNTRACED);
	}
	return (tmp);
}

t_dlk_list	*hd_prepare_dlk(t_dlk_list *dlk)
{
	t_dlk_list	*tmp;
	t_dlk_list	*keep;

	tmp = dlk->next;
	keep = tmp->next;
	dlk->limiter = tmp->token;
	free(tmp);
	dlk->next = keep;
	return (dlk);
}

// les cotes son garder dans tout les cas dans le HD
t_dlk_list	*heredoc(t_minishell *m, t_dlk_list *dlk, char **env)
{
	t_dlk_list	*tmp;

	signal(SIGINT, hd_handler);
	tmp = dlk;
	signal_handler = 0;
	while (tmp != NULL && signal_handler != 130)
	{
		if (tmp->here_doc == 1)
		{
			tmp = hd_prepare_dlk(tmp);
			dlk = child_called(m, tmp, env, 0);
		}
		tmp = tmp->next;
	}
		// if (is_there_heredoc(m) == TRUE)
		// 	dlk = init_heredoc_pipes(m, dlk, 0);
		// dlk = get_heredoc(m, dlk, env);
	signal(SIGINT, rl_handler);
	signal(SIGQUIT, rl_handler);
	return (dlk);
}
