#include "../../includes/cub3d.h"

int	get_line_height(t_ray *c_ray, float value, int *side, float *text_value)
{
	t_ray_calc	calc;

	calc.hit = 0;
	calc.x = *side;
	calc.mapx = (int)c_ray->player_posx;
	calc.mapy = (int)c_ray->player_posy;
	calc.angle = c_ray->player_angle + value;
	if (calc.angle < 0)
		calc.angle += 2 * PI;
	if (calc.angle > 2 * PI)
		calc.angle -= 2 * PI;
	calc.d_distx = fabs(div_zero(1, cos(calc.angle)));
	calc.d_disty = fabs(div_zero(1, cos(PI / 2 - calc.angle)));
	set_steps(c_ray, &calc);
	set_hit(c_ray, &calc, 1);
	*side = get_side(&calc);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	c_ray->all_distances[calc.x] = calc.final_dist;
	*text_value = get_texture_value(c_ray, &calc);
	calc.line_height = c_ray->screen_h / calc.final_dist;
	calc.line_height = calc.line_height / cos(calc.angle - c_ray->player_angle);
	return (calc.line_height);
}

float	get_distance(t_ray *c_ray, float value, int *side)
{
	t_ray_calc	calc;

	calc.hit = 0;
	calc.mapx = (int)c_ray->player_posx;
	calc.mapy = (int)c_ray->player_posy;
	calc.angle = c_ray->player_angle + value;
	if (calc.angle < 0)
		calc.angle += 2 * PI;
	if (calc.angle > 2 * PI)
		calc.angle -= 2 * PI;
	calc.d_distx = fabs(div_zero(1, cos(calc.angle)));
	calc.d_disty = fabs(div_zero(1, cos(PI / 2 - calc.angle)));
	set_steps(c_ray, &calc);
	set_hit(c_ray, &calc, 0);
	*side = get_side(&calc);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	return (calc.final_dist);
}

float	get_absolute_distance(t_ray *c_ray, float angle)
{
	t_ray_calc	calc;

	calc.hit = 0;
	calc.mapx = (int)c_ray->player_posx;
	calc.mapy = (int)c_ray->player_posy;
	calc.angle = angle;
	if (calc.angle < 0)
		calc.angle += 2 * PI;
	if (calc.angle > 2 * PI)
		calc.angle -= 2 * PI;
	calc.d_distx = fabs(div_zero(1, cos(calc.angle)));
	calc.d_disty = fabs(div_zero(1, cos(PI / 2 - calc.angle)));
	set_steps(c_ray, &calc);
	set_hit(c_ray, &calc, 0);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	return (calc.final_dist);
}
