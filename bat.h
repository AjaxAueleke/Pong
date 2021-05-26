#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat
{
private:
	RectangleShape shape;
	Vector2f position;
	RectangleShape bat_shape;
	double speed;
public:
	Bat(double pos_x, double pos_y);
	FloatRect m_getPosition();
	RectangleShape m_getShape();
	void Move(double x);
};