#pragma once

#include "Sprite.h"
#include "Tree.h"
#include "Common.h"

class Player : public Sprite
{
public:

	Player() : Sprite() {}

public:

	int healthPoints = 0;
	enum class Side side = Side::Left;

};

