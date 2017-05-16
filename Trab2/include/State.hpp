#ifndef STATE_H_
#define STATE_H_

#include "Sprite.hpp"
#include <memory>
#include <vector>
#include "Face.hpp"

class State{
	Sprite bg;
	bool varQuitRequested;
	std::vector<std::unique_ptr<GameObject>> objectArray;

	void input();
	void addObject(float mouseX, float mouseY);

	public:
		State();

		~State();

		bool quitRequested();
		void requestQuit();

		void loadAssets();
		void update(double dt);
		void render();
};

#endif