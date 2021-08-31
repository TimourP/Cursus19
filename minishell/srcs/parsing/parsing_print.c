/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:15:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/05 15:57:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_files(t_cmd *cmd)
{
	t_lst	*tmp;

	printf("Infile(s): ");
	tmp = cmd->infiles;
	if (tmp == NULL)
		printf("No infile");
	while (tmp)
	{
		printf("%s (%d) ", tmp->str, tmp->flag);
		if (tmp->next)
			printf(", ");
		tmp = tmp->next;
	}
	printf("\nOutfile(s): ");
	tmp = cmd->outfiles;
	if (tmp == NULL)
		printf("No outfiles");
	while (tmp)
	{
		printf("%s (%d) ", tmp->str, tmp->flag);
		if (tmp->next)
			printf(", ");
		tmp = tmp->next;
	}
	printf("\n");
}

void	print_cmd(t_shell *shell)
{
	t_cmd	*start;
	int		i;
	int		j;

	start = shell->start_cmd;
	i = 0;
	while (start)
	{
		j = -1;
		printf("--------------------\n     Command %d\n", ++i);
		printf("Command name: " MAG "%s\n" RESET "Flags: [ " CYN, start->cmd);
		while (start->flags[++j] != NULL)
		{
			if (j == 0)
				printf(MAG "%s" CYN, start->flags[j]);
			else
				printf("%s", start->flags[j]);
			if (start->flags[j + 1] != NULL)
				printf(RESET ", " CYN);
		}
		printf(RESET " ]\n");
		print_files(start);
		start = start->next;
	}
	printf("--------------------\n");
}
