/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:07:13 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:33:36 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;
	unsigned char	c1;

	p = (unsigned char *)b;
	c1 = (unsigned char )c;
	i = 0;
	while (i < len)
	{
		p[i] = c1;
		i++;
	}
	return (p);
}
