/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:09:36 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/04 15:41:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

static size_t	number_len(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n && ++i)
		n = n / 10;
	return (i);
}

char	*ft_itoa(int n)
{
	const size_t	n_len = number_len(n);
	char			*num;
	int				i;
	int				neg;

	i = -1;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (!(num = malloc(sizeof(char) * (n_len + 1 + (int)(n == 0)))))
		return (NULL);
	num[n_len + (int)(n == 0)] = 0;
	if (neg)
		num[0] = '-';
	if (n == 0)
		num[0] = '0';
	while (n && ++i > -1)
	{
		num[n_len - 1 - i] = neg ? ('0' + n % 10 * -1) : '0' + n % 10;
		n = n / 10;
	}
	return (num);
}

int	is_in_int(int *list, int elem, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (list[i] == elem)
			return (1);
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = -1;
	while (str[++i])
		;
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*conc_str;

	if (s1)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (s1[++i])
			conc_str[i] = s1[i];
		i = -1;
		while (s2[++i])
			conc_str[i + ft_strlen(s1)] = s2[i];
		free(s1);
		free(s2);
		s1 = NULL;
		s2 = NULL;
		return (conc_str);
	}
	return (NULL);
}

int main(void)
{
	int	test_num;
	int	val_num;
	int	scan_value;
	int i;
	int j;
	int	**lst;
	int	ra;
	char	*swap_line;
	char	*line_num;
	FILE	*out_f = fopen("trash.txt", "w");
	FILE	*in_f = fopen("tmp.txt", "r");
	char	buff[100];
	char	*print_error;

	int		corrent_swap;
	int		total_lines;
	int		t;
	char	*bigest;
	char	*lowest;
	int		bigest_n;
	int		lowest_n;

	lowest_n = -1;
	bigest_n = -1;
	bigest = NULL;
	lowest = NULL;
	corrent_swap = 0;
	total_lines = 0;
	t = 0;
	system("clear");
	printf("Please indicate the number of tests to be performed: ");
	scan_value = scanf("%d", &test_num);
	printf("Please indicate the number of values that will be sent to your push_swap: ");
	scan_value = scanf("%d", &val_num);
	lst = malloc(sizeof(int*) * test_num);
	i = -1;
	while (++i < test_num)
		lst[i] = malloc(sizeof(int) * val_num);

	srand(time(NULL));
	i = -1;
	while (++i < test_num)
	{
		j = -1;
		while (j < val_num)
		{
			ra = rand() % (val_num + 1);
			if (!is_in_int(lst[i], ra, j + 1) && ++j + 1)
				lst[i][j] = ra;
		}
	}
	i = -1;
	while (++i < test_num)
	{
		fclose(in_f);
		swap_line = ft_strdup("./push_swap ");
		j = -1;
		while (++j < val_num)
		{
			swap_line = ft_strjoin(swap_line, ft_itoa(lst[i][j]));
			swap_line = ft_strjoin(swap_line, ft_strdup(" "));
		}
		print_error = ft_strdup(swap_line);
		line_num = ft_strdup(print_error);
		line_num = ft_strjoin(line_num, ft_strdup("| wc -l > count.txt"));
		system(line_num);
		t = 0;
		in_f = fopen("count.txt", "r");
		fscanf(in_f, "%d", &t);
		fclose(in_f);
		free(line_num);
		swap_line = ft_strjoin(swap_line, ft_strdup("| ./checker "));
		j = -1;
		while (++j < val_num)
		{
			swap_line = ft_strjoin(swap_line, ft_itoa(lst[i][j]));
			swap_line = ft_strjoin(swap_line, ft_strdup(" "));
		}
		line_num = ft_strdup("Test n° ");
		line_num = ft_strjoin(line_num, ft_itoa(i));
		line_num = ft_strjoin(line_num, ft_strdup(": "));
		fprintf(out_f, "%s", line_num);
		printf("%s", line_num);
		free(line_num);
		line_num = NULL;
		swap_line = ft_strjoin(swap_line, ft_strdup("> tmp.txt"));
		system(swap_line);
		in_f = fopen("tmp.txt", "r");
		fgets(buff, 3, in_f);
		buff[2] = 0;
		if (buff[0] == 'O')
			printf("\033[0;32m");
		else
			printf("\033[0;31m");
		fprintf(out_f, "%s\n", buff);
		printf("%s\n", buff);
		printf("\033[0m");
		free(swap_line);
		if (buff[0] != 'O')
		{
			printf("%s\n", print_error);
			free(print_error);
		}
		else
		{
			corrent_swap++;
			total_lines += t;
			if (t > bigest_n || bigest_n == -1)
			{
				bigest_n = t;
				free(bigest);
				bigest = NULL;
				bigest = print_error;
				if (t < lowest_n || lowest_n == -1)
				{
					lowest_n = t;
					free(lowest);
					lowest = NULL;
					lowest = ft_strdup(print_error);
				}
			} else if (t < lowest_n || lowest_n == -1)
			{
				lowest_n = t;
				free(lowest);
				lowest = NULL;
				lowest = print_error;
			} else
				free(print_error);
		}
		swap_line = NULL;
	}
	printf("\n\n\nReussi: %d / %d\n", corrent_swap, test_num);
	printf("Moyenne: %d swap pour %d elements\n", total_lines / corrent_swap, test_num);
	printf("Lowest: %d swaps\n%s\n\n", lowest_n, lowest);
	printf("Biggest: %d swaps\n%s\n", bigest_n, bigest);
	free(lowest);
	free(bigest);
	return (0);
}