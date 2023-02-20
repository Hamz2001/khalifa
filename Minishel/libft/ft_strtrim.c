/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:52:44 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:56:34 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_end(char const *str1, char const *str2)
{
	int	j;
	int	count;
	int	len;

	j = 0;
	count = 0;
	len = ft_strlen(str1) - 1;
	while (len > 0)
	{
		j = 0;
		while (str2[j] != '\0')
		{
			if (str1[len] == str2[j])
			{
				count++;
				break ;
			}
			j++;
		}
		// if (count > 0)
		break;
		// if (str2[j] == '\0')
		// 	break ;
		len--;
	}
	return (count);
}

static int	ft_check_start(char const *str1, char const *str2)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] != '\0')
		{
			if (str1[i] == str2[j])
			{
				count++;
				break ;
			}
			j++;
		}
		// if (count > 0)
		break;
		// if (str2[j] == '\0')
		// 	break ;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*all;
	int		len;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_check_start (s1, set);
	end = ft_check_end (s1, set);
	len = ft_strlen(s1) - (start + end);
	if (len < 0)
		return (ft_calloc(1, 1));
	all = ft_calloc(len + 1, 1);
	if (all == 0)
		return (0);
	while (i < len)
	{
		all[i] = s1[start + i];
		i++;
	}
	return (all);
}
