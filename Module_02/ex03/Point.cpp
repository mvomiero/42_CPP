/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:35:59 by mvomiero          #+#    #+#             */
/*   Updated: 2023/06/09 18:12:48 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const float x, const float y ) : _x(x), _y(y) {}

Point::Point( const Point &src ) : _x(src._x), _y(src._y) {}

Point::~Point() {}

Point&  Point::operator=( const Point &rhs ) {
	if ( this != &rhs ) {
		( Fixed ) this->_x = rhs.getX(); // you get a float so have to cast it into a Fixed object for it to work
		( Fixed ) this->_y = rhs.getY();
	}
	return *this;
}

Fixed Point::getX( void ) const {
	return this->_x;
}

Fixed Point::getY( void ) const {
	return this->_y;
}