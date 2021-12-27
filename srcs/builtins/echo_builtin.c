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

// #include "../../inc/minishell.h"

// typedef int	t_bool;
// // maybe add echo $? command ?

// static t_bool	is_n_option(char *token)
// {
// 	int	i;

// 	if (token[0] != '-')
// 		return (FALSE);
// 	if (token[1] != 'n')
// 		return (FALSE);
// 	i = 2;
// 	while (token[i] != '\0')
// 	{
// 		if (token[i] != 'n')
// 			return (FALSE);
// 		i++;
// 	}
// 	return (TRUE);
// }

// static t_dlk_list	*skip_option(t_dlk_list *dlk)
// {
// 	while (is_n_option(dlk->token) == TRUE)
// 		dlk = dlk->next;
// 	return (dlk);
// }

// void	echo_builtin(t_dlk_list *dlk)
// {
// 	t_dlk_list	*tmp;
// 	t_bool		option;

// 	option = 0;
// 	if (is_n_option(dlk->token) == TRUE)
// 		option = 1;
// 	tmp = dlk;
// 	if (option == 1)
// 		dlk = skip_option(dlk);
// 	if (dlk != NULL || dlk->here_doc == 0 || dlk->lower_rafter == 0
// 	|| dlk->upper_rafter == 0 || dlk->double_upper_rafter == 0
// 	|| dlk->pipeline == 0)
// 	{
// 		if (option == 0)
// 		{
// 			ft_putstr_fd(dlk->token, STDOUT_FILENO);
// 			write(STDOUT_FILENO, '\n', 1);
// 		}
// 		else
// 			ft_putstr_fd(dlk->token, STDOUT_FILENO);
// 	}
// 	dlk = tmp;
// }
