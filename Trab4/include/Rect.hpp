#ifndef RECT_H_
#define RECT_H_

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Vec2.hpp"
#include "SDL.h"
#include "SDL_image.h"

class Rect{
	public:
		float x,y,w,h;

		Rect(){}
		Rect(float _x, float _y, float _w, float _h);
		void displace(Vec2<float> vector);
		Vec2<float> center();
		float distanceRect(Rect rectangle);
		bool isInside(float _x, float _y);
};

#endif