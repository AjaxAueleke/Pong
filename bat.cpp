#include "bat.h"

Bat::Bat(double pos_x, double pos_y)
{

	this->position.x = pos_x;
	this->position.y = pos_y;
	shape.setPosition(position);
	shape.setSize(Vector2f(50,2));
}
RectangleShape Bat::m_getShape()
{
	return shape;
}
FloatRect Bat::m_getPosition()
{
	return shape.getGlobalBounds();
}
void Bat::Move(double x)
{
	this->position.x += x;
	if (this->position.x >= 800 || this->position.x <= 0)
	{
		this->position.x -= x;
	}
	shape.setPosition(position);
}