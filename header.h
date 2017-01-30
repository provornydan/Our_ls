/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:02 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/30 16:22:04 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

int		g_flags[10];
t_list	g_fhead;
t_list	g_ftail;
typedef struct	s_data
{
	char*	rig;
	int		l;
	char*	o;
	char*	g;
	int		s;
	time_t	t;
	char*	name;
}				t_data;
typedef struct	s_list
{
	t_data			data;
	char*			home;
	struct s_list	*next;
	struct s_list	*prev; 	
}				t_list;

int		ft_strcmp(const char *s1, const char *s2);
char	**my_realloc(char **str, char *new_str, int n);
void	sort_list(char **found);
#endif
