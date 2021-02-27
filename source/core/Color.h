#pragma once

#include <SFML/Graphics/Color.hpp>

class Color : public sf::Color
{
public:

	//Color(const Color& color)
	//	:
	//	sf::Color(color)
	//{}

	Color(
		unsigned int r = 255U,
		unsigned int g = 255U,
		unsigned int b = 255U,
		unsigned int a = 255U)
		:
		sf::Color(r, g, b, a)
	{}

};

