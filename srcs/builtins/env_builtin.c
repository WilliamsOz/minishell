// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   env_builtin.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/26 19:57:56 by oozsertt          #+#    #+#             */
// /*   Updated: 2021/12/26 20:29:55 by oozsertt         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../inc/minishell.h"

void	env_builtin(t_env *env, t_cmd *cmd)
{
	t_env	*tmp;

	tmp = env;
	while (env != NULL)
	{
		ft_putstr_fd(env->var, cmd->output);
		ft_putstr_fd("\n", cmd->output);
		env = env->next;
	}
	env = tmp;
}