/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:18:15 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/24 15:18:18 by hrakik           ###   ########.fr       */
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

t_list	*ft_lstlast(t_list	*lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next; 
	}
	return(tmp);
}

// int main()
// {
// 	t_list *k;
// 	t_list	*j;
// 	t_list  *y;
// 	t_list	*o;

// 	k = ft_lstnew("Hamza");
// 	j = ft_lstnew("Ayoub");
// 	y = ft_lstnew("lllds");

// 	k->next = j;
// 	j->next = y;

// 	o = ft_lstlast(k);
// 	// printf("%s", k->content);
// 	// printf("%s", j->content);
// 	// printf("%s", y->content);
	
// 	printf("%s", o->content);

// }
