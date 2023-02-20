/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:40:54 by hrakik            #+#    #+#             */
/*   Updated: 2022/11/29 10:04:58 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_len_all(int s)
{
	int	i;

	i = 0;
	if (s < 0)
	{
		s *= -1;
		i++;
	}
	if (s == 0)
		return (1);
	while (s)
	{
		s = s / 10;
		i++;
	}
	return (i);
}

static void	itoa_prim(char *all, int len, int n, int sign)
{
	while (len-- > 0)
	{
		all[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		all[0] = '-';
}

char	*ft_itoa(int n)
{
	int		i;
	char	*all;
	int		len;
	int		sign;

	i = 0;
	len = 0;
	sign = 0;
	len = ft_len_all(n);
	printf("%d\n", len);
	all = ft_calloc(len + 1, 1);
	if (all == 0)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(all, "-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	itoa_prim(all, len, n, sign);
	return (all);
}

int	main(void)
{
	int nb = 65;
	printf("%s\n", ft_itoa(nb));
}