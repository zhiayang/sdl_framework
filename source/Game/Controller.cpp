// Controller.cpp
// Copyright (c) 2014 - The Foreseeable Future, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#include <SDL2/SDL.h>
#include "Resources.h"
#include "Controller.h"

Controller::Controller()
{
	this->window = new SDL::Window("Controller", 800, 600);
	this->renderer = new SDL::Renderer(this->window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Controller::Cleanup()
{
	delete this->window;
	delete this->renderer;

	SDL_Quit();
	exit(1);
}

void Controller::HandleSDLEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				this->Cleanup();
				break;
		}
	}
}

void Controller::GameLoop()
{
	SDL::Texture* text = new SDL::Texture("aqua.png", this->renderer);
	this->renderer->Clear();
	this->renderer->Render(text, 50, 50);
	this->renderer->Flush();

	while(true)
	{
		this->HandleSDLEvents();
	}

	delete text;
}












