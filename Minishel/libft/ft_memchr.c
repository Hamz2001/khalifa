/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:45:40 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/31 15:02:30 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ptr;

	i = 0;
	str = (unsigned char *)s;
	ptr = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (str[i] == ptr)
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
