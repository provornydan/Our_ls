/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		get_data_type_2(long long *temp, t_un *uni, short spec)
{
	if (spec == 9 || spec == 31)
		*temp = (char)uni->chr;
	else if (spec == 10)
		*temp = (unsigned char)uni->uchr;
	else if (spec == 12)
		*temp = (size_t)uni->szt;
	else if (spec == 11)
		*temp = (intmax_t)uni->imaxt;
	else if (spec == 14)
		*temp = (uintmax_t)uni->uimaxt;
	else if (spec == 34)
		*temp = (wchar_t)uni->wchr;
}

long long	get_data_type(t_un *uni, short spec)
{
	long long temp;

	if (spec == 1 || spec == 2)
		temp = (long long)uni->ll;
	else if (spec == 3)
		temp = (long int)uni->lin;
	else if (spec == 4)
		temp = (unsigned long int)uni->ulin;
	else if (spec == 5)
		temp = (int)uni->in;
	else if (spec == 6)
		temp = (unsigned int)uni->uin;
	else if (spec == 7)
		temp = (short)uni->sh;
	else if (spec == 8)
		temp = (unsigned short)uni->ush;
	else
		get_data_type_2(&temp, uni, spec);
	return (temp);
}

long long	get_from_list(va_list *my_list, short spec)
{
	long long result;

	if (spec == 1 || spec == 2)
		result = va_arg(*my_list, long long);
	else if (spec == 3)
		result = va_arg(*my_list, long int);
	else if (spec == 4)
		result = va_arg(*my_list, unsigned long int);
	else if (spec == 6)
		result = va_arg(*my_list, unsigned int);
	else if (spec == 12)
		result = va_arg(*my_list, size_t);
	else if (spec == 11)
		result = va_arg(*my_list, intmax_t);
	else if (spec == 14)
		result = va_arg(*my_list, uintmax_t);
	else
		result = va_arg(*my_list, int);
	return (result);
}
