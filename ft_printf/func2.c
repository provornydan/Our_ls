/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:52:32 by dprovorn          #+#    #+#             */
/*   Updated: 2016/12/27 17:52:37 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(const char *src)
{
	unsigned int	i;
	char			*mem;
	unsigned int	j;

	i = 0;
	while (*(src + i))
		i++;
	mem = (char*)malloc(i + 1);
	if (!mem)
		return (0);
	j = -1;
	while (++j < i)
		*(mem + j) = *(src + j);
	*(mem + j) = 0;
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int nr;

	nr = 0;
	while (str[g_jump] && (str[g_jump] >= '0') && (str[g_jump] <= '9'))
	{
		nr *= 10;
		nr += (int)str[g_jump] - '0';
		g_jump++;
	}
	g_jump--;
	return (nr);
}

void	ft_putnbr(unsigned long long nb)
{
	if (nb == 0)
		ft_putchar('0');
	else if (nb > 0 && nb < 10)
	{
		ft_putchar('0' + nb);
		return ;
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}
