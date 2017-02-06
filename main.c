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

	stat(namef,&fileStat);
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
	char	*result;

	stat(namef,&fileStat);
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

void	sort_helper(t_list **second, t_list **new)
{
	if((*second)->next->next)
		(*second)->next->next->prev = (*second);
	(*second)->next->prev =(*second)->prev;
	if((*second)->prev)	
		(*second)->prev->next = (*second)->next;
	(*second)->prev = (*second)->next;
	(*second)->next = (*second)->next->next;
	(*second)->prev->next = (*second);
	if(*new == *second)
		(*new) = (*second)->prev;
	(*second) = (*second)->prev;
}

void	sort_byname(t_list **new)
{
	t_list *first;
	t_list *second;
	int i;

	if(*new == NULL || (*new)->next == NULL)
		return;
	i = -1;
	while(++i < 2)
	{
	first = *new;
	while(first && first->next)
	{
		second = find_first_elem(new);
		while(second && second->next)
		{
			if(ft_strcmp(second->data.name, second->next->data.name) > 0)
				sort_helper(&second, new);	
			if(second->next)
				second = second->next;
		}
		first = first->next;
	}
	second = find_first_elem(new);
	}
}

void	sort_mode(t_list **new)
{
	if(g_flags[2] == 0 && g_flags[4] == 0)
		sort_byname(new);
	else if(g_flags[2] != 0 && g_flags[4] == 0)
	;//	sort_byname_rev(new);
	else if(g_flags[2] == 0 && g_flags[4] != 0)
	;	//sort_bytime_mod(new);
	else if(g_flags[2] != 0 && g_flags[4] != 0)
	;//	sort_bytime_mod_rev(new);
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
  return (stat (filename, &buffer) == 0);
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
	show_blocks(h_h);
	sort_mode(&h_h);
	while(h_h)
	{
		s = format_path(h_h->data.name);
		if(check_a(s))
			ft_printf("%s\n",s);
		h_h = h_h->next;
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
