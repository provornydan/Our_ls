/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:03:44 by dprovorn          #+#    #+#             */
/*   Updated: 2017/02/02 10:13:28 by vcrivenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

short	is_ok(char c, char ok)
{
	if (c && c != '\t' && c != '\n' && c != ok)
		return (1);
	else
		return (0);
}

int		get_count(char const *str, char ok)
{
	int i;
	int count;

	i = -1;
	count = 0;
	if(str[0] == ok)
		count = 1;
	while (str[++i])
		if (is_ok(str[i], ok) && (i ? !is_ok(str[i - 1], ok) : 1))
			++count;
	return (count);
}

int		get_size(char const *str, int i, char ok)
{
	int size;

	size = 0;
	while (is_ok(str[i], ok))
	{
		size++;
		i++;
	}
	return (size);
}

void	put_first(int *i,char** tab)
{
	tab[0][0] = '\0';
	*i = 0;
}

char	**ft_strsplit(char const *str, char ok)
{
	char	**tab;
	int		i[4];

	if(!check_file(i, str, ok))
		return (NULL);
	tab = (char **)malloc(sizeof(char*) * (i[3] + 1));
	if(str[0] == ok)
	{
		tab[0] = (char*)malloc(sizeof(char)*2);
		put_first(&i[0], tab);
	}
	while (++i[0] < i[3] && (i[2] = -1))
	{
		while (!is_ok(str[i[1]], ok))
			++i[1];
		tab[i[0]] = (char *)malloc(sizeof(char) * get_size(str, i[1], ok));
		while (is_ok(str[i[1]], ok))
		{
			tab[i[0]][++i[2]] = str[i[1]];
			i[1]++;
		}
		tab[i[0]][++i[2]] = '\0';
	}
	tab[i[0]] = NULL;
	return (tab);
}
