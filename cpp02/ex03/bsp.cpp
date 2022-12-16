/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:59:57 by mcombeau          #+#    #+#             */
/*   Updated: 2022/12/16 10:44:22 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

Fixed	getTriangleArea( Point const a, Point const b, Point const c )
{
	Fixed	area = a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY()) / 2;
	Fixed	absArea( abs( area.toFloat() ) );
	return ( absArea );
}

bool bsp( Point const a, Point const b, Point const c, Point const p )
{
	// TODO for repush: use vectors instead of triangle areas
	// to determine if the point is in the triangle or not. The
	// area calculation is breakable in certain cases where the point
	// is not inside the triangle but should be..
	Fixed	areaTriangle = getTriangleArea(a, b, c);
	Fixed	areaPAB = getTriangleArea(p, a, b);
	Fixed	areaPBC = getTriangleArea(p, b, c);
	Fixed	areaPAC = getTriangleArea(p, a, c);

	if ( areaPAB != 0 && areaPBC != 0 && areaPBC != 0		
		&& areaPAB + areaPBC + areaPAC <= areaTriangle )
		return ( true );
	return ( false );
}
