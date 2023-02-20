/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:19:04 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/23 17:19:06 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return(NULL);
	node->content = content;
	node->next = NULL;
	return(node);
}

// int main()
// {
// 	t_list *node;
// 	char *c = "Hamza";
// 	node = ft_lstnew(c);
// 	printf("%s", node->content);
// }
