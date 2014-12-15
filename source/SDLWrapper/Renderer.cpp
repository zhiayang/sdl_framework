// Renderer.cpp
// Copyright (c) 2014 - The Foreseeable Future, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#include "SDLWrapper.h"

namespace SDL
{
	void Renderer::Clear()
	{
		SDL_RenderClear(this->sdlRenderer);
	}

	void Renderer::Render(Texture* text, Math::Point pt)
	{
		this->Render(text, pt.x, pt.y);
	}

	void Renderer::Render(Texture* text, uint32_t x, uint32_t y)
	{
		SDL_Rect tgt;
		tgt.x = x;
		tgt.y = y;

		// get the texture's size
		SDL_QueryTexture(text->sdlTexture, 0, 0, &tgt.w, &tgt.h);
		SDL_RenderCopy(this->sdlRenderer, text->sdlTexture, 0, &tgt);
	}

	void Renderer::Render(Texture* text, Math::Rectangle dest)
	{
		SDL_Rect d = Math::ToSDL(dest);

		SDL_RenderCopy(this->sdlRenderer, text->sdlTexture, 0, &d);
	}

	void Renderer::Render(Texture* text, Math::Rectangle src, Math::Rectangle dest)
	{
		SDL_Rect s = Math::ToSDL(src);
		SDL_Rect d = Math::ToSDL(dest);

		SDL_RenderCopy(this->sdlRenderer, text->sdlTexture, &s, &d);
	}

	void Renderer::Flush()
	{
		SDL_RenderPresent(this->sdlRenderer);
	}

}



