/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_f_array_2(short spec)
{
	int i;

	i = -1;
	if (g_flag[0] == 1 && !g_flag[7] && spec != 31 && spec != 34)
		ft_putchar(' ');
	while (++i < g_flag[3] && !g_flag[5])
		if (!g_flag[2])
			ft_putchar(' ');
}

void	check_f_array_3(void)
{
	int i;

	i = -1;
	if (!g_flag[5])
	{
		if (g_flag[3] && g_flag[2] && g_flag[9])
			print_diez();
		while (++i < g_flag[3])
			if (g_flag[2])
				ft_putchar('0');
	}
}

void	check_diez(short spec)
{
	int i;

	i = -1;
	if (spec != 31 && spec != 34)
	{
		if (g_flag[4] && g_flag[9])
			print_diez();
		while (++i < g_flag[4])
			ft_putchar('0');
	}
}

void	check_flag_array(long long nr, short spec)
{
	int					i;
	unsigned long long	uns_nr;

	check_f_array_2(spec);
	ft_negate(&nr, &uns_nr, spec);
	if (g_flag[1] && !g_flag[7] && spec != 31 && spec != 34)
		ft_putchar('+');
	check_f_array_3();
	check_diez(spec);
	if (g_flag[8] == 1)
	{
		ft_putchar(' ');
		if (g_flag[12])
			ft_putstr("0x");
	}
	else if (g_flag[8] != 2)
		select_ft_put(uns_nr, spec);
	else if (g_flag[12])
		ft_putstr("0x");
	i = -1;
	while (++i < g_flag[3] && g_flag[5])
		ft_putchar(' ');
}
