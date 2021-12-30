/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:29:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/30 13:35:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	not_found(char *path, char *path_cmd)
{
	free(path_cmd);
	free(path);
}

static int	move_to_value(char *env, int i)
{
	while (env[i] != '\0' && env[i] != '=')
		i++;
	if (env[i] == '=')
		i++;
	return (i);
}

static int	get_len(char *env, int **ptr_i)
{
	int	len;

	len = 0;
	while (env[**ptr_i] != '\0' && env[**ptr_i] != ':')
	{
		**ptr_i += 1;
		len++;
	}
	if (env[**ptr_i] == ':')
		**ptr_i += 1;
	return (len);
}

void	mall_new_path_failed(t_minishell *m)
{
	strerror(errno);
	env_destructor(m->env);
	cmd_destructor(m->cmd);
	m = destroy_all_data(m);
	exit (errno);
}

static char	*cpy_new_path(char *env, char *path, int i, int j)
{
	while (env[i] != '\0' && env[i] != ':')
	{
		path[j] = env[i];
		i++;
		j++;
	}
	return (path);
}

static char	*get_new_path(t_minishell *m, char *path, char *env, int *ptr_i)
{
	int	len;
	int	tmp;

	len = 0;
	if (*ptr_i == 0)
		*ptr_i = move_to_value(env, *ptr_i);
	tmp = *ptr_i;
	len = get_len(env, &ptr_i);
	if (len == 0)
		return (NULL);
	path = (char *)malloc(sizeof(char) * (len + 2));
	if (path == NULL)
		mall_new_path_failed(m);
	path[len] = '/';
	path[len + 1] = '\0';
	path = cpy_new_path(env, path, tmp, 0);
	return (path);
}

static char	*get_cmd_path(t_minishell *m, char *cmd, t_env *tmp_env, int i)
{
	char	*path_cmd;
	char	*path;

	path_cmd = NULL;
	path = NULL;
	while (tmp_env != NULL)
	{
		while (tmp_env->var[i] != '\0')
		{
			path = get_new_path(m, path, tmp_env->var, &i);
			path_cmd = ft_strjoin(path, cmd);
			if (access(path_cmd, F_OK | X_OK) == 0)
			{
				free(path);
				return (path_cmd);
			}
			else
				not_found(path, path_cmd);
		}
		tmp_env = tmp_env->next;
		i = 0;
	}
	return (path_cmd);
}

t_cmd	*find_and_get_path_cmd(t_minishell *m, t_cmd *cmd, t_env *env)
{
	t_cmd	*tmp_cmd;
	t_env	*tmp_env;

	cmd = init_cmd_path(cmd);
	tmp_cmd = cmd;
	while (tmp_cmd != NULL)
	{
		tmp_env = env;
		tmp_cmd->path = get_cmd_path(m, tmp_cmd->cmd[0], tmp_env, 0);
		tmp_cmd = tmp_cmd->next;
	}
	return (cmd);
}
