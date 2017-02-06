/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:33 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:38 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_wlen(wchar_t wchr)
{
	int i;

	i = 0;
	if (wchr < 128)
		i++;
	else if (wchr < 2047)
		i += 2;
	else if (wchr < 65535)
		i += 3;
	else
		i += 4;
	return (i);
}

void	print_str_2(wchar_t *wstr, char *str, int length, short spec)
{
	if (g_flag[5])
	{
		if (spec == 33)
			ft_print_wstr_minus(wstr, length);
		else
			ft_print_str_minus(str, length);
	}
	else
	{
		if (spec == 33)
			ft_print_wstr_width(wstr, length);
		else
			ft_print_str_width(str, length);
	}
}

void	init(int *length, short *to_free, char **str, wchar_t **wstr)
{
	*length = 0;
	*to_free = 0;
	*str = NULL;
	*wstr = NULL;
}

void	print_str(va_list *mylist, short spec)
{
	int		length;
	short	to_free;
	char	*str;
	wchar_t	*wstr;

	init(&length, &to_free, &str, &wstr);
	if (spec == 33)
		wstr = va_arg(*mylist, wchar_t*);
	else
		str = va_arg(*mylist, char*);
	if ((str == NULL && spec == 30) || (wstr == NULL && spec == 33))
	{
		to_free = 1;
		str = ft_strdup("(null)");
		spec = 30;
	}
	if (spec == 33)
		length = ft_wstrlen(wstr);
	else
		length = ft_strlen(str);
	modify_str_length(&length, wstr, spec);
	print_str_2(wstr, str, length, spec);
	if (to_free)
		free(str);
}
