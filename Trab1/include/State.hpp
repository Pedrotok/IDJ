#ifndef STATE_H_
#define STATE_H_

#include "Sprite.hpp"

class State{
	Sprite bg;
	bool varQuitRequested;

	public:
	State();

	// ~State();

	bool quitRequested();
	void requestQuit();

	void loadAssets();
	void update(double dt);
	void render();
};

#endif