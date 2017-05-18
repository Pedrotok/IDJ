#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

template<class T>
class Vec2{
	public:
		T x,y;

		Vec2();
		Vec2(T _x, T _y);
		Vec2 operator-(const Vec2& vector) const;
		Vec2 operator+(const Vec2& vector) const;
		float magnitude() const;
		Vec2 normalVec() const;
		float distance(const Vec2& vector) const;
		float angle() const;
		void rotate(int ang);
};

const float PI = acos(-1);

template<class T>
Vec2<T>::Vec2(){}

template<class T>
Vec2<T>::Vec2(T _x, T _y) : x(_x), y(_y){}

template<class T>
Vec2<T> Vec2<T>::operator-(const Vec2& vector) const{
	return Vec2(x - vector.x, vector.y - y);
}

template<class T>
Vec2<T> Vec2<T>::operator+(const Vec2& vector) const{
	return Vec2<T>(vector.x + x, vector.y + y);
}

template<class T>
float Vec2<T>::magnitude() const{
	return sqrt(x*x + y*y);
}

template<class T>
Vec2<T> Vec2<T>::normalVec() const{
	double mag = magnitude();
	return Vec2<T>(x/mag, y/mag);
}

template<class T>
float Vec2<T>::distance(const Vec2& vector) const{
	return (*this-vector).magnitude();
}

template<class T>
float Vec2<T>::angle() const{
	return atan(y / x) + (x < 0 ? PI : 0);
}

template<class T>
void Vec2<T>::rotate(int ang){
	double rad = ang*PI/180;

    float newX = cos(rad) * x - sin(rad) * y;
    float newY = sin(rad) * x + cos(rad) * y;

    x = newX;
    y = newY;
}

#endif