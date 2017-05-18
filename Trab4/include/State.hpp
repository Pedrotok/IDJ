#ifndef STATE_H_
#define STATE_H_

#include "Sprite.hpp"
#include "Face.hpp"
#include "TileMap.hpp"
#include <memory>
#include <vector>
#include <string>

class State{
	Sprite bg;
	bool varQuitRequested;
	std::vector<std::unique_ptr<GameObject>> objectArray;

	TileSet tileSet;
	TileMap tileMap;

	// void input();
	void addObject(float mouseX, float mouseY);

	public:
		State(std::string tsFile, std::string tmFile);

		~State();

		bool quitRequested() ;
		void requestQuit();

		void loadAssets();
		void update(double dt);
		void render();
};

#endif