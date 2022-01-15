/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:52:07 by nattia            #+#    #+#             */
/*   Updated: 2022/01/14 15:52:17 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_pid(pid_t *pid, int sig)
{
	static char	s_pid[MAX_SIZE] = {'\0'};
	static int	bit = 7;
	static int	i = 0;
	static int	j = -1;

	if (sig == SIGUSR1)
		s_pid[i] |= (1 << bit);
	if (sig == SIGUSR2)
		s_pid[i] |= 0;
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if ((s_pid)[i] == '\0')
		{
			*pid = ft_atoi(s_pid);
			while (++j < MAX_SIZE)
				s_pid[j] = 0;
			i = 0;
		}
		else
			i++;
		j = -1;
	}
}

static void	generate_text(pid_t *pid, int sig)
{
	static int		bit = 7;
	static wchar_t	buf = 0;

	if (sig == SIGUSR1)
		buf |= (1 << bit);
	if (sig == SIGUSR2)
		buf |= 0;
		bit--;
	if (bit == -1)
	{
		bit = 7;
		if (!buf && *pid)
		{
			kill (*pid, SIGUSR1);
			*pid = 0;
		}
		if (buf)
		{
			write(1, &buf, 1);
			buf = 0;
		}
		else
			write(1, "\n", 1);
	}
}

static void	receive_text(int sig)
{
	static pid_t			pid = 0;

	if (!pid)
		get_pid(&pid, sig);
	else
		generate_text(&pid, sig);
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
	return (0);
}
