#ifndef ALIEN_H_
#define ALIEN_H_

#include "Sprite.hpp"
#include "Vec2.hpp"
#include "Minion.hpp"
#include "GameObject.hpp"
#include <queue>
#include <vector>

class Action;

class Alien : public GameObject{
	Sprite sp;
	Vec2<float> pos;
	int speed, hp;

	std::queue<Action> taskQueue;
	std::vector<Minion*> minionArray;

	public:
		Alien(float x, float y, int nMinions, int speed);
		~Alien();

		void update(float dt);
		void render();
		bool isDead();
};

class Action{
	public:
		enum ActionType{MOVE, SHOOT};
		
		ActionType type;
		Vec2<float> pos;

		Action(ActionType _type, float _x, float _y);
		

};

#endif