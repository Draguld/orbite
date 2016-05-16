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

#include <stdlib.h>
#include <time.h>

#include "std.hpp"
#include "sfml.hpp"

#include "Particule.hpp"

#include "options.hpp"

sf::RenderWindow	win;
sf::Event			eve;

sf::CircleShape		planet(10.0f);
double				pl_mass;

sf::VertexArray		part(sf::Points, PN);
Particule			particule[PN];
sf::VertexArray		trace(sf::LinesStrip, 0);

int		main()
{
	sf::Clock			clock;
	double				s = 0;
	
	double				viewZoom = 1.0f;

	srand(time(0));

	for (u32 i = 0; i < PN; i++)
	{
		particule[i]._px = rand() % WINX;
		particule[i]._py = rand() % WINY;
		if (INITIAL_SPEED_ACTIVATE)
		{
			particule[i]._mx = ((rand() % INITIAL_SPEED) - INITIAL_SPEED / 2) / INITIAL_SPEED_DIV;
			particule[i]._my = ((rand() % INITIAL_SPEED) - INITIAL_SPEED / 2) / INITIAL_SPEED_DIV;
		}
		else
		{
			particule[i]._mx = 0;
			particule[i]._my = 0;
		}
		particule[i]._mass = PAR_MASS;
		particule[i]._color = PCOLOR;
	}

	planet.setPosition(sf::Vector2f(WINX/2, WINY/2));
	planet.setOrigin(sf::Vector2f(10.0f, 10.0f));
	planet.setFillColor(sf::Color::Blue);

	win.create(sf::VideoMode(WINX, WINY), "ORBITE");
	win.setFramerateLimit(MAXFPS);
	clock.restart();
	while (win.isOpen())
	{
		s = clock.restart().asSeconds();
		s *= SPEED;

		sf::View view = win.getDefaultView();
		view.zoom(viewZoom);

		while (win.pollEvent(eve))
		{
			if (eve.type == sf::Event::Closed)
				win.close();
			if (eve.type == sf::Event::KeyPressed)
			{
				if (eve.key.code == sf::Keyboard::Add)
					viewZoom -= 0.25f;
				else if (eve.key.code == sf::Keyboard::Subtract)
					viewZoom += 0.25f;
				else if (eve.key.code == sf::Keyboard::Space)
				{
					trace.clear();
					for (u32 i = 0; i < PN; i++)
					{
						particule[i]._px = rand() % WINX;
						particule[i]._py = rand() % WINY;
						if (INITIAL_SPEED_ACTIVATE)
						{
							particule[i]._mx = ((rand() % INITIAL_SPEED) - INITIAL_SPEED / 2) / INITIAL_SPEED_DIV;
							particule[i]._my = ((rand() % INITIAL_SPEED) - INITIAL_SPEED / 2) / INITIAL_SPEED_DIV;
						}
						else
						{
							particule[i]._mx = 0;
							particule[i]._my = 0;
						}
						particule[i]._mass = PAR_MASS;
						particule[i]._color = PCOLOR;
					}		
				}
			}
		}
		
		planet.setPosition((sf::Vector2f)sf::Mouse::getPosition(win));
		for (u32 i = 0; i < PN; i++)
		{
			particule[i].updateToPosition(planet.getPosition(), PL_MASS, s);
			part[i].position = sf::Vector2f(particule[i]._px, particule[i]._py);
			part[i].color = particule[i]._color;
			if (ACTIVATE_ORBIT_TRACE)
			{
				sf::Vertex cpy = part[i];
				trace.append(cpy);
			}
		}
		win.setView(view);
		win.clear(sf::Color::Black);
		win.draw(planet);
		win.draw(part);
		win.draw(trace);
		win.display();
	}
	return (0);
}
