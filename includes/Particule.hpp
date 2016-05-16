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

#ifndef		PARTICULE_HPP
#define		PARTICULE_HPP

#include "std.hpp"
#include "sfml.hpp"

#include "options.hpp"

#ifndef G
#define G  6.67259E-11  //constante gravitationnelle
#endif

class	Particule
{
	public:
	Particule();
	~Particule();

	void		updateToPosition(sf::Vector2f position, double mass, double s);
	double		_px;
	double		_py;
	double		_mx;
	double		_my;
	double		_mass;
	sf::Color	_color;
};

#endif
