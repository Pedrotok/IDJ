#include "../include/Minion.hpp"
#include "../include/Camera.hpp"
#include "../include/Bullet.hpp"
#include "../include/State.hpp"
#include <math.h>

Minion::Minion(GameObject* minionCenter, float arcOffset) :
	center(minionCenter),
	sp("img/minion.png"),
	arc(arcOffset*PI/180.0)
{
	sp.setScaleX( (rand()%6 + 10.0)/10.0);
	sp.setScaleY( (rand()%6 + 10.0)/10.0);
	
	rotation = arcOffset;
	
	box.x = center->box.center().x + cos(arc)*center->box.w - box.w/2.0;
	box.y = center->box.center().y + sin(arc)*center->box.w - box.h/2.0;
	box.w = sp.getWidth();
	box.h = sp.getHeight();
}

void Minion::update(float dt){
	arc += dt*PI/5;
	if(arc >= 2*PI) arc -= 2*PI;

	rotation = arc*180.0/PI;

	box.x = center->box.center().x + cos(arc)*center->box.w - box.w/2.0;
	box.y = center->box.center().y + sin(arc)*center->box.w - box.h/2.0;
}

void Minion::render(){
	sp.render(box.x - Camera::pos.x, box.y - Camera::pos.y, rotation);
}

bool Minion::isDead(){
	return false;
}

void Minion::shoot(Vec2<float> pos){
	float maxDistance = pos.distance(Vec2<float>(box.x + box.w/2.0, box.y + box.h/2.0));
	float angle = atan2(pos.y - box.y - box.h/2.0, pos.x - box.x - box.w/2.0)*180/PI;

	Bullet* bullet = new Bullet(box.x + box.w/2.0, box.y + box.h/2.0, angle, 200, maxDistance, "img/minionbullet1.png");

	State& state = State::getInstance();
	state.addObject(bullet);
}