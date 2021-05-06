/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:55:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 13:54:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_credit(const char *sentence, const char *color)
{
	const char	*border_colors = "\033[0;37m";
	const int	line_width = 60;
	const int	space = (line_width - ft_strlen(sentence)) / 2 - 1;
	int i;

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

int	quit_properly(t_ray *c_ray)
{
	system("killall afplay &>/dev/null &");
	system("clear");
	printf("\033[0;37m");
	printf("------------------------------------------------------------\n");
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
	print_credit("http://www.online-utility.org/image/convert/to/XPM", "\033[0;36m");
	print_credit("http://www.piskelapp.com", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("", "\033[0;36m");
	print_credit("See you!", "\033[0;36m");
	printf("------------------------------------------------------------\n");
	mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
	free_t_map(c_ray->c_map);
	exit(0);
}

int	key_press(int key, t_ray *c_ray)
{
	if (key == KEY_ESC)
		quit_properly(c_ray);
	if (key == KEY_UP_MOVE)
		c_ray->go_forward = 1;
	else if (key == KEY_DOWN_MOVE)
		c_ray->go_backward = 1;
	else if (key == KEY_LEFT_MOVE)
		c_ray->go_left = 1;
	else if (key == KEY_RIGHT_MOVE)
		c_ray->go_right = 1;
	else if (key == KEY_RIGHT_ARROW)
		c_ray->turn_right = 1;
	else if (key == KEY_LEFT_ARROW)
		c_ray->turn_left = 1;
	else if (key == KEY_UP_ARROW)
		c_ray->look_up = 1;
	else if (key == KEY_DOWN_ARROW)
		c_ray->look_down = 1;
	else if (key == KEY_SPACE)
		c_ray->shoot = 1;
	return (1);
}

int	key_release(int key, t_ray *c_ray)
{
	if (key == KEY_UP_MOVE)
		c_ray->go_forward = 0;
	else if (key == KEY_DOWN_MOVE)
		c_ray->go_backward = 0;
	else if (key == KEY_LEFT_MOVE)
		c_ray->go_left = 0;
	else if (key == KEY_RIGHT_MOVE)
		c_ray->go_right = 0;
	else if (key == KEY_RIGHT_ARROW)
		c_ray->turn_right = 0;
	else if (key == KEY_LEFT_ARROW)
		c_ray->turn_left = 0;
	else if (key == KEY_UP_ARROW)
		c_ray->look_up = 0;
	else if (key == KEY_DOWN_ARROW)
		c_ray->look_down = 0;
	else if (key == KEY_ALT)
		c_ray->look_offset = 0;
	return (1);
}

int	exit_button(t_ray *c_ray)
{
	return (quit_properly(c_ray));
}
