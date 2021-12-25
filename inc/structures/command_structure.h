/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:07:10 by user42            #+#    #+#             */
/*   Updated: 2021/12/25 13:09:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_STRUCTURE_H
# define  COMMAND_STRUCTURE_H


typedef struct g_cmd
{
	char			**cmd;
	int				input;
	int				output;
	struct g_cmd	*next;
}				t_cmd;

#endif