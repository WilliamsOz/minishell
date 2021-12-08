/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_token_structure.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:45:28 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/08 14:58:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIM_TOKEN_STRUCTURE_H
# define TRIM_TOKEN_STRUCTURE_H

typedef struct s_trim
{
	char		*before_quote;
	char		*between_quote;
	char		*after_quote;
}				t_trim;

#endif