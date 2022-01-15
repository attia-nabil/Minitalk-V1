/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:54 by nattia            #+#    #+#             */
/*   Updated: 2022/01/14 15:53:56 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	chr_to_bin(pid_t server_pid, char chr)
{
	int	i;
	int	bit;

	i = 8;
	bit = 0;
	if (chr < 0 || chr > 127)
		return ;
	while (i--)
	{
		bit = (chr >> i) & 1;
		if (bit == 1)
			kill (server_pid, SIGUSR1);
		if (bit == 0)
			kill (server_pid, SIGUSR2);
		usleep(100);
	}
}

static void	send_text(pid_t server_pid, char *txt)
{
	int		i;

	i = -1;
	while (txt[++i])
		chr_to_bin(server_pid, txt[i]);
	chr_to_bin(server_pid, 0);
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_putstr("\n\e[32m[+]\e[0m Usage : ./client \e[33m<server_pid> ", 0);
		ft_putstr("\e[0m\"text to send\"\n", 1);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_putstr("\n\e[31m[-]\e[0m Invalid PID!\n", 1);
		exit(EXIT_FAILURE);
	}
	send_text(server_pid, av[2]);
	exit(EXIT_SUCCESS);
}
