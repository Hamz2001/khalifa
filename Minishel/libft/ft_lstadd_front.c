/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:31:12 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/24 10:31:13 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
			new->next = *lst;
		*lst = new;
	}
}

// int main()
// {
// 	t_list	*k;
// 	t_list	*p;

// 	k = ft_lstnew("kfor");
// 	p = ft_lstnew("popo");

// 	ft_lstadd_front(&k,p);
// 	printf("%s", k->content);
// 	printf("%s", p->content);
// }