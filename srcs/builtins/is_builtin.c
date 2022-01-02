/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 23:48:34 by user42            #+#    #+#             */
/*   Updated: 2022/01/01 23:48:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp("echo", cmd) == TRUE)
		return (TRUE);
	else if (ft_strcmp("cd", cmd) == TRUE)
		return (TRUE);
	else if (ft_strcmp("pwd", cmd) == TRUE)
		return (TRUE);
	else if (ft_strcmp("export", cmd) == TRUE)
		return (TRUE);
	else if (ft_strcmp("unset", cmd) == TRUE)
		return (TRUE);
	else if (ft_strcmp("env", cmd) == TRUE)
		return (TRUE);
	else if (ft_strcmp("exit", cmd) == TRUE)
		return (TRUE);
	return (FALSE);
}
