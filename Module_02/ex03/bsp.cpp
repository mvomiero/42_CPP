/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:44:36 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/09 17:44:42 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// source for the explanation and the formula: https://www.youtube.com/watch?v=HYAgJN3x4GA
// then readapted for this exercise: for example vertexes and edges excluded

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed s1 = c.getY() - a.getY();
	Fixed s2 = c.getX() - a.getX();
	Fixed s3 = b.getY() - a.getY();
	Fixed s4 = point.getY() - a.getY();

	Fixed w1 = (a.getX() * s1 + s4 * s2 - point.getX() * s1) / (s3 * s2 - (b.getX()-a.getX()) * s1);
	Fixed w2 = (s4- w1 * s3) / s1;
	return w1 > 0 && w2 > 0 && (w1 + w2) <= 1;
}
