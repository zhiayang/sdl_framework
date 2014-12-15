// MathPrimitives.h
// Copyright (c) 2014 - The Foreseeable Future, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#pragma once
#include <cmath>
#include <SDL2/SDL_shape.h>
#include <stdint.h>

namespace Math
{
	struct Point
	{
		Point(uint32_t x, uint32_t y) : x(x), y(y) { }
		uint32_t x;
		uint32_t y;
	};

	struct Rectangle
	{
		Point origin;
		uint32_t width;
		uint32_t height;

		double area()
		{
			return this->width * this->height;
		}

		Point centre()
		{
			return Point(this->origin.x + (this->width / 2), this->origin.y + (this->height / 2));
		}
	};

	struct Circle
	{
		Point origin;
		uint32_t radius;

		double area()
		{
			return M_PI * this->radius * this->radius;
		}
	};

	SDL_Rect ToSDL(Rectangle rect);
}












