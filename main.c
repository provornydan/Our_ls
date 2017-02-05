/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:21:43 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/30 16:21:48 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char **my_realloc(char **str, char *new_str, int n)
{
	char **temp;
	int i;
	size_t j;

	i = -1;
	temp = (char**)malloc(sizeof(char*) * (n+2));
	while(++i < n)
		temp[i] = (char*)malloc(sizeof(char)*(ft_strlen(str[i])+1));
	temp[i] = (char*)malloc(sizeof(char) * (ft_strlen(new_str)+1));
	temp[++i] = NULL;
	i = -1;
	while(++i < n)
	{
		j = -1;
		while(++j < ft_strlen(str[i]) + 1)
			temp[i][j] = str[i][j];
	}
	j = -1;
	while(++j < ft_strlen(new_str) + 1)
		temp[i][j] = new_str[j];
	return(temp);
}

void	sort_list(char **found)
{
	int i;
	int j;
	char *temp;

	i = -1;
	while(found[++i])
	{
		j = -1;
		while(found[++j])
			if(found[j+1])
			{
				if(ft_strcmp(found[j],found[j+1]) > 0)
				{
					temp = found[j];
					found[j] = found[j+1];
					found[j+1] = temp;
				}
			}
	}
}

void	print_usage(char c)
{
		ft_printf("ls: illegal option -- %c\n",c);
		ft_printf("usage: ls [-GRadfglrtu]");
		ft_printf(" [file ...]");
		exit(0);
}

int		check_in_base(char c, char *base)
{
	int i;

	i = -1;
	while(*(base + ++i))
		if(c == *(base + i))
		{
			g_flags[i] = 1;
			return(1);
		}
	return(0);
}

void	reset_flags2()
{
	int i;

	i = -1;
	while(++i < 10)
		g_flags[i] = 0;
}

/*void	add_elem()
{

}*/

void	check_flags(char **av)
{
	int i;
	int j;
	static char *base = "larRtufdgG";

	i = 0;
	reset_flags2();
	while(*(av + ++i))
	{
		j = 0;
		if(av[i][0] != '-')
			break;
		while(av[i][++j])
			if(!check_in_base(av[i][j], base))
				print_usage(av[i][j]);
	}
}

void	complete_info(t_data *info)
{
	info->rig = NULL;
	info->l = 0;
	info->o = NULL;
	info->g = NULL;
	info->s = 0;
	info->t = 0;
}

void	add_to_filelist(char *namef, t_list **new, t_list **tail)
{
	t_list *create;
	t_data info;

	info.name = ft_strdup(namef);
	complete_info(&info);
	create = (t_list*)malloc(sizeof(t_list));
	create->data = info;
	create->home = ft_strdup(".");
	if(*new == NULL)
	{
		create->prev = NULL;
		create->next = NULL;
		*new = create;
		*tail = create;
	}
	else
	{
		create->prev = *tail;
		create->next = NULL;
		(*tail)->next = create;
		*tail = create;
	}
}

void	add_to_folderlist(char *namef, t_list **new, t_list **tail)
{
	t_list *create;
	t_data info;

	info.name = ft_strdup(namef);
	complete_info(&info);
	create = (t_list*)malloc(sizeof(t_list));
	create->data = info;
	create->home = ft_strdup(".");
	if(*new == NULL)
	{
		create->prev = NULL;
		create->next = NULL;
		*new = create;
		*tail = create;
	}
	else
	{
		create->prev = *tail;
		create->next = NULL;
		(*tail)->next = create;
		*tail = create;
	}
}

t_list *find_first_elem(t_list **new)
{
	t_list *local;

	while((*new)->prev)
	{
		*new = (*new)->prev;
	}
	local = *new;
	return (local);
}

