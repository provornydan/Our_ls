/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octa_work2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_oct_ul(unsigned long long n)
{
	g_flag[6] = 0;
	if (n == 0)
		ft_putchar('0');
	else
		ft_octal_ul(n);
}

int		get_length_oct_ui(unsigned n)
{
	g_flag[6] = 0;
	return (g_o_ui_l(n));
}

int		get_length_oct_ul(unsigned long long n)
{
	g_flag[6] = 0;
	return (g_o_ul_l(n));
}
