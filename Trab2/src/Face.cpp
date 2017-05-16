#include "../include/Face.hpp"

float max(float a, float b){
	return a > b ? a : b;
}

Face::Face(float x, float y) : hitPoints(30), sp("img/penguinface.png"){
	box = Rect(x, y, sp.getWidth(), sp.getHeight());

	box.x -= box.w/2;
	box.y -= box.h/2;

	box.x = max(box.x, 0);
	box.y = max(box.y, 0);
}

void Face::damage(int varDamage){
	hitPoints -= varDamage;
}

void Face::update(float dt){

}

void Face::render(){
	sp.render((int)box.x, (int)box.y);
}

bool Face::isDead(){
	return hitPoints <= 0;
}

Face::~Face(){}
