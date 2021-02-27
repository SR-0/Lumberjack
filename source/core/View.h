#pragma once

#include <SFML/Graphics/View.hpp>

#include "Common.h"

class View : public sf::View
{
public:

	View(FloatRect rectangle)
		:
		sf::View(rectangle)
	{}

};


