/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:27:21 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/17 18:27:22 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*l_lstlast(t_data **lst)
{
	t_data	*tmp;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_data	*l_lstnew(char **infile, char **outfile, char **full_cmd)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->infile = infile;
	node->outfile = outfile;
	node->full_cmd = full_cmd;
	node->next = NULL;
	return (node);
}

void	l_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*p;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = l_lstlast(lst);
	p->next = new;
}

int	l_lstsize(t_data *lst)
{
	int		i;
	t_data	*tmp;

	tmp = lst;
	// if (tmp == NULL)
	// 	(printf("Error_Size\n"), exit(1));
	i = 0;
	while (tmp)
	{
		// printf("%s=\n", tmp->infile);
		// printf("%s=\n", tmp->outfile);
		//printf("%s=\n", tmp->full_cmd[0]);
		// printf("%s\n", tmp->full_cmd[1]);
		// printf("===========\n");
		tmp = tmp->next;
		i++;
	}
	return (i);
}
