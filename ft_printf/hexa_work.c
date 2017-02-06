/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_hexa_ui(unsigned n)
{
	const char *base_s = "0123456789abcdef";
	const char *base_l = "0123456789ABCDEF";

	if (n >> 4)
		ft_hexa_ui(n >> 4);
	if (g_small)
		ft_putchar(base_s[n % 16]);
	else
		ft_putchar(base_l[n % 16]);
}

void	ft_hexa_ul(unsigned long long n)
{
	const char *base_s = "0123456789abcdef";
	const char *base_l = "0123456789ABCDEF";

	if (n >> 4)
		ft_hexa_ul(n >> 4);
	if (g_small)
		ft_putchar(base_s[n % 16]);
	else
		ft_putchar(base_l[n % 16]);
}

void	ft_hexa(unsigned long long n)
{
	const char *base_s = "0123456789abcdef";
	const char *base_l = "0123456789ABCDEF";

	g_flag[6]++;
	if (n >> 4 && g_flag[6] < g_flag[5] * 2)
		ft_hexa(n >> 4);
	if (g_small)
		ft_putchar(base_s[n % 16]);
	else
		ft_putchar(base_l[n % 16]);
}

void	ft_print_hex_ui(unsigned n)
{
	g_flag[6] = 0;
	if (n == 0)
		ft_putchar('0');
	else
		ft_hexa_ui(n);
}

void	ft_print_hex_ul(unsigned long long n)
{
	g_flag[6] = 0;
	if (n == 0)
		ft_putchar('0');
	else
		ft_hexa_ul(n);
}
