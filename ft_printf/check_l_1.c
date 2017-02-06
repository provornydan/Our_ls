/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_l_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	check_l_spec(const char *s)
{
	short result;

	if (s[g_jump] == 'l')
	{
		if ((result = check_l_spec_2(s)) && result)
			return (result);
		if ((result = check_l_spec_3(s)) && result)
			return (result);
		if (s[g_jump + 1] == 'l')
		{
			++g_jump;
			if ((result = check_l_spec_4(s)) && result)
				return (result);
			if ((result = check_l_spec_5(s)) && result)
				return (result);
		}
	}
	return (0);
}

short	check_l_spec_2(const char *s)
{
	if (s[g_jump + 1] == 'd' || s[g_jump + 1] == 'D' || s[g_jump + 1] == 'i')
	{
		++g_jump;
		return (3);
	}
	if (s[g_jump + 1] == 'u' || s[g_jump + 1] == 'U')
	{
		delete_sign();
		++g_jump;
		return (4);
	}
	if (s[g_jump + 1] == 'x')
	{
		++g_jump;
		g_small = 1;
		g_flag[7] = 1;
		return (4);
	}
	if (s[g_jump + 1] == 's')
	{
		++g_jump;
		return (33);
	}
	return (0);
}

short	check_l_spec_3(const char *s)
{
	if (s[g_jump + 1] == 'X')
	{
		++g_jump;
		g_small = 0;
		g_flag[7] = 1;
		return (4);
	}
	if (s[g_jump + 1] == 'o' || s[g_jump + 1] == 'O')
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
	if (check_lc(s))
		return (34);
	return (0);
}

short	check_l_spec_4(const char *s)
{
	if (s[g_jump + 1] == 'u' || s[g_jump + 1] == 'U')
	{
		delete_sign();
		++g_jump;
		return (2);
	}
	if (s[g_jump + 1] == 'd' || s[g_jump + 1] == 'D' || s[g_jump + 1] == 'i')
	{
		++g_jump;
		return (1);
	}
	if (s[g_jump + 1] == 'x')
	{
		++g_jump;
		g_small = 1;
		g_flag[7] = 1;
		return (2);
	}
	return (0);
}

short	check_l_spec_5(const char *s)
{
	if (s[g_jump + 1] == 'X')
	{
		++g_jump;
		g_small = 0;
		g_flag[7] = 1;
		return (2);
	}
	if (s[g_jump + 1] == 'o' || s[g_jump + 1] == 'O')
	{
		if (g_flag[11] && g_flag[9])
			g_flag[4]--;
		++g_jump;
		g_flag[7] = 2;
		return (2);
	}
	if (s[g_jump + 1] == 'p')
	{
		++g_jump;
		return (set_pointer());
	}
	if (check_lc(s))
		return (34);
	return (0);
}
