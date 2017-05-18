#ifndef FACE_H_
#define FACE_H_

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Face : public GameObject{
	int hitPoints;
	Sprite sp;

	public:
		Face(float x, float y);
		~Face();

		void damage(int varDamage);

		void update(float dt);
		void render();
		bool isDead();


};

#endif