#pragma once

#include "RenderWindow.h"
#include "RectangleShape.h"
#include "Sound.h"
#include "Common.h"
#include "Text.h"

class Timebar : public sf::RectangleShape
{
public:

	Timebar(float startWidth = 400, float startHeight = 80, float timeTolal = 0.f, float timeRemaining = 6.f)
		:
		startWidth(startWidth),
		startHeight(startHeight),
		timeTotal(timeTolal),
		timeRemaining(timeRemaining),
		widthPerSecond(startWidth / timeRemaining),
		sf::RectangleShape(vec2f(startWidth, startHeight))
	{}

public:

	void update(RenderWindow& window, float deltaTime, bool& paused, Text& textMessage, Sound& outOfTime)
	{
		timeRemaining -= deltaTime;

		setSize(vec2f(widthPerSecond * timeRemaining, startHeight));

		if (timeRemaining <= 0.f)
		{
			outOfTime.play();
			paused = true;

			textMessage.setString("Out of time!!!");

			textMessage.setOrigin(
				textMessage.getLocalBounds().left	+ (textMessage.getLocalBounds().width	/ 2),
				textMessage.getLocalBounds().top	+ (textMessage.getLocalBounds().height	/ 2));
			
			textMessage.setPosition(window.getSize().x / 2, window.getSize().y / 2);

		}

	}

public:

	float getStartWidth()
	{
		return startWidth;
	}

	float getStartHeight()
	{
		return startHeight;
	}

	float getTimeRemaining()
	{
		return timeRemaining;
	}

	float getTimeTotal()
	{
		return timeTotal;
	}

	float getWidthPerSecond()
	{
		return widthPerSecond;
	}

public:

	void setStartWidth(float startWidth)
	{
		this->startWidth = startWidth;
	}

	void setStartHeight(float startHeight)
	{
		this->startHeight = startHeight;
	}

	void setTimeRemaining(float timeRemaining)
	{
		this->timeRemaining = timeRemaining;
	}

	void setTimeTotal(float timeTotal)
	{
		this->timeTotal = timeTotal;
	}

	void setWidthPerSecond(float widthPerSecond)
	{
		this->widthPerSecond = widthPerSecond;
	}

private:

	float	startWidth;
	float	startHeight;
	float	timeRemaining;
	float	timeTotal;
	float	widthPerSecond;

};

