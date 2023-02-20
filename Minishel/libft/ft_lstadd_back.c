/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:14:32 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/24 16:14:33 by hrakik           ###   ########.fr       */
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

// t_list	*ft_lstlast(t_list	*lst)
// {
// 	t_list *tmp;

// 	tmp = lst;
// 	while (tmp->next != NULL)
// 	{
// 		tmp = tmp->next; 
// 	}
// 	return(tmp);
// }

void    lstadd_back(t_list **lst, t_list *new)
{
    t_list    *p;

    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    p = ft_lstlast(*lst);
    p->next = new;
}

// int main()
// {
// 	t_list *k;
// 	t_list *o;
// 	t_list *e;
// 	t_list *p;

// 	k = ft_lstnew("111");
// 	o = ft_lstnew("222");
// 	e = ft_lstnew("333");
// 	p = ft_lstnew("444");

// 	k->next = o;
// 	o->next = e;
// 	e->next = NULL;
// 	p->next = NULL;

// 	ft_lstadd_back(&k,p);
// 	// printf("%s", k->content);
// 	// printf("%s", o->content);
// 	// printf("%s", e->content);
// 	printf("%s", p->content);
// }