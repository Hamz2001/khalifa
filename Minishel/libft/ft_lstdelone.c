/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:02:16 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/24 17:02:17 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list *node;

// 	node = malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return(NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return(node);
// }

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if(lst && del)
		del(lst->content);
	free(lst);
}

void	*del(void *k)
{
	free(k);
}

// int main()
// {
// 	t_list *k;
// 	t_list *o;

// 	k = ft_lstnew("kkk");
// 	o = ft_lstnew("111");

// 	k->next = o;
// 	o->next = NULL;

// 	ft_lstdelone(k, del(k));
// 	printf("%s", k->content);
// }
