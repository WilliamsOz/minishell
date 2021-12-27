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

// #include "../../inc/minishell.h"
// #include <sys/types.h>
// #include <dirent.h>

// static int	check_and_move_directory(char **directories, char *originalpwd)
// {
// 	int		i;

// 	i = 0;
// 	while (directories[i] != NULL)
// 	{
// 		if (access(directories[i], F_OK) == -1)
// 		{
// 			ft_putstr_fd("bash: cd: ", STDERR_FILENO);
// 			ft_putstr_fd(directories[i], STDERR_FILENO);
// 			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
// 			chdir(originalpwd);
// 			return (-1);
// 		}
// 		if (access(directories[i], X_OK) == -1)
// 		{
// 			ft_putstr_fd("bash: cd: ", STDERR_FILENO);
// 			ft_putstr_fd(directories[i], STDERR_FILENO);
// 			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
// 			chdir(originalpwd);
// 			return (-1);
// 		}
// 		chdir(directories[i]);
// 		i++;
// 	}
// 	return (0);
// }

// void	cd_builtin(char *path) // add t_env **env
// {
// 	DIR		*dir;
// 	struct dirent	*dent;
// 	char	**directories;
// 	char	*pwd;

// 	pwd = getcwd(NULL, 0);
// 	if (path[0] == '/')
// 		chdir("/");
// 	directories = ft_split(path, '/');
// 	if (check_and_move_directory(directories, pwd) == -1)
// 		exit (EXIT_FAILURE); // TO FREE
// 	pwd = getcwd(NULL, 0);
// }
// ///////////////////////// TO FINISH WITH ENV LINKED LIST ///////////////////////
// ///////////////////////// DEAL multiple arguments //////////////////////////////