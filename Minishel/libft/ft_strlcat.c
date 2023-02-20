/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:11:40 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/29 21:52:08 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		lendst;
	size_t		lensrc;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || lendst >= dstsize)
		return (dstsize + lensrc);
	while (dstsize - lendst - 1 > i && src[i] != '\0')
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
