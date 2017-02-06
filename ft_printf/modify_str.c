/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	modify_wlen(wchar_t *wstr)
{
	int	wlen;
	int	i;

	wlen = 0;
	i = 0;
	while (wstr[i])
	{
		wlen += ft_wlen(wstr[i]);
		if (wlen > g_flag[4])
			break ;
		else if (wlen == g_flag[4])
			return ;
		++i;
	}
	wlen -= ft_wlen(wstr[i]);
	g_flag[3] = g_flag[3] + (g_flag[4] - wlen);
}

void	modify_str_length(int *length, wchar_t *wstr, short spec)
{
	if (g_flag[4] <= *length && g_flag[8])
		*length = g_flag[4];
	if (g_flag[3] - *length > 0)
		g_flag[3] = g_flag[3] - *length;
	else
		g_flag[3] = 0;
	if (g_flag[4] && g_flag[3] && spec == 33)
		modify_wlen(wstr);
}
