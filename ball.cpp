#include "ball.h"
#include <iostream>
Ball::Ball(Vector2f pos)
{
	m_shape.setRadius(5);
	m_shape.setPosition(pos);
	
}
int Ball::collision_bat(Bat b, Time td, int score)
{
	if (b.m_getShape().getGlobalBounds().contains(this->m_shape.getPosition()))
	{

		speed_y = score + speed_y;
		speed_x = score + speed_x;
		speed_y = -1 * speed_y;
			
		std::cout << this->m_shape.getPosition().x - b.m_getShape().getPosition().x<< std::endl;
		score++;
		
	}
	return score;
}
void Ball::setSpeed(double s_x, double s_y)
{
	this->speed_x = s_x;
	this->speed_y = s_y;
}
void Ball::move(Time td)
{
	m_shape.setPosition(m_shape.getPosition().x + this->speed_x * 0.01, m_shape.getPosition().y + this->speed_y * 0.01);
}

CircleShape Ball::m_getShape()
{
		return m_shape;
}
void Ball::collision_s()
{
	if (m_shape.getPosition().x < 1 || m_shape.getPosition().x > 800)
	{
		speed_x = -speed_x;
	}
}
void Ball::collision_sides()
{
	if ( m_shape.getPosition().y < 0)
	{
		speed_y = -speed_y;
	}
}
void Ball::setPosition(Vector2f f)
{
	m_shape.setPosition(f);
}