void	sort_helper(t_list **second)
{
	if((*second)->next->next)
		(*second)->next->next->prev = (*second);
	(*second)->next->prev =(*second)->prev;
	if((*second)->prev)	
	(*second)->prev->next = (*second)->next;
	(*second)->prev = (*second)->next;
	(*second)->next = (*second)->next->next;
	(*second)->prev->next = (*second);
	(*second) = (*second)->prev;
}

void	sort_byname(t_list **new)
{
	t_list *first;
	t_list *second;

	if((*new)->next == NULL)
		return;
	first = *new;
	while(first && first->next)
	{
		second = *new;//find_first_elem(new);
		while(second && second->next)
		{
			if(ft_strcmp(second->data.name, second->next->data.name) > 0)
				sort_helper(&second);	
			if(second->next)
				second = second->next;
		}
		first = first->next;
	}
	second = find_first_elem(new);
}

void	print_files(t_list *list)
{
	while(list)
	{
		ft_printf("%s\n",list->data.name);
		g_fflag = 1;
		list = list->next;
	}
	ft_printf("\n");
}

void	show_files(char **av)
{
	int i;
	t_list *new;
	t_list *tail;

	new = NULL;
	tail = NULL;
	g_fnew = NULL;
	g_ftail = NULL;
	i = 0;
	while(av[++i])
		if(!opendir(av[i]))
		{
			if(errno == ENOTDIR)
				add_to_filelist(av[i], &new, &tail);
			else
				add_to_folderlist(av[i], &g_fnew, &g_ftail);
		}
		else
			add_to_folderlist(av[i], &g_fnew, &g_ftail);
	if(new == NULL)
		return ;
	sort_byname(&new);
	sort_byname(&g_fnew);
	print_files(new);
}

void	show_inside(char *str)
{
	struct dirent *dirp;
	DIR *dir;
	t_list *here_h;
	t_list *here_t;

	here_h = NULL;
	here_t = NULL;
	if(!(dir = opendir(str)))
	{
		ft_printf("%s\n",stderr);
		return ;
	}
	while((dirp = readdir(dir)) != NULL)
		add_to_folderlist(dirp->d_name, &here_h, &here_t);
	if(g_fflag)
		ft_printf("%s:\n",str);
	sort_byname(&here_h);
	while(here_h)
	{
		ft_printf("%s\n",here_h->data.name);
		here_h = here_h->next;
	}
}

void	show_folders()
{
	t_list *hey;

	hey = g_fnew;

	if(g_flags[3])
		;//show_recursively();
	else
	{
		while(hey)
		{
			show_inside(hey->data.name);
			hey = hey->next;
		}
	}
}

int		main(int ac, char **av)
{
	(void)ac;
	g_fflag = 0;
	check_flags(av);
	show_files(av);
	if(g_fnew == NULL && g_fflag)
		return(0);
	else if(g_fnew == NULL && g_fflag)
		add_to_folderlist(".", &g_fnew, &g_ftail);
	if(g_fnew->next != NULL)
		g_fflag = 1;
	show_folders();
}

// int main(int ac, char **av)
// {
// 	struct dirent *dirp;
// 	DIR *dir;
// 	char **learn;
// 	int n;
// 	int i;

// 	n = 0;
// 	i = -1;
// 	if(ac == 1)
// 		dir = opendir("*");
// 	else
// 		dir = opendir(av[1]);
// 	while((dirp = readdir(dir)) != NULL)
// 	{
// 		if(n == 0)
// 		{
// 			learn = (char**)malloc(sizeof(char*)*2);
// 			learn[0] =(char*)malloc(sizeof(strlen(dirp->d_name) + 1));
// 			learn[1] = NULL;
// 			while(++i < strlen(dirp->d_name)+ 1)
// 				learn[0][i] = dirp->d_name[i];
// 		}
// 		else
// 		{
// 			learn = my_realloc(learn, dirp->d_name, n);
// 		}
// 		n++;
// 	}
// 	sort_list(learn);
// 	i = -1;
// 	while(++i < n)
// 		ft_printf("%s\n",learn[i]);
// }
