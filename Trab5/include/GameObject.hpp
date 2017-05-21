#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Rect.hpp"
#include "SDL.h"
#include "SDL_image.h"

class GameObject{
	public:
		int z;
		float rotation;

		Rect box;
		GameObject(){rotation = 0;}
		virtual ~GameObject(){};

		virtual void update(float dt) = 0;
		virtual void render() = 0;
		virtual bool isDead() = 0;
};

#endif