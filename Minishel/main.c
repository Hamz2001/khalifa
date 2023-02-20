/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrakik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:41:36 by hrakik            #+#    #+#             */
/*   Updated: 2023/02/04 15:41:37 by hrakik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_empt(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '\0' && s[i] != '\n')
		return (1);
	return (0);
}

//int	main(int ac, char **av, char **env)
int	main(int ac, char **av, char **env)
{
	// t_data data;
	(void)ac;
	(void)av;
	(void)env;
	t_prompt prompt;
	t_data *data = NULL;
	int q;
	int i;
	char **a = NULL;

	while (1)
	{
		q = 0;
		i = 0;
		prompt.cmds = readline("Minishell > ");
		if (ft_check_empt(prompt.cmds) == 1)
			add_history(prompt.cmds);
		a = break_cmd(prompt.cmds, ' ');
		expand_Path(a, env);
		divide_input(a, &data);
		// printf("==============\n");
		// while (a[q])
		// {
		// 	printf("%s\n", a[q]);
		// 	q++;
		// }
		// i = 2;
		// while (i > 0)
		// {
		// 	printf("===================\n");
		// 	printf("%s\t_______Infile______\n", data->infile[0]);
		// 	printf("%s\t_______Infile______\n", data->infile[1]);
		// 	// printf("%s\t_______Infile______\n", data->infile[2]);
		// 	// printf("%s\t_______Infile______\n", data->infile[3]);
		// 	printf("%s\t_______Outfile______\n", data->outfile[0]);
		// 	// printf("%s\t_______Node______\n", data->outfile[1]);
		// 	printf("%s\t_______full_cmd______\n", data->full_cmd[0]);
		// 	printf("%s\t_______full_cmd______\n", data->full_cmd[1]);
		// 	// printf("%s\t_______Node______\n", data->full_cmd[2]);
		// 	// printf("%s\t_______Node______\n", data->full_cmd[2]);
		// 	printf("====================\n");
		// 	i--;
		// 	data = data->next;
		// }
	}
	// printf("%s\n",getenv("PWD"));
}