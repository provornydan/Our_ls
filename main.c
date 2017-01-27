#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

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
	int j;

	i = -1;
	temp = (char**)malloc(sizeof(char*) * (n+2));
	while(++i < n)
		temp[i] = (char*)malloc(sizeof(char)*(strlen(str[i])+1));
	temp[i] = (char*)malloc(sizeof(char) * (strlen(new_str)+1));
	temp[++i] = NULL;
	i = -1;
	while(++i < n)
	{
		j = -1;
		while(++j < strlen(str[i]) + 1)
			temp[i][j] = str[i][j];
	}
	j = -1;
	while(++j < strlen(new_str) + 1)
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

int main(int ac, char **av)
{
	struct dirent *dirp;
	DIR *dir;
	char **learn;
	int n;
	int i;

	n = 0;
	i = -1;
	if(ac == 1)
		dir = opendir("/");
	else
		dir = opendir(av[1]);
	while((dirp = readdir(dir)) != NULL)
	{
		if(n == 0)
		{
			learn = (char**)malloc(sizeof(char*)*2);
			learn[0] =(char*)malloc(sizeof(strlen(dirp->d_name) + 1));
			learn[1] = NULL;
			while(++i < strlen(dirp->d_name)+ 1)
				learn[0][i] = dirp->d_name[i];
		}
		else
		{
			learn = my_realloc(learn, dirp->d_name, n);
		}
		n++;
	}
	sort_list(learn);
	i = -1;
	while(++i < n)
		printf("%s\n",learn[i]);
}