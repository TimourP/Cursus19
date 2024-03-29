/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:18:54 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 11:55:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static float sign(Point const & p1, Point const & p2, Point const & p3)
{
	return (p1.getXV() - p3.getXV()) * (p2.getYV() - p3.getYV()) - (p2.getXV() - p3.getXV()) * (p1.getYV() - p3.getYV());
}

bool bsp(Point const & p1, Point const & p2, Point const & p3, Point const & point)
{
	float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, p1, p2);
    d2 = sign(point, p2, p3);
    d3 = sign(point, p3, p1);
	has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
    has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

    return !(has_neg && has_pos);
}
