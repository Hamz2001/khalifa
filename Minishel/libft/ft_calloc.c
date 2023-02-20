/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:44:17 by hrakik            #+#    #+#             */
/*   Updated: 2022/10/31 14:51:17 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count >= SIZE_MAX / size)
	{
		return (NULL);
	}	
	p = malloc(count * size);
	if (p == 0)
		return (0);
	ft_bzero (p, (count * size));
	return (p);
}

void    ft_bzero(void *s, size_t n)
{
    size_t            i;
    char            *sr;

    sr = (char *)s;
    i = 0;
    while (i < n)
    {
        sr[i] = '\0';
        i++;
    }
}
