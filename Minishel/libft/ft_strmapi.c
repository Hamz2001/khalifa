/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strmapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:18:23 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:54:06 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*all;
	char	*d;

	i = 0;
	d = (char *)s;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(d);
	all = ft_calloc(len + 1, 1);
	if (all == 0)
		return (0);
	while (d[i] != '\0')
	{
		all[i] = f(i, d[i]);
		i++;
	}
	return (all);
}
