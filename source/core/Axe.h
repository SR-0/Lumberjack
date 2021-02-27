#pragma once

#include "Sprite.h"

class Axe : public Sprite
{
public:

	Axe(float AXE_POSITION_LEFT = 700, float AXE_POSITION_RIGHT = 1075)
		:
		AXE_POSITION_LEFT(AXE_POSITION_LEFT),
		AXE_POSITION_RIGHT(AXE_POSITION_RIGHT),
		Sprite()
	{}

	const float AXE_POSITION_LEFT;
	const float AXE_POSITION_RIGHT;

};

