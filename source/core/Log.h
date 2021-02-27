#pragma once

#include "Sprite.h"
#include "Common.h"

class Log : public Sprite
{
public:

	Log() : Sprite() {}

public:

	void update(float deltaTime)
	{
		if (isActive())
		{
			setPosition(getPosition().x + (speed.x * deltaTime), getPosition().y + (speed.y * deltaTime));
			
			if ( (getPosition().x < -100) || (getPosition().x > 2000) )
			{
				setActive(false);
				setPosition(810, 720);
			}
		}
	} 

public:

	vec2f getSpeed()
	{
		return speed;
	}

	bool isActive()
	{
		return active;
	}

public:

	void setSpeed(vec2f speed)
	{
		this->speed = speed;
	}

	void setActive(bool active)
	{
		this->active = active;
	}

private:

	vec2f	speed	= vec2f(1000.f, -1500.f);
	bool	active	= false;

};

