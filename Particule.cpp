//////////////////////////////////////////////////////////////////////////////////
//																				//
//    Copyright (C) 2016 RUE Thomas												//
//																				//
//    This program is free software; you can redistribute it and/or modify		//
//    it under the terms of the GNU General Public License as published by		//
//    the Free Software Foundation; either version 2 of the License, or			//
//    (at your option) any later version.										//
//																				//
//    This program is distributed in the hope that it will be useful,			//
//    but WITHOUT ANY WARRANTY; without even the implied warranty of			//
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the				//
//    GNU General Public License for more details.								//
//																				//
//    You should have received a copy of the GNU General Public License along	//
//    with this program; if not, write to the Free Software Foundation, Inc.,	//
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.				//
//																				//
//////////////////////////////////////////////////////////////////////////////////

#include "Particule.hpp"

Particule::Particule():
_px(0.0f),
_py(0.0f),
_mx(0.0f),
_my(0.0f),
_mass(0.0f),
_color(0.0f, 0.0f, 0.0f)
{
		
}

Particule::~Particule()
{
		
}

static double	pow2(double n)
{
	return (n * n);
}



void	Particule::updateToPosition(sf::Vector2f position, double mass, double s)
{
	double dcarre = pow2(position.x * MPARPIXEL - _px * MPARPIXEL) + pow2(position.y * MPARPIXEL - _py * MPARPIXEL);
	double dist = sqrt(dcarre);

	if (dist <= 5.0f * MPARPIXEL)
	{
		if (dist == 0.0f)
		{
			_mx *= -1;
			_my *= -1;
		}
		_px += _mx;
		_py += _my;
		return;
	}
//color
//color
//color
	double F = G * ((_mass * mass) / dcarre);
	double acel = (F / _mass);
	double vx = acel * s;
	double vy = acel * s;
	_mx += vx * (position.x - _px);
	_my += vy * (position.y - _py);
	_px += _mx;
	_py += _my;
}
