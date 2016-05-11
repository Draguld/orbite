#include "std.hpp"
#include "sfml.hpp"

#include "Particule.hpp"

#define	PN 100000
#define WINX 800
#define WINY 800
#define	MAXFPS 30

#define ACTIVATE_ORBIT_TRACE false
//FOR TRUE RESULT ACTIVATE THIS OPTION WHITE ONE PARTICULE (PN 1)//


#define PL_MASS 100000000000000.0f
#define PAR_MASS 24800.0001f

#define SPEED 1.0f

sf::RenderWindow	win;
sf::Event			eve;


sf::CircleShape		planet(10.0f);
float				pl_mass;

sf::VertexArray		part(sf::Points, PN);
Particule			particule[PN];
sf::VertexArray		trace(sf::LinesStrip, 0);

int		main()
{
	sf::Clock			clock;
	float				s = 0;
	
	float				viewZoom = 1.0f;

	srand(time(0));

	for (u32 i = 0; i < PN; i++)
	{
		particule[i]._px = rand() % WINX;
		particule[i]._py = rand() % WINY;
		particule[i]._mx = 0.0f;
		particule[i]._my = 0.0f;
		particule[i]._mass = PAR_MASS;
		particule[i]._color = sf::Color(0.0f, 0.0f, 0.0f);
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
					viewZoom += 0.25f;
				else if (eve.key.code == sf::Keyboard::Subtract)
					viewZoom -= 0.25f;
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
//		win.draw(planet);
		win.draw(part);
		win.draw(trace);
		win.display();
	}
	return (0);
}
