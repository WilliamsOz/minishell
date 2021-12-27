// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   echo_builtin.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/22 20:27:13 by oozsertt          #+#    #+#             */
// /*   Updated: 2021/12/26 21:24:59 by oozsertt         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../inc/minishell.h"

// typedef int	t_bool;
// // maybe add echo $? command ?

// static t_bool	is_n_option(t_dlk_list *dlk)
// {
// 	int	i;

// 	if (dlk == NULL)
// 		return (FALSE);
// 	if (dlk->token[0] != '-')
// 		return (FALSE);
// 	if (dlk->token[1] != 'n')
// 		return (FALSE);
// 	i = 2;
// 	while (dlk->token[i] != '\0')
// 	{
// 		if (dlk->token[i] != 'n')
// 			return (FALSE);
// 		i++;
// 	}
// 	return (TRUE);
// }

// static t_dlk_list	*skip_option(t_dlk_list *dlk)
// {
// 	while (is_n_option(dlk) == TRUE)
// 		dlk = dlk->next;
// 	return (dlk);
// }

// void	echo_builtin(t_dlk_list *dlk)
// {
// 	t_dlk_list	*tmp;
// 	t_bool		option;

// 	if (is_n_option(dlk) == TRUE)
// 		option = 1;
// 	else
// 		option = 0;
// 	if (option == 1)
// 		dlk = skip_option(dlk);
// 	tmp = dlk;
// 	if (dlk != NULL)
// 	{
// 		if (option == 0)
// 		{
// 			ft_putstr_fd(dlk->token, STDOUT_FILENO);
// 			write(STDOUT_FILENO, "\n", 1);
// 		}
// 		else
// 			ft_putstr_fd(dlk->token, STDOUT_FILENO);
// 	}
// 	else
// 		write(STDOUT_FILENO, "\n", 1);
// 	dlk = tmp;
// }
