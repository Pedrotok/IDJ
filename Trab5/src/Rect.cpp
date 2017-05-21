#include "../include/Rect.hpp"

Rect::Rect(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h){}

void Rect::displace(Vec2<float> vector){
	x += vector.x;
	y += vector.y;
}

Vec2<float> Rect::center(){
	return Vec2<float>(x + w/2, y + h/2);
}

float Rect::distanceRect(Rect rectangle){
	Vec2<float> my_center = center();
	Vec2<float> other_center = rectangle.center();
	return my_center.distance(other_center);
}

bool Rect::isInside(float _x, float _y){
	return _x >= x && _x <= x+w && _y >= y && _y <= y+h;
}
