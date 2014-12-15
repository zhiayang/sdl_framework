// Controller.h
// Copyright (c) 2014 - The Foreseeable Future, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#pragma once

#include "Util.h"
#include "SDLWrapper.h"

class Controller
{
	public:
		Controller();

		void GameLoop();
		void HandleSDLEvents();
		void Cleanup();



		Controller* instance() { return this; }

	private:
		SDL::Window*	window;
		SDL::Renderer*	renderer;
};
