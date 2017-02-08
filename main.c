/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:21:43 by dprovorn          #+#    #+#             */
/*   Updated: 2017/02/06 16:09:38 by vcalmic          ###   ########.fr       */
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
	ft_printf(" [file ...]\n");
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

int		check_flags(char **av)
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
		if(!av[i][1])
			break;
		if(av[i][1] == '-' && !av[i][2])
		{
			i++;
			break;
		}
		while(av[i][++j])
			if(!check_in_base(av[i][j], base))
				print_usage(av[i][j]);
	}
	return(i);
}

char	*ft_rights(char *namef)
{
	char *local;
	struct stat fileStat;

	lstat(namef,&fileStat);
	local = (char*)malloc(sizeof(char)*15);
	local[0] = (S_ISDIR(fileStat.st_mode)) ? 'd' : '-';
    local[1] = (fileStat.st_mode & S_IRUSR) ? 'r' : '-';
    local[2] = (fileStat.st_mode & S_IWUSR) ? 'w' : '-';
    local[3] = (fileStat.st_mode & S_IXUSR) ? 'x' : '-';
    local[4] = (fileStat.st_mode & S_IRGRP) ? 'r' : '-';
    local[5] = (fileStat.st_mode & S_IWGRP) ? 'w' : '-';
    local[6] = (fileStat.st_mode & S_IXGRP) ? 'x' : '-';
    local[7] = (fileStat.st_mode & S_IROTH) ? 'r' : '-';
    local[8] = (fileStat.st_mode & S_IWOTH) ? 'w' : '-';
    local[9] = (fileStat.st_mode & S_IXOTH) ? 'x' : '-';
    local[10] = 0;
    return(local);
}
void	complete_info(t_data *info, char *namef)
{
	struct stat fileStat;
	struct passwd* pass;
	struct group* gr;

	lstat(namef,&fileStat);
	info->rig = ft_rights(namef);
	info->l = fileStat.st_nlink;
	pass = getpwuid(fileStat.st_uid);
	info->o = pass->pw_name;
	gr = getgrgid(fileStat.st_gid);
	info->g = gr->gr_name;
	info->s = fileStat.st_size;
	info->t = fileStat.st_mtime;
	info->total = fileStat.st_blocks;
}

