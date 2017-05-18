#include "../include/Game.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"

Game* Game::instance = NULL;

static unsigned int fixed_step = 30;

Game::Game(std::string _title, int _width, int _height){
	if(instance != NULL) return ; // tratar erro
	instance = this;

	srand(time(NULL));

	title = _title;
	width = _width;
	height = _height;

	// inicia SDL
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) ){
		//tratar erro
		printf("SDL INIT ERROR: %s\n", SDL_GetError());
	}

	//inicia carregadores de imagem
	if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0){
		// carregou nada
		printf("carregou nada\n");
	}

	// cria janela n centro da tela com width e height determinados
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if(window == NULL){
		printf("SDL CREATE WINDOW ERROR: %s\n", SDL_GetError());
	}
	// cria renderizador (vsync on)
	renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );

	if(renderer == NULL){
		printf("SDL CREATE RENDERER ERROR: %s\n", SDL_GetError());
	}

	state = new State("img/tileset.png", "map/tileMap.txt");
}

Game::~Game(){
	delete(state);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
}

SDL_Renderer* Game::getRenderer(){
	return renderer;
}

Game& Game::getInstance(){
	return *instance;
}

State& Game::getState(){
	return *state;
}


void Game::run(){
	while(state->quitRequested() == false){
		static unsigned int current_time = 0;

		if(current_time == 0){
			current_time = SDL_GetTicks();
			continue;
		}

		static unsigned int time_buffer = 0;

		unsigned int new_time = SDL_GetTicks();
		unsigned int dt = new_time - current_time;
		time_buffer += dt;
		current_time = new_time;

		while(time_buffer >= fixed_step){
			time_buffer -= fixed_step;
			Camera::update(dt);
			InputManager::getInstance().update();
			state->update(dt/1000.0f);
		}

		state->render();
		SDL_RenderPresent(renderer);

		SDL_Delay(33);
	}
}

int Game::getWidth() const{
	return width;
}

int Game::getHeight() const{
	return height;
}
