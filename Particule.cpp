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

static float	pow2(float n)
{
	return (n * n);
}



void	Particule::updateToPosition(sf::Vector2f position, float mass, float s)
{
	float dcarre = pow2(position.x - _px) + pow2(position.y - _py);
	float dist = sqrt(dcarre);

	if (dist <= 10)
		return;

	if (dist > 255)
		_color = sf::Color(0, 255, 255);
	else
		_color = sf::Color(255 - dist, dist, dist);

	float F = (G * _mass * mass) / dcarre;
	float acel = (F / _mass);
	float vx = acel * s;
	float vy = acel * s;
	_mx += vx * (position.x - _px);
	_my += vy * (position.y - _py);
	_px += _mx;
	_py += _my;
}
