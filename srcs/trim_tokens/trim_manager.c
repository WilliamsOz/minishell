/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:57:28 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/10 15:26:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	trim_malloc_failed(t_minishell *minishell, t_trim *trim)
{
	strerror(errno);
	destroy_trim(trim);
	minishell = destroy_all_data(minishell);
	exit (EXIT_FAILURE);
}

t_trim	*init_trim(t_minishell *minishell)
{
	t_trim	*trim;

	trim = NULL;
	trim = (t_trim *)malloc(sizeof(t_trim));
	if (trim == NULL)
	{
		strerror(errno);
		minishell = destroy_all_data(minishell);
		exit (EXIT_FAILURE);
	}
	trim->before_quote = NULL;
	trim->between_quote = NULL;
	trim->after_quote = NULL;
	return (trim);
}

void	destroy_trim(t_trim *trim)
{
	if (trim->before_quote != NULL)
		free(trim->before_quote);
	if (trim->between_quote != NULL)
		free(trim->between_quote);
	if (trim->after_quote != NULL)
		free(trim->after_quote);
	if (trim != NULL)
		free(trim);
}