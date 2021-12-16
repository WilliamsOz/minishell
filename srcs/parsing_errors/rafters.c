/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rafters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:30:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 13:04:45 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

int	check_rafter_errors(t_dlk_list *dlk)
{
	// if ((dlk->upper_rafter == 1 || dlk->double_upper_rafter == 1)
	// 	&& directory_redirection(m, dlk, env) == TRUE)
	// 	return (TRUE);
	if (dlk->lower_rafter == 1 && lower_rafter_errors(dlk) == 1)
		return (TRUE);
	else if (dlk->upper_rafter == 1 && upper_rafter_errors(dlk) == 1)
		return (TRUE);
	return (FALSE);
}
