/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_call_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:30:12 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:58:32 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_dlk_list	*call_child(t_minishell *m, t_dlk_list *tmp, int status)
{
	pid_t	pid;
	int		ret;

	ret = pipe(tmp->heredoc_pipe);
	if (ret == -1)
		pipe_failed(m);
	pid = fork();
	if (pid == -1)
		fork_failed(m);
	if (pid == 0)
	{
		g_signal_handler = -1;
		close(tmp->heredoc_pipe[0]);
		m = w_inside_child(m, tmp);
		close(tmp->heredoc_pipe[1]);
		exit (EXIT_SUCCESS);
	}
	else
	{
		close(tmp->heredoc_pipe[1]);
		waitpid(pid, &status, 0);
	}
	return (tmp);
}
