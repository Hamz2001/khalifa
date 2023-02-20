/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:47:22 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/05 16:47:23 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msg_err(char *err)
{
	perror(err);
}

void	msg_error(char *err)
{
	perror(err);
	exit(1);
}

void	msg_cmd_not_found(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	//write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(127);
}
