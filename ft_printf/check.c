/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:46 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_char(const char *s)
{
	if (s[g_jump] == '+')
		modify_plus();
	else if (s[g_jump] == '-')
		g_flag[5] = 1;
	else if (s[g_jump] == '0')
		modify_zero();
	else if (s[g_jump] == '#')
		g_flag[9] = 1;
	else if (s[g_jump] == '.')
		return (modify_dot());
	else if (s[g_jump] == '%')
		return (modify_percent(s));
	else if (s[g_jump] >= '1' && s[g_jump] <= '9')
		return (3);
	else
	{
		g_flag[3]--;
		if (g_flag[13])
			g_flag[2] = 1;
		g_flag[8] = 0;
		check_flag_array(s[g_jump], 31);
		return (0);
	}
	return (1);
}

void	init2(void)
{
	g_flag[4] = 0;
	g_flag[8] = 0;
}

short	check_single(const char *s)
{
	if (s[g_jump] == 's')
		return (30);
	if (s[g_jump] == 'S')
		return (33);
	if (s[g_jump] == 'C' || s[g_jump] == 'c')
	{
		if (g_flag[13])
			g_flag[2] = 1;
		init2();
	}
	if (s[g_jump] == 'C')
		return (34);
	if (s[g_jump] == 'c')
		return (31);
	if (s[g_jump] == 'd' || s[g_jump] == 'i')
		return (5);
	if (s[g_jump] == 'D')
		return (3);
	if (s[g_jump] == 'u' || s[g_jump] == 'U')
		delete_sign();
	if (s[g_jump] == 'u')
		return (6);
	if (s[g_jump] == 'U')
		return (4);
	return (0);
}

short	is_spec(const char *s)
{
	short result;

	result = check_single(s);
	if (result)
		return (result);
	if (s[g_jump] == 'p')
		return (set_pointer());
	result = check_ox(s);
	if (result)
		return (result);
	result = check_h_spec(s);
	if (result)
		return (result);
	result = check_l_spec(s);
	if (result)
		return (result);
	result = check_z_spec(s);
	if (result)
		return (result);
	result = check_j_spec(s);
	if (result)
		return (result);
	return (0);
}

short	check_lc(const char *s)
{
	if (s[g_jump + 1] == 'c' || s[g_jump + 1] == 'C')
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
