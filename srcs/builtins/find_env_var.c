/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:24:45 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/04 16:14:52 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		find_env_var(char *var, char *pwd_header)
{
	int	i;

	i = 0;
	while (pwd_header[i] != '\0')
	{
		if (var[i] != pwd_header[i] && var[i] != '\0')
			return (FALSE);
		i++;
	}
	if (pwd_header[i] == '\0')
		return (TRUE);
	else
		return (FALSE);
}
