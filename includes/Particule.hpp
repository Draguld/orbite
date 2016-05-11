#ifndef		PARTICULE_HPP
#define		PARTICULE_HPP

#include "std.hpp"
#include "sfml.hpp"

#ifndef G
#define G  6.67259E-11  //constante gravitationnelle
#endif

class	Particule
{
	public:
	Particule();
	~Particule();

	void		updateToPosition(sf::Vector2f position, float mass, float s);
	float		_px;
	float		_py;
	float		_mx;
	float		_my;
	float		_mass;
	sf::Color	_color;
};

#endif
