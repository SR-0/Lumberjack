#pragma once

#include <SFML/Graphics/Sprite.hpp>

class Sprite : public sf::Sprite 
{ 
public: 
	
	Sprite() 
		: 
		sf::Sprite() 
	{}  

public:

	void setup(Texture& texture, vec2f origin, vec2f position, const sf::Color& color)
	{
		sf::Sprite::setTexture(texture);
		sf::Sprite::setOrigin(origin);
		sf::Sprite::setPosition(position);
		sf::Sprite::setColor(color);
	}

};
