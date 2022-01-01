/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:18:38 by user42            #+#    #+#             */
/*   Updated: 2022/01/01 20:13:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_STRUCTURE_H
# define ENV_STRUCTURE_H

typedef struct g_env
{
	char			*var;
	struct g_env	*next;
}				t_env;

#endif