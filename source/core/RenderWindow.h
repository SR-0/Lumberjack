#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

class Event	: public sf::Event		{};

class Title	: public sf::String	
{
public:

	Title(const std::string& title)
		:
		sf::String(title)
	{}

};

class VideoMode	: public sf::VideoMode	
{
public:

	VideoMode(unsigned int width, unsigned int height)
		:
		sf::VideoMode(width, height)
	{}

};

class ContextSettings : public sf::ContextSettings
{
public:

	ContextSettings(
		unsigned int	depth			= 0U,
		unsigned int	stencil			= 0U,
		unsigned int	antialiasing	= 0U,
		unsigned int	major			= 1U,
		unsigned int	minor			= 1U,
		unsigned int	attributes		= 0U,
		bool			sRbg			= false)
		:
		sf::ContextSettings(
			depth,
			stencil,
			antialiasing,
			major,
			minor,
			attributes,
			sRbg)
	{}

};

class RenderWindow : public sf::RenderWindow
{
public:

	RenderWindow(
		const sf::VideoMode&		videoMode,
		const sf::String&			title,
		const sf::Uint32&			style,
		const sf::ContextSettings&	settings)
		:
		sf::RenderWindow(
			videoMode,
			title,
			style,
			settings)
	{}

};