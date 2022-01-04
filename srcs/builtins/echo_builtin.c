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

typedef int	t_bool;

static t_bool	is_n_option(char *option)
{
	int	i;

	if (option == NULL)
		return (FALSE);
	if (option[0] != '-')
		return (FALSE);
	if (option[1] != 'n')
		return (FALSE);
	i = 2;
	while (option[i] != '\0')
	{
		if (option[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	skip_option(char **cmd)
{
	int	i;

	i = 1;
	while (is_n_option(cmd[i]) == TRUE)
		i++;
	return (i);
}

void	echo_builtin(t_cmd *cmd)
{
	int			i;
	t_bool		option;

	if (is_n_option(cmd->cmd[1]) == TRUE)
		option = 1;
	else
		option = 0;
	i = 1;
	if (option == 1)
		i = skip_option(cmd->cmd);
	if (cmd->cmd[i] != NULL)
	{
		if (option == 0)
		{
			ft_putstr_fd(cmd->cmd[i], cmd->output);
			write(cmd->output, "\n", 1);
		}
		else
			ft_putstr_fd(cmd->cmd[i], cmd->output);
	}
	else
		write(cmd->output, "\n", 1);
}
