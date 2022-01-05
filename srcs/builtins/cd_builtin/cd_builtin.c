/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:33:59 by oozsertt          #+#    #+#             */
/*   Updated: 2022/01/05 14:59:01 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

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

static int	multiple_args(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (i > 1)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	change_pwd_env(t_env *env, char *pwd)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (find_env_var(tmp->var, "PWD=") == TRUE)
		{
			free(tmp->var);
			tmp->var = ft_strjoin("PWD=", pwd);
		}
		tmp = tmp->next;
	}
}

void	cd_builtin(t_cmd *cmd, t_env **env)
{
	char	**directories;
	char	*pwd;

	directories = NULL;
	pwd = NULL;
	pwd = getcwd(NULL, 0);
	if (multiple_args(cmd->cmd) == TRUE)
		ft_putstr_fd("bash: cd: too many arguments\n", cmd->output);
	else if (cmd->cmd[1] == NULL)
		cd_to_home(*env, pwd);
	else
	{
		if (cmd->cmd[1][0] == '/')
			move_to_root(*env);
		else
		{
			directories = ft_split(cmd->cmd[1], '/');
			check_and_move_directory(directories, pwd);
		}
	}
	free(pwd);
	pwd = getcwd(NULL, 0);
	change_pwd_env(*env, pwd);
	free(pwd);
}
