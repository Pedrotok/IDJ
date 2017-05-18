#include "../include/Face.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"

float max(float a, float b){
	return a > b ? a : b;
}

Face::Face(float x, float y) : hitPoints(30), sp("img/penguinface.png"){
	box = Rect(x, y, sp.getWidth(), sp.getHeight());

	box.x -= box.w/2;
	box.y -= box.h/2;
}

void Face::damage(int varDamage){
	hitPoints -= varDamage;
}

void Face::update(float dt){
	InputManager& IMInstance = InputManager::getInstance();
	
	if(box.isInside(IMInstance.getMouseX() - Camera::pos.x, IMInstance.getMouseY() - Camera::pos.y)){
		for(int i = 1; i <= 5; i++)
			if(IMInstance.mousePress(i))
				damage(rand()%10 + 10);
	}
}

void Face::render(){
	sp.render((int)box.x - Camera::pos.x, (int)box.y - Camera::pos.y);
}

bool Face::isDead(){
	return hitPoints <= 0;
}

Face::~Face(){}