void	add_to_filelist(char *namef, t_list **new, t_list **tail)
{
	t_list *create;
	t_data info;

	info.name = ft_strdup(namef);
	complete_info(&info, namef);
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
	complete_info(&info, namef);
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

t_data	dup_info(t_data data)
{
	t_data local;

	local.name = ft_strdup(data.name);
	local.rig = ft_strdup(data.rig);
	local.l = data.l;
	local.o = ft_strdup(data.o);
	local.g = ft_strdup(data.g);
	local.s = data.s;
	local.t = data.t;
	local.total = data.total;
	return(local);
}

void	sort_byname(t_list **new)
{
	t_list *first;
	t_list *second;
	char *temp_home;
	t_data temp_info;

	first = *new;
	while(first)
	{
		second = *new;
		while(second->next)
		{
			if(ft_strcmp(second->data.name, second->next->data.name) > 0)
			{
				temp_home = ft_strdup(second->home);
				temp_info = dup_info(second->data);
				second->home = ft_strdup(second->next->home);
				second->data = dup_info(second->next->data);
				second->next->home = ft_strdup(temp_home);
				second->next->data = dup_info(temp_info);
			}
			second = second->next;
		}
		first = first->next;
	}
}

void	sort_byname_rev(t_list **new)
{
	t_list *first;
	t_list *second;
	char *temp_home;
	t_data temp_info;

	first = *new;
	while(first)
	{
		second = *new;
		while(second->next)
		{
			if(ft_strcmp(second->data.name, second->next->data.name) < 0)
			{
				temp_home = ft_strdup(second->home);
				temp_info = dup_info(second->data);
				second->home = ft_strdup(second->next->home);
				second->data = dup_info(second->next->data);
				second->next->home = ft_strdup(temp_home);
				second->next->data = dup_info(temp_info);
			}
			second = second->next;
		}
		first = first->next;
	}
}

void	sort_bytime_mod(t_list **new)
{
	t_list *first;
	t_list *second;
	char *temp_home;
	t_data temp_info;

	first = *new;
	while(first)
	{
		second = *new;
		while(second->next)
		{
			if((second->data.t/3600) > (second->next->data.t/3600))
			{
				temp_home = ft_strdup(second->home);
				temp_info = dup_info(second->data);
				second->home = ft_strdup(second->next->home);
				second->data = dup_info(second->next->data);
				second->next->home = ft_strdup(temp_home);
				second->next->data = dup_info(temp_info);
			}
			second = second->next;
		}
		first = first->next;
	}
}

void	sort_bytime_mod_rev(t_list **new)
{
	t_list *first;
	t_list *second;
	char *temp_home;
	t_data temp_info;

	first = *new;
	while(first)
	{
		second = *new;
		while(second->next)
		{
			if((long)second->data.t/60 < (long)second->data.t/60)
			{
				temp_home = ft_strdup(second->home);
				temp_info = dup_info(second->data);
				second->home = ft_strdup(second->next->home);
				second->data = dup_info(second->next->data);
				second->next->home = ft_strdup(temp_home);
				second->next->data = dup_info(temp_info);
			}
			second = second->next;
		}
		first = first->next;
	}
}

void	sort_mode(t_list **new)
{
	if(g_flags[2] == 0 && g_flags[4] == 0)
		sort_byname(new);
	else if(g_flags[2] != 0 && g_flags[4] == 0)
		sort_byname_rev(new);
	else if(g_flags[2] == 0 && g_flags[4] != 0)
		sort_bytime_mod(new);
	else if(g_flags[2] != 0 && g_flags[4] != 0)
		sort_bytime_mod_rev(new);
}

void	print_files(t_list *list)
{
	while(list)
	{
		g_first = 1;
		ft_printf("%s\n",list->data.name);
		g_fflag = 1;
		list = list->next;
	}
}


int file_exist (char *filename)
{
  struct stat   buffer;   
  return (lstat (filename, &buffer) == 0);
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
	i = -1;
	while(av[++i])
		if(!opendir(av[i]))
		{
			if(errno == ENOTDIR)
				add_to_filelist(av[i], &new, &tail);
			else if(file_exist(av[i]))
				add_to_folderlist(av[i], &g_fnew, &g_ftail);
		}
		else
			add_to_folderlist(av[i], &g_fnew, &g_ftail);
	if(new == NULL)
		return ;
	sort_mode(&new);
	sort_mode(&g_fnew);
	print_files(new);
}

char	*find_path(char *str, char *source)
{
	char *yes;

	yes = ft_strdup(str);
	yes = ft_strjoin(yes, "/");
	yes = ft_strjoin(yes, source);
	return(yes);
}

char	*format_path(char *path)
{
	char **found;
	char *temp;
	int i;

	i = -1;
	found = ft_strsplit(path, '/');
	while(found[++i])
		;
	temp = found[i-1];
	g_first = 1;
	return(temp);
}

int		check_a(char *s)
{
	if(s[0] == '.')
	{
		if(g_flags[1] == 0)
			return(0);
		if(g_flags[1] != 0)
			return(1);
	}
	return(1);
}

void	show_blocks(t_list *here)
{
	int count;
	char *s;
	count = 0;
	while(here)
	{
		s = format_path(here->data.name);
		if(check_a(s))
			count+=here->data.total;
		here = here->next;
	}
	ft_printf("total %d\n",count);
}

int	find_lmax(t_list *h_h)
{
	t_list *here;
	int lmax;

	lmax = 0;
	here = h_h;
	while(here)
	{
		if(here->data.l > lmax)
			lmax = here->data.l;
		here = here->next;
	}
	return(ft_strlen(ft_itoa(lmax)));
}

int	find_umax(t_list *h_h)
{
	t_list *here;
	int u_max;

	u_max = 0;
	here = h_h;
	while(here)
	{
		if(ft_strlen(here->data.o) > u_max)
			u_max = ft_strlen(here->data.o);
		here = here->next;
	}
	return(u_max);
}

int	find_gmax(t_list *h_h)
{
	t_list *here;
	int u_max;

	u_max = 0;
	here = h_h;
	while(here)
	{
		if(ft_strlen(here->data.g) > u_max)
			u_max = ft_strlen(here->data.g);
		here = here->next;
	}
	return(u_max);
}

int	find_smax(t_list *h_h)
{
	t_list *here;
	int lmax;

	lmax = 0;
	here = h_h;
	while(here)
	{
		if(here->data.s > lmax)
			lmax = here->data.s;
		here = here->next;
	}
	return(ft_strlen(ft_itoa(lmax)));
}

int	date_max(t_list *h_h)
{
	t_list *here;
	int lmax;
	char *str;
	char **found;

	lmax = 0;
	here = h_h;
	while(here)
	{
		str = ctime(&here->data.t);
		found = ft_strsplit(str, ' ');
		if(ft_strlen(found[2]) > lmax)
			lmax = ft_strlen(found[2]);
		here = here->next;
	}
	return(lmax);
}

void	print_insize(char *str, int n)
{
	int i;
	int spaces;

	i = -1;
	spaces = n - ft_strlen(str);
	while(++i < spaces)
		ft_printf(" ");
	i = -1;
	ft_printf("%s",str);
}

void	print_insize2(char *str, int n)
{
	int i;
	int spaces;

	i = -1;
	spaces = n - ft_strlen(str);
	ft_printf(" %s",str);
	while(++i < spaces)
		ft_printf(" ");
}

void	print_time(time_t our_time, int date_max)
{
	char *str_time;
	char **found;
	char **t_form;
	int i;
	int n;
	time_t now;

	time(&now);
	str_time = ctime(&our_time);
	found = ft_strsplit(str_time, ' ');
	ft_printf(" %s", found[1]);
	n = date_max - ft_strlen(found[2]);
	ft_printf(" ");
	ft_printf("%2s", found[2]);
	ft_printf(" ");
	t_form = ft_strsplit(found[3], ':');
	if((long)(now - our_time) > 15768000)
	{
		ft_printf("%5s ",found[4]);
		return ;
	}
	ft_printf("%s", t_form[0]);
	ft_printf(":");
	ft_printf("%s ", t_form[1]);
}

void	print_as_list(t_list *h_h)
{
	int l_max;
	int u_max;
	int	g_max;
	int	s_max;
	int d_max;
	char *s;

	show_blocks(h_h);
	l_max = find_lmax(h_h);
	u_max = find_umax(h_h);
	g_max = find_gmax(h_h);
	s_max = find_smax(h_h);
	d_max = date_max(h_h);
	while(h_h)
	{
		s = format_path(h_h->data.name);
		if(check_a(s))
		{
			ft_printf("%-12s",h_h->data.rig);
			print_insize(ft_itoa(h_h->data.l), l_max);
			print_insize2(h_h->data.o, u_max+1);
			print_insize2(h_h->data.g, g_max);
			print_insize(ft_itoa(h_h->data.s), s_max+2);
			print_time(h_h->data.t, d_max);
			ft_printf("%s\n",s);
		}
		h_h = h_h->next;
	}
}

void	show_inside(char *str)
{
	IN_V;
	h_h = NULL;
	h_t = NULL;
	if(!(dir = opendir(str)))
	{
		ft_printf("%s\n",stderr);
		return ;
	}
	while((dirp = readdir(dir)) != NULL)
		add_to_filelist(find_path(str, dirp->d_name), &h_h, &h_t);
	if(g_first)
		ft_printf("\n");
	if(g_fflag)
		ft_printf("%s:\n",str);
	sort_mode(&h_h);
	if(g_flags[0] == 1)
	{
		print_as_list(h_h);
		return ;
	}
	while(h_h)
	{
		s = format_path(h_h->data.name);
		if(check_a(s))
			ft_printf("%s\n",s);
		h_h = h_h->next;
	}
}
int	check_ispoint(char *s)
{
	if(s[0] != '.')
		return(0);
	if(s[1] == '\0')
		return(1);
	if(s[1] == '.' && !s[2])
		return(1);
	return(0);
}
void	show_recursively(t_list *yes)
{
	t_list *h;
	struct stat path_stat;

	IN_V;
	h = yes;
	h_h = NULL;
	h_t = NULL;
	while(h)
	{
		show_inside(h->data.name);
		g_fflag = 1;
			dir = opendir(h->data.name);
			while((dirp = readdir(dir)) != NULL)
			{
				lstat(find_path(h->data.name, dirp->d_name), &path_stat);
				if(S_ISDIR(path_stat.st_mode) && !check_ispoint(dirp->d_name))
					if(check_a(dirp->d_name))
						add_to_filelist(find_path(h->data.name, 
							dirp->d_name), &h_h, &h_t);
			}
		closedir(dir);
		sort_mode(&h_h);
		if(h_h != NULL)
			show_recursively(h_h);
		h_h = NULL;
		h = h->next;
	}
}

void	show_folders()
{
	t_list *hey;

	hey = g_fnew;

	if(g_flags[3])
		show_recursively(g_fnew);
	else
	{
		while(hey)
		{
			show_inside(hey->data.name);
			hey = hey->next;
		}
	}
}
void	check_exist(char **av)
{
	int i;

	i = -1;
	while(*(av + ++i))
	{
		if(!file_exist(av[i]))
		{
			g_notfound =  1;
			printf("ls: %s: No such file or directory\n",av[i]);
		}
	}
}

int		main(int ac, char **av)
{
	int n;

	g_fflag = 0;
	g_notfound = 0;
	g_first = 0;
	if(ac > 1)
	{
	n = check_flags(av);
	check_exist(av + n);
	show_files(av + n);
	}
	if(g_fnew == NULL && (g_fflag || g_notfound))
		return(0);
	else if((g_fnew == NULL && !g_fflag) || ac == 1)
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
