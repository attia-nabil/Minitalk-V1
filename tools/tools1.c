/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:54:40 by nattia            #+#    #+#             */
/*   Updated: 2022/01/14 15:54:44 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *s1)
{
	int		i;
	char	*rtn;

	rtn = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	i = -1;
	while (s1[++i])
		rtn[i] = s1[i];
	rtn[i] = '\0';
	free(s1);
	return (rtn);
}

static int	sign_and_len(int *n, int *t, int *s)
{
	int	l;

	l = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		*s = 1;
	}
	while (*t)
	{
		*t = *t / 10;
		l++;
	}
	return (l + *s);
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		s;
	int		t;
	int		l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!n)
		return (ft_strdup("0"));
	t = n;
	s = 0;
	l = sign_and_len(&n, &t, &s);
	rtn = (char *)malloc(sizeof(char) * l + 1);
	if (!rtn)
		return (NULL);
	rtn[l] = '\0';
	while (l--)
	{
		rtn[l] = (n % 10) + '0';
		n = n / 10;
	}
	if (s)
		rtn[0] = '-';
	return (rtn);
}
