/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_hexadecimal(unsigned long long uns_nr, short spec)
{
	if (g_flag[9])
		print_diez();
	if ((spec == 4 && sizeof(long int) == 4) || (spec == 12 &&
				sizeof(size_t) == 4))
		ft_print_hex_ui(uns_nr);
	else if (spec < 5 || spec > 10)
		ft_print_hex_ul(uns_nr);
	else
		ft_print_hex_ui(uns_nr);
}

void	ft_print_octal(unsigned long long uns_nr, short spec)
{
	if (g_flag[9])
		print_diez();
	if ((spec == 4 && sizeof(long int) == 4) || (spec == 12 &&
				sizeof(size_t) == 4))
		ft_print_oct_ui(uns_nr);
	else if (spec < 5 || spec > 10)
		ft_print_oct_ul(uns_nr);
	else
		ft_print_oct_ui(uns_nr);
}

void	select_ft_put(unsigned long long uns_nr, short spec)
{
	if (spec == 31)
		ft_putchar(uns_nr);
	else if (spec == 34)
		ft_putchar_fd(uns_nr, 1);
	else if (!g_flag[7])
		ft_putnbr(uns_nr);
	else if (g_flag[7] == 1)
		ft_print_hexadecimal(uns_nr, spec);
	else if (g_flag[7] == 2)
		ft_print_octal(uns_nr, spec);
}

void	print_diez(void)
{
	if (g_flag[7] == 1 && g_small)
		ft_putstr("0x");
	if (g_flag[7] == 1 && !g_small)
		ft_putstr("0X");
	if (g_flag[7] == 2)
		ft_putchar('0');
	g_flag[9] = 0;
}
