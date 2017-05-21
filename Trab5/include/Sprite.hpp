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
	float scaleX, scaleY;

	public:
		Sprite();
		Sprite(std::string file);
		~Sprite();

		void open(std::string file);
		void setClip(int x, int y, int w, int h);
		void render(int x, int y, float angle = 0);

		int getWidth();
		int getHeight();

		bool isOpen();

		void setScaleX(float scale);
		void setScaleY(float scale);
};

#endif