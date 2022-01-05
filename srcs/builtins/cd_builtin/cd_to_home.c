/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_to_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:30:12 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 11:52:00 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

static char	*find_home(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (find_env_var(tmp->var, "HOME=") == TRUE)
			return (&tmp->var[5]);
		tmp = tmp->next;
	}
	return (NULL);
}

static void	check_and_move_directory(char **directories, char *originalpwd)
{
	int		i;

	i = 0;
	while (directories[i] != NULL)
	{
		if (access(directories[i], F_OK) == -1)
		{
			ft_putstr_fd("bash: cd: ", STDERR_FILENO);
			ft_putstr_fd(directories[i], STDERR_FILENO);
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
			chdir(originalpwd);
			return ;
		}
		if (access(directories[i], X_OK) == -1)
		{
			ft_putstr_fd("bash: cd: ", STDERR_FILENO);
			ft_putstr_fd(directories[i], STDERR_FILENO);
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
			chdir(originalpwd);
			return ;
		}
		chdir(directories[i]);
		i++;
	}
}

void	cd_to_home(t_env *env)
{
	char	*pwd;
	char	**home_path;

	pwd = NULL;
	home_path = NULL;
	move_to_root(env);
	pwd = getcwd(NULL, 0);
	home_path = ft_split(find_home(env), '/');
	check_and_move_directory(home_path, pwd);
}
