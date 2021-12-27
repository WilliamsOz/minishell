/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:07:10 by user42            #+#    #+#             */
/*   Updated: 2021/12/27 15:52:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_STRUCTURE_H
# define CMD_STRUCTURE_H

typedef struct g_cmd
{
	char			**cmd;
	int				input;
	int				output;
	struct g_cmd	*next;
}				t_cmd;

#endif