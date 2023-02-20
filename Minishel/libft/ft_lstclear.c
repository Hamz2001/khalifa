/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:22:22 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/24 21:22:24 by hrakik           ###   ########.fr       */
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

// void ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if(lst && del)
// 		del(lst->content);
// 	free(lst);
// }

// void	*del(void *k)
// {
// 	free(k);
// }

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if(lst)
	{
		while(*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst,del);
			(*lst) = tmp;
		}
	}
	*lst = NULL;
}

// int main()
// {
// 	t_list	*k;
// 	t_list	*o;
// 	t_list	*i;

// 	k = ft_lstnew("jdjd\n");
// 	o = ft_lstnew("klkl\n");
// 	i = ft_lstnew("utut\n");

// 	k->next = o;
// 	o->next = i;
// 	i->next = NULL;


// 	printf("%s", k->content);
// 	printf("%s", o->content);
// 	printf("%s", i->content);
// }
