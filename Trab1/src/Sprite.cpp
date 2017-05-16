#include "../include/Sprite.hpp"
#include "../include/Game.hpp"

Sprite::Sprite(){
	texture = NULL;
}

Sprite::Sprite(std::string file){
	texture = NULL;
	open(file);
}

Sprite::~Sprite(){
	if(texture != NULL)
		SDL_DestroyTexture(texture);
}

void Sprite::open(std::string file){
	if(texture != NULL)
		texture = NULL;

	SDL_Renderer* renderer = Game::getInstance()->getRenderer();

	texture = IMG_LoadTexture(renderer, file.c_str());

	if(texture == NULL){
		printf("IMG_LoadTexture ERROR: %s\n", SDL_GetError());
	}

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	setClip(0,0,width,height);

	render(0,0);
}

void Sprite::setClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::render(int x, int y){
	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = width;
	dstrect.h = height;

	SDL_Renderer* renderer = Game::getInstance()->getRenderer();

	SDL_RenderCopy(renderer, texture, &clipRect, &dstrect);
}

int Sprite::getWidth(){
	return width;
}

int Sprite::getHeight(){
	return height;
}

bool Sprite::isOpen(){
	return texture != NULL;
}