/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:54:27 by nattia            #+#    #+#             */
/*   Updated: 2022/01/14 15:54:30 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putstr(const char *s, int nl)
{
	while (s && *s)
		write(1, s++, 1);
	if (nl)
		write(1, "\n", 1);
}

void	ft_putnbr(unsigned int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

unsigned int	ft_atoi(const char *s)
{
	unsigned int	i;
	unsigned int	r;

	i = 0;
	r = 0;
	while (s[i] >= '0' && s[i] <= '9')
		r = (r * 10) + (s[i++] - '0');
	return (r);
}
