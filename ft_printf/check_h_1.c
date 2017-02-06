/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_h_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:53:22 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	check_h_spec_2(const char *s)
{
	if (s[g_jump + 1] == 'd' || s[g_jump + 1] == 'i')
	{
		++g_jump;
		return (7);
	}
	if (s[g_jump + 1] == 'D')
	{
		++g_jump;
		return (3);
	}
	if (s[g_jump + 1] == 'u')
	{
		delete_sign();
		++g_jump;
		return (8);
	}
	if (s[g_jump + 1] == 'U')
	{
		delete_sign();
		++g_jump;
		return (4);
	}
	return (0);
}

short	check_h_spec_3(const char *s)
{
	if (s[g_jump + 1] == 'x')
	{
		++g_jump;
		g_small = 1;
		g_flag[7] = 1;
		return (8);
	}
	if (s[g_jump + 1] == 'X')
	{
		++g_jump;
		g_small = 0;
		g_flag[7] = 1;
		return (8);
	}
	if (s[g_jump + 1] == 'o')
	{
		if (g_flag[11] && g_flag[9])
			g_flag[4]--;
		++g_jump;
		g_flag[7] = 2;
		return (8);
	}
	return (0);
}

short	check_h_spec_4(const char *s)
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
		++g_jump;
		g_flag[4] = 0;
		if (g_flag[13])
			g_flag[2] = 1;
		g_flag[8] = 0;
		return (34);
	}
	return (0);
}

short	check_h_spec_5(const char *s)
{
	if (s[g_jump + 1] == 'd' || s[g_jump + 1] == 'i')
	{
		++g_jump;
		return (9);
	}
	if (s[g_jump + 1] == 'D')
	{
		++g_jump;
		return (3);
	}
	if (s[g_jump + 1] == 'u')
	{
		delete_sign();
		++g_jump;
		return (10);
	}
	if (s[g_jump + 1] == 'U')
	{
		delete_sign();
		++g_jump;
		return (4);
	}
	return (0);
}

short	check_h_spec(const char *s)
{
	short result;

	if (s[g_jump] == 'h')
	{
		if ((result = check_h_spec_2(s)) && result)
			return (result);
		if ((result = check_h_spec_3(s)) && result)
			return (result);
		if ((result = check_h_spec_4(s)) && result)
			return (result);
		if (s[g_jump + 1] == 'h')
		{
			++g_jump;
			if ((result = check_h_spec_5(s)) && result)
				return (result);
			if ((result = check_h_spec_6(s)) && result)
				return (result);
			if ((result = check_h_spec_7(s)) && result)
				return (result);
		}
	}
	return (0);
}
