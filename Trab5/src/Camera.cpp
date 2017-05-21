#include "../include/Camera.hpp"
#include "../include/Game.hpp"
#include "../include/InputManager.hpp"

Vec2<float> Camera::pos(0,0);
Vec2<float> Camera::speed(0,0);
GameObject* Camera::focus(NULL);

void Camera::follow(GameObject* newFocus){
	focus = newFocus;
}

void Camera::unfollow(){
	focus = NULL;
}

void Camera::update(float dt){
	if(focus == NULL){
		InputManager& IMInstance = InputManager::getInstance();
		
		speed.x = 0; speed.y = 0;
		if(IMInstance.isKeyDown(LEFT_ARROW_KEY))
			speed.x--;
		if(IMInstance.isKeyDown(RIGHT_ARROW_KEY))
			speed.x++;
		if(IMInstance.isKeyDown(DOWN_ARROW_KEY))
			speed.y++;
		if(IMInstance.isKeyDown(UP_ARROW_KEY))
			speed.y--;
		
		pos.x += speed.x*dt;
		pos.y += speed.y*dt;
	}
	else{
		Game& GameInstance = Game::getInstance();
		pos.x = GameInstance.getWidth()/2.0;
		pos.y = GameInstance.getHeight()/2.0;
	}
}
