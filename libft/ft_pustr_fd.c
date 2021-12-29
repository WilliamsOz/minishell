/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:37:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/28 22:58:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

#include <stdio.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	// printf("%s\n", str);
	// printf("%d\n", fd);
	write(fd, str, len);
}