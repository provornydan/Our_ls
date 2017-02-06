/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	check_hx(const char *s)
{
	if (s[g_jump + 1] == 'x')
	{
		++g_jump;
		g_small = 1;
		g_flag[7] = 1;
		return (10);
	}
	if (s[g_jump + 1] == 'X')
	{
		++g_jump;
		g_small = 0;
		g_flag[7] = 1;
		return (10);
	}
	return (0);
}

short	check_h_spec_6(const char *s)
{
	short result;

	result = check_hx(s);
	if (result)
		return (result);
	if (s[g_jump + 1] == 'o')
	{
		if (g_flag[11] && g_flag[9])
			g_flag[4]--;
		++g_jump;
		g_flag[7] = 2;
		return (10);
	}
	if (s[g_jump + 1] == 'S')
	{
		++g_jump;
		return (33);
	}
	return (0);
}

short	check_h_spec_7(const char *s)
{
	if (s[g_jump + 1] == 'O')
	{
		if (g_flag[11] && g_flag[9])
			g_flag[4]--;
		++g_jump;
		g_flag[7] = 2;
		return (4);
	}
	if (s[g_jump + 1] == 'p')
	{
		++g_jump;
		return (set_pointer());
	}
	if (s[g_jump + 1] == 'C')
	{
		if (g_flag[13])
			g_flag[2] = 1;
		g_flag[4] = 0;
		++g_jump;
		g_flag[8] = 0;
		return (34);
	}
	return (0);
}
