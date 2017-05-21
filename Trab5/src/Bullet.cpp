#include "../include/Bullet.hpp"
#include "../include/Camera.hpp"
#include <math.h>

Bullet::Bullet(float x, float y, float angle, float _speed, float maxDistance, std::string file) : 
	distanceLeft(maxDistance),
	sp(file)
{
	box = Rect(x, y, sp.getWidth(), sp.getHeight());
	box.x -= box.w/2;
	box.y -= box.h/2;

	double rad = angle*PI/180;
	speed.x = _speed*cos(rad);
	speed.y = _speed*sin(rad);
}

void Bullet::update(float dt){
	float totalDistance = sqrt(speed.x*speed.x + speed.y*speed.y)*dt;
	if(totalDistance > distanceLeft){
		Vec2<float> tmp = speed.normalVec();
		tmp *= distanceLeft;
		box.x += distanceLeft;
		box.y += distanceLeft;
		distanceLeft = 0;
	}
	else{
		box.x += speed.x*dt;
		box.y += speed.y*dt;
		distanceLeft -= totalDistance;
	}
}

void Bullet::render(){
	sp.render(box.x - Camera::pos.x, box.y - Camera::pos.y);
}

bool Bullet::isDead(){
	return distanceLeft <= 0;
}
