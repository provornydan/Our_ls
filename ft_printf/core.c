/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	skip(const char *s)
{
	if (s[g_jump] == 32)
	{
		if (g_flag[0] != -1)
			g_flag[0] = 1;
		while (s[g_jump] == 32)
			g_jump++;
	}
}

int		skip_space(const char *s, va_list *mylist)
{
	short spec;

	g_jump++;
	if (!s[g_jump])
	{
		--g_jump;
		return (0);
	}
	skip(s);
	if (!s[g_jump])
	{
		--g_jump;
		return (0);
	}
	spec = is_spec(s);
	if (spec)
	{
		if (spec == 30 || spec == 33)
			print_str(mylist, spec);
		else
			print_nbr(mylist, spec);
		return (0);
	}
	return (check_char(s));
}

void	print_letter(const char *s, va_list *mylist)
{
	int cs;

	if (s[g_jump] == '%')
	{
		reset_flags();
		while ((cs = skip_space(s, mylist)) && cs)
		{
			if (!cs)
				g_jump++;
			else if (cs == 1)
				continue;
			else
				g_flag[cs] = ft_atoi(s);
		}
	}
	else
		ft_putchar(s[g_jump]);
}
