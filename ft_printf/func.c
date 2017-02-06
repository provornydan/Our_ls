/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:53:26 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	reset_flags(void)
{
	int i;

	i = -1;
	while (++i < 14)
		g_flag[i] = 0;
}

void	reset_bratan(void)
{
	g_jump = -1;
	g_cont = 0;
	g_small = -1;
	reset_flags();
}

void	delete_sign(void)
{
	g_flag[3]++;
	g_flag[0] = -1;
	g_flag[1] = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	++g_cont;
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
