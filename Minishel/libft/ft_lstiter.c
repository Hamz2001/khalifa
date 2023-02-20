/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:36:33 by hrakik            #+#    #+#             */
/*   Updated: 2022/12/24 21:36:34 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		f(lst->content); 
		//lst = lst->next;
	}
}

// void	f(void	*k)
// {
// 	t_list *o;

// 	o = (t_list)k;
// 	o->content = ft_strdup("5555");
// 	// printf("%s\n", k);
// 	// k = ft_strdup("333333");
// 	// printf("%s\n", k);
// }

// int main()
// {
// 	t_list	*k;
// 	t_list	*p;


// 	k = ft_lstnew(ft_strdup("11111"));
// 	p = ft_lstnew(ft_strdup("22222"));

// 	//k->next = p;
// 	//p->next = NULL;

// 	ft_lstiter(k,f);
// 	printf("%s", k->content);
// 	//printf("%s", p->content);
// }