#ifndef SPRITE_H_
#define SPRITE_H_

#include <stdlib.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Sprite{
	SDL_Texture* texture;
	int width, height;
	SDL_Rect clipRect;

	public:
		Sprite();
		Sprite(std::string file);
		~Sprite();

		void open(std::string file);
		void setClip(int x, int y, int w, int h);
		void render(int x, int y);

		int getWidth();
		int getHeight();

		bool isOpen();
};

#endif