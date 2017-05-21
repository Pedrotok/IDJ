#ifndef BULLET_H_
#define BULLET_H_

#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Vec2.hpp"
#include <string>

class Bullet : public GameObject{
	Sprite sp;
	Vec2<float> speed;
	float distanceLeft;

	public:
		Bullet(float x, float y, float angle, float _speed, float maxDistance, std::string file);
		void update(float dt);
		void render();
		bool isDead();
};

#endif