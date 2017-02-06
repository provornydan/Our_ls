/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	check_o(const char *s)
{
	if (s[g_jump] == 'o')
	{
		if (g_flag[11] && g_flag[9])
			g_flag[4]--;
		g_flag[7] = 2;
		return (6);
	}
	if (s[g_jump] == 'O')
	{
		if (g_flag[11] && g_flag[9])
			g_flag[4]--;
		g_flag[7] = 2;
		return (4);
	}
	return (0);
}

short	check_ox(const char *s)
{
	short result;

	if (s[g_jump] == 'x')
	{
		if (g_flag[9] && g_flag[11])
			g_flag[8] = 2;
		g_small = 1;
		g_flag[7] = 1;
		return (6);
	}
	if (s[g_jump] == 'X')
	{
		if (g_flag[9] && g_flag[11])
			g_flag[8] = 2;
		g_small = 0;
		g_flag[7] = 1;
		return (6);
	}
	result = check_o(s);
	if (result)
		return (result);
	return (0);
}
