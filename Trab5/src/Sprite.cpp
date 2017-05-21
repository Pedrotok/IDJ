#include "../include/Sprite.hpp"
#include "../include/Game.hpp"

Sprite::Sprite(){
	texture = NULL;
}

Sprite::Sprite(std::string file){
	texture = NULL;
	scaleX = scaleY = 1;
	open(file);
}

Sprite::~Sprite(){
	if(texture != NULL)
		SDL_DestroyTexture(texture);
}

void Sprite::open(std::string file){
	if(texture != NULL){
		SDL_DestroyTexture(texture);
		texture = NULL;
	}

	SDL_Renderer* renderer = Game::getInstance().getRenderer();

	texture = IMG_LoadTexture(renderer, file.c_str());

	if(texture == NULL){
		printf("IMG_LoadTexture ERROR: %s\n", SDL_GetError());
	}

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	setClip(0,0,width,height);
}

void Sprite::setClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::render(int x, int y, float angle){
	SDL_Rect dstrect = {x, y, clipRect.w*scaleX, clipRect.h*scaleY};

	SDL_Renderer* renderer = Game::getInstance().getRenderer();

	SDL_RenderCopyEx(renderer, texture, &clipRect, &dstrect, angle, NULL, SDL_FLIP_NONE);
}

int Sprite::getWidth(){
	return width*scaleX;
}

int Sprite::getHeight(){
	return height*scaleY;
}

bool Sprite::isOpen(){
	return texture != NULL;
}

void Sprite::setScaleX(float scale){
	scaleX = scale;
}

void Sprite::setScaleY(float scale){
	scaleY = scale;
}
