/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:27:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/16 14:20:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_here_doc_errors(t_dlk_list *tmp)
{
	if (tmp->next == NULL)
		ft_putstr_fd("bash: syntax error near unexpected token `newline'\n", 2);
	else if (tmp->next != NULL && tmp->next->pipeline == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
	else if (tmp->next != NULL && tmp->next->upper_rafter == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `>'\n", 2);
	else if (tmp->next != NULL && tmp->next->lower_rafter == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `<'\n", 2);
	else if (tmp->next != NULL && tmp->next->here_doc == 1)
		ft_putstr_fd("bash: syntax error near unexpected token `<<'\n", 2);
	if (tmp->next == NULL || (tmp->next != NULL && 
		(tmp->next->pipeline == 1 || tmp->next->upper_rafter == 1 ||
		tmp->next->lower_rafter == 1 || tmp->next->here_doc == 1)))
		return (TRUE);
	return (FALSE);
}