/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:19:57 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/05 15:19:59 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int	find_var(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '$')
		i++;
	return (i);
}

int	count_var(char *s, int index)
{
	int	c;

	c = 0;
	while (s[index] && ft_isalpha(s[index]) == 1)
	{
		index++;
		c++;
	}
	return (c);
}

int	check_the_env(char *s1, char *s2, int index, int df)
{
	int	i;

	i = 0;
	index++;
	while (i <= df && s1[i] == s2[index])
	{
		i++;
		index++;
	}
	if (df == i)
		return (1);
	return (0);
}

char	*linke_str(char *yum, char *str)
{
	int		i;
	int		len_s1;
	int		len_s2;
	int		del;
	int		all;
	int		y;
	int		t;
	int		m;
	char	*iren;

	y = 0;
	m = 0;
	t = 0;
	i = find_var(str);
	len_s1 = ft_strlen(yum);
	del = count_var(str, (i + 1));
	len_s2 = ft_strlen(str) - del;
	all = len_s1 + len_s2;
	iren = (char *)ft_calloc(all + 1, sizeof(char));
	while (all > 0)
	{
		if (str[m] == '$')
		{
			while (yum[t])
			{
				iren[y] = yum[t];
				t++;
				y++;
				all--;
			}
			while (del >= 0)
			{
				m++;
				del--;
			}
		}
		iren[y] = str[m];
		y++;
		m++;
		all--;
	}
	// while (all > 0)
	// {
	// 	if (str[m] == '$')
	// 	{
	// 		while (yum[t])
	// 		{
	// 			iren[y] = yum[t];
	// 			t++;
	// 			y++;
	// 			all--;
	// 		}
	// 		while (del >= 0)
	// 		{
	// 			m++;
	// 			del--;
	// 		}
	// 	}
	// 	iren[y] = str[m];
	// 	m++;
	// 	y++;
	// 	all--;
	// }
	//printf("%s_=_\n", iren);
	return (iren);
}

int	check_single_qotos(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == '\'')
			return (0);
		index++;
	}
	return (1);
}

char	*env_var(char *s, char **env, t_prompt *prompt)
{
	int		i;
	int		len;
	int		c;
	int		p;
	char	*yum;
	char	*asta;

	(void)prompt;
	c = 0;
	p = 0;
	yum = NULL;
	asta = NULL;
	len = count_env(env);
	i = find_var(s);
	// int d = check_single_qotos(s, i);
	// if (d == 1)
	// 	return (NULL);
	p = count_var(s, (i + 1));
	while (env[c] && c < len && check_the_env(env[c], s, i, p) == 0)
		c++;
	if (env[c] && c < len && check_the_env(env[c], s, i, p) == 1)
		yum = env[c];
	else
		return (NULL);
	asta = linke_str(yum, s);
	return (asta);
}

int	check_befor_exp(char *s)
{
	int	q;
	int	i;

	q = 0;
	i = 0;
	while (s[q])
	{
		if (s[q] == '<')
			i++;
		q++;
	}
	if (i >= 2)
		return (0);
	return (1);
}

int	check_herdoc(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '<')
			return (0);
		i++;
	}
	return (1);
}

int	check_quots(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

void	expand_Path(char **a, char **env)
{
	int			i;
	int			j;
	t_prompt	prompt;

	i = 0;
	j = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == '$')
			{
				if (i > 0) // && check_single_qotos(a[i]) == 1
				{
					if (env_var(a[i], env, &prompt) == NULL)
						j++;
					else if (check_herdoc(a[i - 1]) == 1)
						(a[i] = env_var(a[i], env, &prompt), j++);
					else
						j++;
				}
				else if (i == 0) // && check_single_qotos(a[i]) == 1
				{
					if (env_var(a[i], env, &prompt) == NULL)
						j++;
					else
						(a[i] = env_var(a[i], env, &prompt), j++);
				}
			}
			j++;
		}
		i++;
	}
}
