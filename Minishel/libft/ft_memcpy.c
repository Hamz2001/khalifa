/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:14:57 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:32:59 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	i = 0;
	if (dst == src)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
