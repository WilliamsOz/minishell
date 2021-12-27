/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:32:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/12/27 16:03:11 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0

char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
int		get_next_line(int fd, char **line);
void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char *s, char c);

#endif