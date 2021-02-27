#pragma once

#include <cstdlib>
#include <time.h>

class RandomNumberGenerator
{
public:

	RandomNumberGenerator()
	{
		srand(time(0));
	}

public:

	void seed(unsigned int seed)
	{
		srand(seed);
	}

	float range(unsigned int start, unsigned int end)
	{
		return rand() % (unsigned int)(end + 1 - start) + start;
	}

};