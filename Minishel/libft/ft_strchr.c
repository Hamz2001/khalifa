/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:55:05 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/31 15:02:42 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;
	char	p;

	str = (char *)s;
	p = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == p)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == p)
		return (&str[i]);
	return (NULL);
}
