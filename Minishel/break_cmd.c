/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:09 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/06 13:57:10 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_space(char s, char set)
{
	if (s == set)
		return (1);
	return (0);
}

int	count_word(char *s, char set)
{
	int	i;
	int	sp;

	(void)set;
	i = 0;
	sp = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != ' ' && s[i] != '\'' && s[i] != '\"' && s[i] != '<' && s[i] != '>' && s[i] != '|') //&& (s[i] != '>'&& s[i + 1] != '>') && (s[i] != '<' && s[i + 1] != '<')
			{
				i++;
				if (!s[i])
					sp++;
			}
		if (s[i] == '\'' || s[i] == '\"')
		{
			if (s[i] == '\'')
			{
				i++;
				while (s[i] != '\'' && s[i])
					i++;
				if (s[i] == '\'')
					i++;
			}
			else if (s[i] == '\"')
			{
				i++;
				while (s[i] != '\"' && s[i])
					i++;
				if (s[i] == '\"')
					i++;
			}
		}
		if ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i
				+ 1] == '<'))
			(sp++, i++, i++);
		else if (s[i] == ' ' || s[i] == '|' || s[i] == '<' || s[i] == '>')
			(sp++, i++);
	}
	if (sp == 0)
		sp = 1;
	return (sp);
}

int	ft_strlen_sp(char *s, int index)
{
	int	q;

	q = 0;
	while (s[index] && s[index] == ' ')
		index++;
	if (s[index] && s[index] != ' ' && s[index] != '<' && s[index] != '>'
		&& s[index] != '|')
	{
		while (s[index] && s[index] != ' ' && s[index] != '<' && s[index] != '>'
			&& s[index] != '|')
		{
			if (s[index] == '\'')
			{
				index++;
				q++;
				while (s[index] && s[index] != '\'')
				{
					index++;
					q++;
				}
				if (s[index] == '\'')
				{
					index++;
					q++;
				}
			}
			else if (s[index] == '\"')
			{
				index++;
				q++;
				while (s[index] && s[index] != '\"')
				{
					index++;
					q++;
				}
				if (s[index] == '\"')
				{
					index++;
					q++;
				}
			}
			else
			{
				index++;
				q++;
			}
		}
	}
	else if ((s[index] == '>' && s[index + 1] == '>') || (s[index] == '<'
				&& s[index + 1] == '<'))
		q = 1;
	else if (s[index] == ' ' || s[index] == '<' || s[index] == '>'
			|| s[index] == '|')
		q++;
	return (q + 1);
}

char	**ft_fill_list(char **av, char *s)
{
	int		i;
	int		len;
	char	*b;
	int		h;
	int		bob;

	i = 0;
	bob = 0;
	while (s[i])
	{
		h = 0;
		len = ft_strlen_sp(s, i);
		// printf("%d__Lenght__\n",len);
		b = (char *)ft_calloc(len, sizeof(char));
		if (b == NULL)
			exit(1);
		while (s[i] == ' ')
			i++;
		if ((s[i] == '|' || s[i] == '>' || s[i] == '<') && len == 1)
		{
			b[h] = s[i];
			i++;
			h++;
			len--;
		}
		else if ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i
					+ 1] == '<'))
		{
			while (len > 0)
			{
				// printf("here\t%d\t%d\n", h, len);
				b[h] = s[i];
				i++;
				h++;
				len--;
			}
			// b[h] = '\0';
			// printf("%s_____________________\n", b);
		}
		else
		{
			while (s[i] && (s[i] != '|' || s[i] != '>' || s[i] != '<')
				&& len > 1) //
			{
				b[h] = s[i];
				i++;
				h++;
				len--;
			}
		}
		//b[h] = '\0';
		//printf("%s|||||\n", b);
		av[bob] = ft_strdup(b);
		// printf("%s__\n", av[bob]);
		bob++;
	}
	return (av);
}

int	is_token(char c)
{
	if (c == '|' || c == '\'' || c == '\"' || c == '<' || c == '>')
		return (1);
	return (0);
}

char	*ft_handel_cmd(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*cmd;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		else
		{
			i++;
			len++;
		}
	}
	i = 0;
	cmd = ft_calloc(len + 1, sizeof(char));
	while (s[i] != '\0')
	{
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		else
		{
			cmd[j] = s[i];
			j++;
			i++;
		}
	}
	return (cmd);
}

char	*ft_handle_quots_iside(char *s)
{
	int		i;
	int		x;
	char	*cmd;

	i = 0;
	x = 0;
	cmd = NULL;
	if (ft_isalpha(s[i]) == 1)
	{
		while (s[i])
		{
			if (s[i] == '\'' || s[i] == '\"')
			{
				cmd = ft_handel_cmd(s);
			}
			i++;
		}
	}
	return (cmd);
}

char	**break_cmd(char *s, char set)
{
	int nword;
	char **av;
	char **op;

	nword = count_word(s, set);
	// printf("%d__\n", nword);
	if (nword == -1)
		return (NULL);
	av = (char **)ft_calloc((nword + 3), sizeof(char *));
	if (av == NULL)
		exit(1);
	av = ft_fill_list(av, s);
	op = (char **)ft_calloc((nword + 3), sizeof(char *));
	int p = 0;
	while (av[p])
	{
		av[p] = ft_strtrim(av[p], "\"\'");
		p++;
	}
	p = 0;
	while (av[p])
	{
		if (ft_handle_quots_iside(av[p]) != NULL)
			av[p] = ft_handle_quots_iside(av[p]);
		p++;
	}
	return (av);
}