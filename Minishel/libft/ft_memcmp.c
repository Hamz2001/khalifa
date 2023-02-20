/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:15:40 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:32:14 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	if (n == 0)
		return (0);
	else
	{
		while (i < n)
		{
			if (c[i] != d[i])
			{
				return (c[i] - d[i]);
			}
			i++;
		}
	}
	return (0);
}
