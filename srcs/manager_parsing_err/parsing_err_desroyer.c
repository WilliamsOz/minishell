/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err_desroyer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:25:57 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/04 12:07:59 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_parsing_err	*parsing_err_destroyer(t_parsing_err *parsing_err)
{
	free(parsing_err);
	parsing_err = NULL;
	return (parsing_err);
}
