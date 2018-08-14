#pragma once
#include <cstdlib>

namespace MathExtension
{
	static int GetRandomInt(int a, int b)
	{
		if (a == b)
			return a;

		return (rand() % (b - a) + a);
	}
}