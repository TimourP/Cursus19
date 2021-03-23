/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:22:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 11:22:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static float	reste_angle(float angle)
{
	int i;
	int prec;

	prec = 20;
	i = -1;
	while (++i < prec)
	{
		if (angle <= (i + 0.5) * PI * (2.0 / prec) && angle >= (i - 0.5) * PI * (2.0 / prec))
			return (PI * i * (2.0 / prec));
	}
	return (0);
}