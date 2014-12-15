// Surface.cpp
// Copyright (c) 2014 - The Foreseeable Future, zhiayang@gmail.com
// Licensed under the Apache License Version 2.0.

#include "SDLWrapper.h"
namespace SDL
{
	Surface::Surface(const char* path) : Surface(AssetLoader::Load(path))
	{
	}

	Surface::Surface(AssetLoader::Asset* ass)
	{
		using namespace AssetLoader;

		assert(ass);
		this->asset = ass;

		switch(ass->type)
		{
			case AssetType::ImagePNG:
				this->sdlSurf = IMG_LoadPNG_RW(this->asset->sdlrw);
				if(!this->sdlSurf)
					ERROR("Failed to load PNG image from asset '%s'", this->asset->path.c_str());

				break;

			default:
				ERROR("Cannot create surface from unknown type of asset");
		}
	}

	Surface::~Surface()
	{
		SDL_FreeSurface(this->sdlSurf);
		AssetLoader::Unload(this->asset);
	}

}
