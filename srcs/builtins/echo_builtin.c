/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:28:22 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 17:28:25 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	put_strs(char **strs, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		ft_putstr_fd(strs[i], cmd->output);
		if (strs[i + 1] != NULL)
			write(1, " ", cmd->output);
		i++;
	}
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
		put_strs(cmd->cmd, cmd);
		if (option == 0)
			write(cmd->output, "\n", 1);
	}
	else
		write(cmd->output, "\n", 1);
}
