/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:25 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/15 15:28:27 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_herdoc1(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '<')
			c++;
		i++;
	}
	if (c == 2)
		return (0);
	return (1);
}

int	search(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**find_infile(char **av)
{
	int		i;
	int		x;
	char	**inf;
	int		p;

	i = 0;
	x = 0;
	p = 0;
	while (av[i])
	{
		if (search(av[i], '<') == 1)
		{
			if (check_herdoc1(av[i]) == 1)
			{
				x++;
			}
		}
		i++;
	}
	if (x == -1)
		return (NULL);
	i = 0;
	inf = ft_calloc(x + 1, sizeof(char *));
	while (av[i])
	{
		if (search(av[i], '<') == 1)
		{
			if (check_herdoc1(av[i]) == 1)
			{
				inf[p] = av[i + 1];
				p++;
			}
		}
		i++;
	}
	return (inf);
}

char	**find_outfile(char **av)
{
	int		i;
	int		x;
	int		p;
	char	**out;

	i = 0;
	p = 0;
	x = -1;
	out = NULL;
	while (av[i])
	{
		if (search(av[i], '>') == 1)
		{
			if (check_herdoc1(av[i]) == 1)
				x++;
		}
		i++;
	}
	if (x == -1)
		return (NULL);
	out = ft_calloc(x + 1, sizeof(char *));
	i = 0;
	while (av[i])
	{
		if (search(av[i], '>') == 1)
		{
			if (check_herdoc1(av[i]) == 1)
			{
				out[p] = av[i + 1];
				p++;
			}
		}
		i++;
	}
	return (out);
}

int	find_pipe(char **av, int i)
{
	int	j;

	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '|')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	count_pipe(char **av)
{
	int	i;
	int	c;
	int	j;

	c = 0;
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '|')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	skip_infile(char **s)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = -1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (search(s[i], '<') == 1)
			{
				x = i;
			}
			j++;
		}
		i++;
	}
	return (x);
}

int	count_arg(char **t, int i)
{
	int	j;
	int	c;

	c = 0;
	while (t[i])
	{
		j = 0;
		while (t[i][j])
		{
			if (t[i][j] == '|' || t[i][j] == '>')
				return (c);
			j++;
		}
		c++;
		i++;
	}
	return (c);
}

char	**count_cmd(char **s, int p, int y)
{
	int		j;
	int		h;
	char	**cmd;

	(void)y;
	j = count_arg(s, p);
	h = 0;
	cmd = ft_calloc((j + 1), sizeof(char *));
	while (s[p] && j > 0)
	{
		cmd[h] = s[p];
		p++;
		j--;
		h++;
	}
	return (cmd);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	create_node(t_data **data, char **infile, char **outfile,
		char **full_cmd)
{
	l_lstadd_back(data, l_lstnew(infile, outfile, full_cmd));
}

int	open_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

int	open_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

void	divide_input(char **av, t_data **data)
{
	char	**infile;
	int		p;
	int		o;
	char	**outfile;
	char	**count;
	int		i;
	int		ji;
	int		y;

	p = 0;
	o = 4;
	infile = find_infile(av);
	if (infile == NULL)
	{
		infile = ft_calloc(1, sizeof(char *));
		infile[0] = NULL;
	}
	outfile = find_outfile(av);
	if (outfile == NULL)
	{
		outfile = ft_calloc(1, sizeof(char *));
		outfile[0] = NULL;
	}
	i = count_pipe(av);
	y = 0;
	p = skip_infile(av);
	while (i >= 0)
	{
		ji = 0;
		if (y == 0)
		{
			if (p == -1)
				p = 0;
			else
				p = 2;
			ji = count_arg(av, p);
			count = ft_calloc(ji + 1, sizeof(char *));
			count = count_cmd(av, p, y);
		}
		else
		{
			ji = count_arg(av, p);
			count = ft_calloc(ji + 1, sizeof(char *));
			p = (find_pipe(av, p) + 1);
			count = count_cmd(av, p, y);
		}
		create_node(data, infile, outfile, count);
		y++;
		i--;
	}
	// i = 5;
	// while (i > 0)
	// {
	// 	printf("%s\t_______Node______\n", data->infile[0]);
	// 	printf("%s\t_______Node______\n", data->infile[1]);
	// 	printf("%s\t_______Node______\n", data->outfile[0]);
	// 	printf("%s\t_______Node______\n", data->outfile[1]);
	// 	printf("%s\t_______Node______\n", data->full_cmd[0]);
	// 	printf("%s\t_______Node______\n", data->full_cmd[1]);
	// 	printf("%s\t_______Node______\n", data->full_cmd[2]);
	// 	printf("%d\t__nb_node____\n", l_lstsize(data));
	// 	printf("====================\n");
	// 	i--;
	// 	data = data->next;
	// }
	// return (data);
}
