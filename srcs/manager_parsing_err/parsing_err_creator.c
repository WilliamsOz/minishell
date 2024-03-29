/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err_creator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:25:13 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 11:34:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_parsing_err	*parsing_err_creator(void)
{
	t_parsing_err	*parsing_err;

	parsing_err = (t_parsing_err *)malloc(sizeof(t_parsing_err));
	if (parsing_err == NULL)
	{
		strerror(errno);
		return (parsing_err);
	}
	return (parsing_err);
}
