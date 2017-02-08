/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:02 by dprovorn          #+#    #+#             */
/*   Updated: 2017/02/02 15:04:40 by vcalmic          ###   ########.fr       */
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
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include "ft_printf/header.h"
# define IN_V struct dirent *dirp; DIR *dir; t_list *h_h; t_list *h_t; char *s;
typedef struct	s_data
{
	char*	rig;
	int		l;
	char*	o;
	char*	g;
	int		s;
	time_t	t;
	char*	name;
	int		total;
}				t_data;
typedef struct	s_list
{
	t_data			data;
	char*			home;
	struct s_list	*next;
	struct s_list	*prev; 	
}				t_list;

int		g_flags[10];
t_list	*g_fhead;
t_list	*g_fnew;
t_list	*g_ftail;
int		g_fflag;
int		g_notfound;
int		g_first;
t_list	*g_htemp;
t_list	*g_ttemp;	

int		ft_strcmp(const char *s1, const char *s2);
char	**my_realloc(char **str, char *new_str, int n);
void	sort_list(char **found);
short	is_ok(char c, char ok);
int		get_count(char const *str, char ok);
int		get_size(char const *str, int i, char ok);
char	**ft_strsplit(char const *str, char ok);
int		check_file(int *i, const char *str, char ok);
int		match(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
#endif
