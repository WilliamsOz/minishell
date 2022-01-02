/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:07:10 by user42            #+#    #+#             */
/*   Updated: 2022/01/01 23:13:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_STRUCTURE_H
# define CMD_STRUCTURE_H

typedef struct g_cmd
{
	char			**cmd;
	char			*path;
	int				input;
	int				output;
	int				pipes[2];
	struct g_cmd	*next;
	struct g_cmd	*previous;
}				t_cmd;

#endif