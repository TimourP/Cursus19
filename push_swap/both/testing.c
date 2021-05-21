/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:05:13 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/21 10:34:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	printf("-------------------\n");
	printf("    a    |    b\n");
	printf("-------------------\n");
	while (a || b)
	{
		if (a)
		{
			if (b)
			{
				printf("%5d", a->content);
				printf("    |");
			}
			else
				printf("%5d    |\n", a->content);
			a = a->next;
		}
		else
			printf("         |");
		if (b)
		{
			printf("%5d\n", b->content);
			b = b->next;
		}
	}
	printf("-------------------\n");
}

char *str_char(char c, int len)
{
	int 	i;
	char	*str;

	i = -1;
	len = len + 1;
	str = malloc((len + 1) * sizeof(str));
	while (++i < len)
		str[i] = c;
	str[i] = 0;
	return (str);
}

void	graph_1line(t_stack *a, t_stack *b)
{
	system("sleep 0.05");
	system("clear");
	graphic_stack(a, b);
}

void	graphic_stack(t_stack *a, t_stack *b)
{
	char *str;

	while (a || b)
	{
		if (a)
		{
			str = str_char('|', a->content);
			printf("%-110s", str);
			free(str);
			if (!b)
				printf("\n");
			a = a->next;
		}
		else
			printf("%110s", "");
		if (b)
		{
			str = str_char('|', b->content);
			printf("%110s\n", str);
			free(str);
			b = b->next;
		}
	}
}