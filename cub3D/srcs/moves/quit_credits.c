/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_credits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:04:23 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 16:14:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_credit(const char *sentence, const char *color)
{
	const char	*border_colors = "\033[0;37m";
	const int	line_width = 60;
	const int	space = (line_width - ft_strlen(sentence)) / 2 - 1;
	int			i;

	printf("%s", border_colors);
	printf("|");
	printf("%s", color);
	i = -1;
	while (++i < space)
		printf(" ");
	printf("%s", sentence);
	i = -1;
	while (++i < space)
		printf(" ");
	printf("%s", border_colors);
	printf("|\n");
}

static void	credits_center(t_ray *c_ray)
{
	print_credit("Thanks for playing", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("Game Development", "\033[0;33m");
	print_credit("Tpetit", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("Design", "\033[0;33m");
	print_credit("Design Manager  Ybrutout", "\033[0;36m");
	print_credit("Design Assistant  Tpetit", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("Sounds", "\033[0;33m");
	print_credit("https://www.myinstants.com", "\033[0;36m");
	print_credit("https://www.zapsplat.com", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("Useful Links", "\033[0;33m");
	print_credit("http://www.online-utility.org/image/convert/to/XPM",
		"\033[0;36m");
	print_credit("http://www.piskelapp.com", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("See you!", "\033[0;36m");
}

int	quit_properly(t_ray *c_ray)
{
	system("killall afplay &>/dev/null &");
	system("clear");
	printf("\033[0;37m");
	printf("------------------------------------------------------------\n");
	credits_center(c_ray);
	printf("------------------------------------------------------------\n");
	mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
	free_t_map(c_ray->c_map);
	exit(0);
}
