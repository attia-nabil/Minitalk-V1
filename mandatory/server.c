/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:54:03 by nattia            #+#    #+#             */
/*   Updated: 2022/01/14 15:54:06 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_text(int sig)
{
	static char	buf = 0;
	static int	bit = 7;

	if (sig == SIGUSR1)
		buf |= (1 << bit);
	if (sig == SIGUSR2)
		buf |= 0;
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (buf)
		{
			write(1, &buf, 1);
			buf = 0;
		}
		else
			write(1, "\n", 1);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("\n\e[33mPID : ", 0);
	ft_putnbr(pid);
	ft_putstr("\e[0m\n", 1);
	while (TRUE)
	{
		signal(SIGUSR1, receive_text);
		signal(SIGUSR2, receive_text);
		pause();
	}
	exit(EXIT_SUCCESS);
}
