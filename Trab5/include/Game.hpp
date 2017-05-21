#ifndef GAME_H_
#define GAME_H_

#include "State.hpp"
#include <stdlib.h>
#include <time.h>

class Game{
	std::string title;
	int width, height;
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;

	public:
		Game(std::string _title, int _width, int _height);
		~Game();
		void run();
		SDL_Renderer* getRenderer();
		static Game& getInstance();
		
		State& getState();
		int getWidth() const; 
		int getHeight() const;
};

#endif