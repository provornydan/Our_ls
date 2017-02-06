/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_work2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_hex_ui_l(unsigned n)
{
	g_flag[6]++;
	if (n >> 4)
		g_hex_ui_l(n >> 4);
	return (g_flag[6]);
}

int		g_hex_ul_l(unsigned long long n)
{
	g_flag[6]++;
	if (n >> 4)
		g_hex_ul_l(n >> 4);
	return (g_flag[6]);
}

void	ft_binar(unsigned long long n)
{
	const char *base = "01";

	if (n >> 1)
		ft_binar(n >> 1);
	ft_putchar(base[n % 2]);
}

int		get_length_hex_ui(unsigned n)
{
	g_flag[6] = 0;
	return (g_hex_ui_l(n));
}

int		get_length_hex_ul(unsigned long long n)
{
	g_flag[6] = 0;
	return (g_hex_ul_l(n));
}
