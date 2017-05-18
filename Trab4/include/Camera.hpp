#ifndef CAMERA_H_
#define CAMERA_H_

#include "GameObject.hpp"
#include "Vec2.hpp"
#include <iostream>

class Camera{
	static GameObject* focus;

	public:
		static Vec2<float> pos, speed;

		static void follow(GameObject* newFocus);
		static void unfollow();
		static void update(float dt);
};

#endif