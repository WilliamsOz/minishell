/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:32:03 by wiozsert          #+#    #+#             */
/*   Updated: 2022/01/05 17:37:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_builtin(char *str)
{
	if (ft_strcmp("cd", str) == TRUE)
		return (TRUE);
	else if (ft_strcmp("echo", str) == TRUE)
		return (TRUE);
	else if (ft_strcmp("env", str) == TRUE)
		return (TRUE);
	else if (ft_strcmp("exit", str) == TRUE)
		return (TRUE);
	else if (ft_strcmp("export", str) == TRUE)
		return (TRUE);
	else if (ft_strcmp("pwd", str) == TRUE)
		return (TRUE);
	else if (ft_strcmp("unset", str) == TRUE)
		return (TRUE);
	return (FALSE);
}
