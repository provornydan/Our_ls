/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:33 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_wstr_minus(wchar_t *wstr, int length)
{
	int	i;
	int	len;

	i = 0;
	while (i < length && *wstr)
	{
		len = ft_wlen(*wstr);
		if (i + len <= length)
			ft_putchar_fd(*wstr, 1);
		i += len;
		wstr++;
	}
	i = -1;
	while (++i < g_flag[3])
		ft_putchar(' ');
}

void	ft_print_str_minus(char *str, int length)
{
	int	i;

	i = -1;
	while (++i < length && str[i])
		ft_putchar(str[i]);
	i = -1;
	while (++i < g_flag[3])
		ft_putchar(' ');
}

void	ft_print_wstr_width(wchar_t *wstr, int length)
{
	int	i;
	int	len;

	i = -1;
	while (++i < g_flag[3])
	{
		if (g_flag[10])
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	i = 0;
	while (i < length && *wstr)
	{
		len = ft_wlen(*wstr);
		if (i + len <= length)
			ft_putchar_fd(*wstr, 1);
		i += len;
		wstr++;
	}
}

void	ft_print_str_width(char *str, int length)
{
	int	i;

	i = -1;
	while (++i < g_flag[3])
	{
		if (g_flag[10])
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	i = -1;
	while (++i < length && str[i])
		ft_putchar(str[i]);
}
