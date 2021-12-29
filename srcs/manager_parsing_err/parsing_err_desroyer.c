/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err_desroyer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:25:57 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/28 23:57:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void		parsing_err_destroyer(t_parsing_err *parsing_err)
{
	free(parsing_err);
	parsing_err = NULL;
}
