#pragma once

#include "Sprite.h"
#include "Common.h"
#include <iostream>

class Tree : public Sprite
{
public:

	Tree(int numOfBranches = 6)
		:
		numOfBranches(numOfBranches),
		branches(new Sprite[numOfBranches]),
		sides(new Side[numOfBranches]),
		Sprite()
	{}

public:

	void setup(Texture& texture, vec2f origin, vec2f position, const sf::Color& color)
	{
		Sprite::setup(texture, origin, position, color);
	}

	void setup(unsigned int numOfBranches, Sprite& branch, RandomNumberGenerator& rng)
	{
		for (auto i = 0; i < numOfBranches; i++)
		{
			branches[i].setTexture(*branch.getTexture()); // 'branch.png'
			branches[i].setPosition(-branches[i].getLocalBounds().width, -branches[i].getLocalBounds().height); // offscreen
			branches[i].setOrigin(branches[i].getLocalBounds().width / 2, branches[i].getLocalBounds().height / 2); // center

			for (auto i = 0; i < numOfBranches; i++)
			{
				sides[i] = Side::None;
			}
		}

		updateBranch(rng);
		updateBranch(rng);
		updateBranch(rng);
		updateBranch(rng);
		updateBranch(rng);
	}

public:

	void updateBranch(RandomNumberGenerator& rng)
	{
		for (auto i = numOfBranches - 1; i > 0; i--)
		{
			sides[i] = sides[i - 1];
		}
		
		switch ((int)rng.range(0, 5))
		{
			case 0:
			{
				sides[0] = Side::Left;
			}
			break;

			case 1:
			{
				sides[0] = Side::Right;
			}
			break;

			default:
			{
				sides[0] = Side::None;
			}
			break;
		}
	}

public:

	void update(RenderWindow& window)
	{
		for (auto i = 0; i < numOfBranches; i++)
		{
			float height = i * 150;

			if (sides[i] == Side::Left)
			{
				branches[i].setPosition(610, height);
				branches[i].setRotation(180);
			}
			else if (sides[i] == Side::Right)
			{
				branches[i].setPosition(1330, height);
				branches[i].setRotation(0);
			}
			else
			{
				branches[i].setPosition(3000, height);
			}
		}
	}

public:

	unsigned int getNumOfBranches()
	{
		return numOfBranches;
	}

	Sprite*	getBranches()
	{
		return branches;
	}
	
	Side* getSides()
	{
		return sides;
	}

private:

	unsigned int		numOfBranches	= 0;
	Sprite*				branches		= nullptr;
	enum class Side*	sides			= nullptr;
	
};

