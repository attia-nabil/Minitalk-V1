/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:16 by nattia            #+#    #+#             */
/*   Updated: 2022/01/14 15:53:20 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include <unistd.h>

void			ft_putstr(const char *s, int nl);
void			ft_putnbr(unsigned int n);
unsigned int	ft_atoi(const char *s);
char			*ft_itoa(int n);

#endif
