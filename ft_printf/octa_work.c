/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octa_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_octal_ui(unsigned n)
{
	const char *base_o = "01234567";

	if (n >> 3)
		ft_octal_ui(n >> 3);
	ft_putchar(base_o[n % 8]);
}

void	ft_octal_ul(unsigned long long n)
{
	const char *base_o = "01234567";

	if (n >> 3)
		ft_octal_ul(n >> 3);
	ft_putchar(base_o[n % 8]);
}

int		g_o_ui_l(unsigned n)
{
	g_flag[6]++;
	if (n >> 3)
		g_o_ui_l(n >> 3);
	return (g_flag[6]);
}

int		g_o_ul_l(unsigned long long n)
{
	g_flag[6]++;
	if (n >> 3)
		g_o_ul_l(n >> 3);
	return (g_flag[6]);
}

void	ft_print_oct_ui(unsigned n)
{
	g_flag[6] = 0;
	if (n == 0)
		ft_putchar('0');
	else
		ft_octal_ui(n);
}
