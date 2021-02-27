#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class RectangleShape : sf::RectangleShape
{
public:

	RectangleShape(float width, float height)
		:
		sf::RectangleShape(sf::Vector2f(width, height))
	{}

	void setSize(float width, float height)
	{
		sf::RectangleShape::setSize(vec2f(width, height));
	}
};

