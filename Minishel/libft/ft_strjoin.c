/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:41:39 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:49:11 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy1(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	char	*b;
	char	*all;
	int		lend;
	int		lens;

	d = (char *)s1;
	b = (char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lend = ft_strlen(d);
	lens = ft_strlen(b);
	all = malloc(lend + lens + 1);
	if (all == 0)
		return (0);
	ft_strcpy1 (all, d);
	ft_strcpy1 (all + lend, b);
	all[lens + lend] = '\0';
	return (all);
}
