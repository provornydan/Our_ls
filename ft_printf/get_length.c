/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_length_hexadecimal(unsigned long long uns_temp, short spec)
{
	if ((spec == 4 && sizeof(long int) == 4) || (spec == 12 &&
		sizeof(size_t) == 4))
		return (get_length_hex_ui(uns_temp));
	if (spec < 5 || spec > 10)
		return (get_length_hex_ul(uns_temp));
	return (get_length_hex_ui(uns_temp));
}

int		get_length_octal(unsigned long long uns_temp, short spec)
{
	if ((spec == 4 && sizeof(long int) == 4) || (spec == 12 &&
		sizeof(size_t) == 4))
		return (get_length_oct_ui(uns_temp));
	if (spec < 5 || spec > 10)
		return (get_length_oct_ul(uns_temp));
	return (get_length_oct_ui(uns_temp));
}

int		get_length_2(long long temp, unsigned long long uns_temp, short spec)
{
	int i;

	i = 0;
	if (spec % 2 == 1)
	{
		if (temp < 0)
		{
			g_flag[0] = 0;
			g_flag[1] = 0;
			i++;
		}
		while (temp)
		{
			temp = temp / 10;
			i++;
		}
	}
	else if (spec % 2 == 0)
		while (uns_temp)
		{
			uns_temp = uns_temp / 10;
			i++;
		}
	return (i);
}

int		get_length(t_un *uni, short spec)
{
	long long			temp;
	unsigned long long	uns_temp;
	int					i;

	i = 0;
	if (uni->ll == 0 || spec == 31 || spec == 34)
		return (1);
	uni->ll = get_data_type(uni, spec);
	temp = uni->ll;
	uns_temp = uni->ull;
	if (g_flag[7] == 1)
		return (get_length_hexadecimal(uns_temp, spec));
	if (g_flag[7] == 2)
		return (get_length_octal(uns_temp, spec));
	if (uni->ll < 0)
		g_flag[0] = -1;
	i = get_length_2(temp, uns_temp, spec);
	return (i);
}
