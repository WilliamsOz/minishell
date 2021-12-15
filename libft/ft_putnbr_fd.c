/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:46:51 by user42            #+#    #+#             */
/*   Updated: 2021/12/15 12:47:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_intlen(long nbr)
{
	int		i;
	long	len;

	i = 1;
	len = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	while (--i > 0)
		len *= 10;
	return (len);
}

void			ft_putnbr_fd(int n, int fd)
{
	char	res[10];
	long	nbr;
	int		i;
	long	cc;

	nbr = n;
	i = -1;
	cc = 0;
	while (++i < 10)
		res[i] = '\0';
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	i = 0;
	cc = ft_intlen(nbr);
	while (cc > 0)
	{
		res[i] = ('0' + ((nbr / cc) % 10));
		write(fd, &res[i], 1);
		cc /= 10;
		i++;
	}
}
