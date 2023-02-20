/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:14:16 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/05 12:14:17 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_separa(char const *str, char c, int in)
{
	int	i;

	i = 0;
	while (str[in] != c && str[in] != '\0')
	{
		in++;
	}
	return (in);
}

void	ft_free(char **str, int i)
{
	while (str[i])
	{
		free(str[i]);
		i--;
	}
	free(str);
}

int	ft_countstr(char const *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && j == 0)
		{
			j = 1;
			index++;
		}
		if (s[i] == c)
			j = 0;
		i++;
	}
	return (index + 1);
}

char	*ft_all_str(char const *s, int bg, char c)
{
	char	*all;
	int		j;
	int		len;
	int		b;
	int		i;

	b = bg;
	len = 0;
	j = 0;
	i = 0;
	while (s[b] != c && s[b] != '\0')
	{
		len++;
		b++;
	}
	all = (char *)ft_calloc((len) + 1, sizeof(char));
	if (all == 0)
		return (0);
	while (s[bg] != c && s[bg] != '\0')
	{
		all[j] = s[bg];
		bg++;
		j++;
	}
	return (all);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**split;
	int		bg;

	bg = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	split = (char **)ft_calloc(ft_countstr(s, c), sizeof(char *));
	if (split == 0)
		return (0);
	while (s[bg] != '\0')
	{
		if (s[bg] == c)
			bg++;
		else if (s[bg] != c)
		{
			split[i] = ft_all_str(s, bg, c);
			if (split[i] == NULL)
				ft_free(split, i);
			bg = ft_separa(s, c, bg);
			i++;
		}
	}
	return (split);
}
