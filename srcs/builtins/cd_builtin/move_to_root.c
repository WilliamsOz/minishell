/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_to_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:46:48 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/04 17:10:51 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	move_to_root(t_env *env)
{
	char	**root_path = NULL;
	t_env	*tmp;
	int		i;

	tmp = env;
	while (tmp != NULL)
	{
		if (find_env_var(tmp->var, "PWD=") == TRUE)
		{
			root_path = ft_split(tmp->var, '/');
			i = 0;
			while (root_path[i] != NULL)
			{
				free(root_path[i]);
				chdir("..");
				i++;
			}
			free(root_path);
		}
		tmp = tmp->next;
	}
}