#ifndef MINION_H_
#define MINION_H_

#include "Sprite.hpp"
#include "GameObject.hpp"

class Minion : public GameObject{
	GameObject* center;
	Sprite sp;
	float arc;

	public:
		Minion(GameObject* minionCenter, float arcOffset = 0);
		void update(float dt);
		void render();
		bool isDead();
		void shoot(Vec2<float> pos);
};

#endif