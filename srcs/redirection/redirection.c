/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:06 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 15:47:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	redirection_check(t_minishell *m, char **env)
{
	t_dlk_list	*tmp;

	tmp = m->d_lk;
	while (tmp != NULL)
	{
		if (tmp->lower_rafter && lr_bad_redirection(m, tmp, env) == TRUE)
			 return (TRUE);
		// else if (tmp->upper_rafter && is_ur_bad_redirection(tmp) == TRUE)
		// 		return (TRUE);
		// else if (tmp->double_upper_rafter
			// && is_dr_bad_redirection(tmp) == TRUE)
		// 		return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}
	//upr
// static int	directory_redirection(t_minishell *m, t_dlk_list *dlk, char **env)
// {
// 	char	*tmp;
// 	int		fd;

// 	tmp = trim(m, dlk->next->token, -1, env);
// 	fd = open(tmp, O_DIRECTORY);
// 	if (fd != -1)
// 	{
// 		ft_putstr_fd("bash :", 2);
// 		ft_putstr_fd(tmp, 2);
// 		ft_putstr_fd(": Is a directory\n", 2);
// 		close (fd);
// 		return (TRUE);
// 	}
// 	fd = open(tmp, )
// 	return (FALSE);
// }

	// if ((dlk->upper_rafter == 1 || dlk->double_upper_rafter == 1)
	// 	&& directory_redirection(m, dlk, env) == TRUE)
	// 	return (TRUE);