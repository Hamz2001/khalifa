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

int	search_2(char *s, char c, int index)
{
	int	i;

	(void)index;
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
	out = ft_calloc(x + 2, sizeof(char *));
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
			// if (av[i][j] == '<')
			// 	i = skip_infile(av, i);
			//printf("%s______\n", av[i]);
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

int	skip_infile_2(char **s, int index)
{
	int	j;
	int	x;

	x = -1;
	while (s[index])
	{
		j = 0;
		while (s[index][j])
		{
			if (search_2(s[index], '<', index) == 1)
			{
				x = index;
			}
			j++;
		}
		index++;
	}
	return (x);
}

int	check_if_befor_cmd(char **av, int i, int x)
{
	int	j;
	int	p;
	int	y;

	j = 0;
	p = 0;
	y = 0;
	while (j < i)
	{
		if (av[j][p] == '<')
		{
			j++;
			y = 1;
		}
		else if (y == 1 && av[j][p] != '<')
		{
			j++;
			y = 0;
		}
		else if (y == 0 && av[j][p])
		{
			return (j);
		}
	}
	return (x);
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
			if (search(s[i], '<') == 1 && search(s[i], '|') == 0) //
			{
				x = i;
				// printf("%s_______skip_infile________\n", s[x + 1]);
			}
			if (search(s[i], '|') == 1)
			{
				if (x == check_if_befor_cmd(s, i, x))
				{
					j++;
				}
				else if (x != check_if_befor_cmd(s, i, x))
				{
					x = check_if_befor_cmd(s, i, x);
					return (x);
				}	
				printf("%d__________xxxxxX_____\n", x);
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
			if (t[i][j] == '|' || t[i][j] == '>' || t[i][j] == '<')
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

int	check_redirection(char **av, int p)
{
	if (av[p][0] == '<')
	{
		printf("%d__check_how_p\n", p);
		p = (skip_infile_2(av, p) + 2);
		printf("%d__check_how_p\n", p);
	}
	printf("%s_______check_reeeeeee_____\n", av[p]);
	return (p);
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
	printf("%d__here___pppp\n", p);
	while (i >= 0)
	{
		ji = 0;
		if (y == 0)
		{
			printf("______first_cmd________\n");
			if (p == -1)
				p = 0;
			else if (p == 0)
				p = 2;
			p = check_redirection(av, p);
			printf("%d____________check_redirection\n", p);
			ji = count_arg(av, p);
			count = ft_calloc(ji + 1, sizeof(char *));
			count = count_cmd(av, p, y);
		}
		else
		{
			printf("___________second_cmd_________\n");
			ji = count_arg(av, p);
			count = ft_calloc(ji + 1, sizeof(char *));
			p = (find_pipe(av, p) + 1);
			p = check_redirection(av, p);
			printf("%d____Pipe_____\n", p);
			count = count_cmd(av, p, y);
		}
		// printf("%s_____count_____\n", count[0]);
		// printf("%s_______count_________\n", count[1]);
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
