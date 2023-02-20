/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:29:59 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:58:07 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			si;
	char			*all;

	i = 0;
	if (s == NULL)
		return (NULL);
	si = ft_strlen(s);
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (len >= SIZE_MAX || len + start > ft_strlen(s))
		all = ft_calloc(ft_strlen(s + start) + 1, 1);
	else
		all = ft_calloc((len + 1), sizeof(char));
	if (all == 0)
		return (0);
	while (i < len && start + i < si)
	{
		all[i] = s[i + start];
		i++;
	}
	return (all);
}
