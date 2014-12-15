// Primitives.cpp
// Copyright (c) 2014 - The Foreseeable Future, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#include "MathPrimitives.h"

namespace Math
{
	SDL_Rect ToSDL(Rectangle rect)
	{
		SDL_Rect r;
		r.x = rect.origin.x;
		r.y = rect.origin.y;
		r.w = rect.width;
		r.h = rect.height;

		return r;
	}
}
