/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_nbr_2(short spec, int *abs_length, int length, long long ll)
{
	if ((spec % 2 == 1) && ll < 0)
		*abs_length = length - 1;
	else
		*abs_length = length;
	if (g_flag[0] || g_flag[1])
		g_flag[3]--;
	if ((g_flag[4] - *abs_length) > 0)
		g_flag[4] = g_flag[4] - *abs_length;
	else
		g_flag[4] = 0;
	if ((g_flag[3] - (g_flag[4] + length)) > 0)
		g_flag[3] = g_flag[3] - (g_flag[4] + length);
	else
		g_flag[3] = 0;
}

void	print_nbr(va_list *mylist, short spec)
{
	int		length;
	int		abs_length;
	t_un	uni;

	if (g_flag[12])
		uni.ll = (long long)va_arg(*mylist, void*);
	else
		uni.ll = get_from_list(mylist, spec);
	if (!(g_flag[8] && g_flag[4] == 0 && uni.ll == 0))
		g_flag[8] = 0;
	if (g_flag[9] && uni.ll == 0 && !g_flag[12])
		g_flag[9] = 0;
	if (g_flag[9] && g_flag[7] == 1)
		g_flag[3] -= 2;
	if (g_flag[9] && g_flag[7] == 2)
		g_flag[3]--;
	if (uni.ll < 0)
		g_flag[0] = -1;
	length = get_length(&uni, spec);
	print_nbr_2(spec, &abs_length, length, uni.ll);
	check_flag_array(uni.ll, spec);
}

short	set_pointer(void)
{
	if (g_flag[9] && g_flag[11])
		g_flag[8] = 2;
	g_small = 1;
	g_flag[7] = 1;
	g_flag[12] = 1;
	g_flag[9] = 1;
	return (2);
}

void	ft_negate(long long *nr, unsigned long long *uns_nr, short spec)
{
	if (*nr < 0 && (spec % 2 == 1))
	{
		ft_putchar('-');
		*uns_nr = -(*nr);
	}
	else
		*uns_nr = *nr;
}
