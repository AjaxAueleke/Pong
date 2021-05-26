#pragma once
#include "bat.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Bat;
class Ball
{
private:
	CircleShape m_shape;
	double speed_x;
	double speed_y;
public:
	Ball(Vector2f pos); //Constructor
	void setPosition(Vector2f f); 
	CircleShape m_getShape(); //draw SFML
	int collision_bat(Bat b, Time td, int score);
	void collision_sides();
	void setSpeed(double s_x, double s_y);
	void collision_s();
	void move(Time td);
};