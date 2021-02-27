#pragma once

#include "Sprite.h"

class Cloud : public Sprite
{
public:

	Cloud() : Sprite() {}

public:

	void update(float deltaTime, float speed, const vec2f position, float screenWidth)
	{
		if (!isActive())
		{
			setSpeed(speed);
			setPosition(position);
			setActive(true);
		}
		else
		{
			setPosition(getPosition().x + (getSpeed() * deltaTime), getPosition().y);

			if (getPosition().x > screenWidth)
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

