/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:44:46 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/17 16:24:46 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (d == NULL && s == NULL)
		return (NULL);
	if (d > s)
	{
		while (len != 0 && len--)
			d[len] = s[len];
	}
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
