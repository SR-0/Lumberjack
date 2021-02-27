#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class vec2f : public sf::Vector2f
{
public:

	vec2f(float x = 0.f, float y = 0.f)
		:
		sf::Vector2f(x, y)
	{}

};

class vec2i : public sf::Vector2i
{
public:

	vec2i(int x = 0, int y = 0)
		:
		sf::Vector2i(x, y)
	{}

};

class FloatRect : public sf::FloatRect
{
public:

	FloatRect(
		unsigned int left = 0U,
		unsigned int top = 0U,
		unsigned int width = 0U,
		unsigned int height = 0U)
		:
		sf::FloatRect(left, top, width, height)
	{}

};

enum class Side
{
	Left,
	Right,
	None
};

