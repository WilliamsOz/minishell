/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:07:10 by user42            #+#    #+#             */
/*   Updated: 2021/12/29 19:24:02 by wiozsert         ###   ########.fr       */
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