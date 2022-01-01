// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cd_builtin.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/22 21:33:59 by oozsertt          #+#    #+#             */
// /*   Updated: 2021/12/27 15:42:11 by oozsertt         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// /////////////////// DO THE RM -RF CURRENT DIRECTORY CASE

#include "../../inc/minishell.h"
#include <sys/types.h>
#include <dirent.h>

static int	check_and_move_directory(char **directories, char *originalpwd)
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
			return (-1);
		}
		if (access(directories[i], X_OK) == -1)
		{
			ft_putstr_fd("bash: cd: ", STDERR_FILENO);
			ft_putstr_fd(directories[i], STDERR_FILENO);
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
			chdir(originalpwd);
			return (-1);
		}
		chdir(directories[i]);
		i++;
	}
	return (0);
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

static int		find_pwd(char *var, char *pwd_header)
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

static void	change_pwd_env(t_env *env, char *pwd)
{
	t_env	*tmp;
	// char	*full_pwd;

	(void)pwd;
	tmp = env;
	while (env != NULL)
	{
		if (find_pwd(env->var, "PWD=") == TRUE)
		{
			free(env->var);
			// full_pwd = ft_strjoin("PWD=", pwd);
		}
		env = env->next;
	}
	env = tmp;
}

void	cd_builtin(t_cmd *cmd, t_env **env) // add t_env **env
{
	char	**directories;
	char	*pwd;

	if (multiple_args(cmd->cmd) == TRUE)
		ft_putstr_fd("bash: cd: too many arguments\n", cmd->output);
	else
	{
		pwd = getcwd(NULL, 0);
		if (cmd->cmd[0][0] == '/')
			chdir("/");
		directories = ft_split(cmd->cmd[1], '/');
		if (check_and_move_directory(directories, pwd) == -1)
			exit (EXIT_FAILURE); // TO FREE
		pwd = getcwd(NULL, 0);
		change_pwd_env(*env, pwd);
	}
}
// ///////////////////////// TO FINISH WITH ENV LINKED LIST ///////////////////////