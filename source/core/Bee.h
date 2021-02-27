#pragma once

#include "Sprite.h"
#include "Common.h"

class Bee : public Sprite
{
public:

	Bee() : Sprite() {}

public:

	void update(float deltaTime, float speed, const vec2f position)
	{
		if (!isActive())
		{
			setSpeed(speed);
			setPosition(position);
			setActive(true);
		}
		else
		{
			setPosition(getPosition().x - (getSpeed() * deltaTime), getPosition().y);

			if (getPosition().x < -getLocalBounds().width)
			{
				setActive(false);
			}
		}
	}

public:

	float getSpeed()
	{
		return speed;
	}

	bool isActive()
	{
		return active;
	}

public:

	void setSpeed(float speed)
	{
		this->speed = speed;
	}

	void setActive(bool active)
	{
		this->active = active;
	}

private:

	float	speed	= 0.f;
	bool	active	= false;

};

