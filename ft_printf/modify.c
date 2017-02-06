/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	modify_dot(void)
{
	g_flag[2] = 0;
	if (g_flag[3] && !g_flag[9])
		g_flag[8] = 1;
	else if (!g_flag[9])
		g_flag[8] = 2;
	else
		g_flag[11] = 1;
	g_jump++;
	return (4);
}

void	modify_plus(void)
{
	g_flag[0] = -1;
	g_flag[1] = 1;
}

void	modify_zero(void)
{
	g_flag[10] = 1;
	g_flag[2] = 1;
	g_flag[13] = 1;
}

short	modify_percent(const char *s)
{
	if (!g_flag[3])
		ft_putchar('%');
	else
	{
		g_flag[3]--;
		if (g_flag[13])
			g_flag[2] = 1;
		g_flag[8] = 0;
		check_flag_array(s[g_jump], 31);
	}
	return (0);
}
