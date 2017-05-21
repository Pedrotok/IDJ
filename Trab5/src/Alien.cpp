#include "../include/Alien.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"

Alien::Alien(float x, float y, int nMinions, int _speed) : 
	sp("img/alien.png"),
	speed(_speed),
	hp(100)
{
	box = Rect(x, y, sp.getWidth(), sp.getHeight());

	box.x -= box.w/2;
	box.y -= box.h/2;

	float angle = 360.0/nMinions;

	for(int i = 0; i < nMinions; i++){
		minionArray.emplace_back(new Minion(this, angle*i));
	}
}

Alien::~Alien(){
	minionArray.clear();
}

void Alien::update(float dt){
	rotation--;
	if(rotation < 0) rotation += 360;

	InputManager& IMInstance = InputManager::getInstance();

	if(IMInstance.mousePress(LEFT_MOUSE_BUTTON)){
		taskQueue.push(Action(Action::SHOOT, IMInstance.getMouseX()+Camera::pos.x, IMInstance.getMouseY()+Camera::pos.y));
	}

	if(IMInstance.mousePress(RIGHT_MOUSE_BUTTON)){
		taskQueue.push(Action(Action::MOVE, IMInstance.getMouseX()+Camera::pos.x-box.w/2, IMInstance.getMouseY()+Camera::pos.y-box.h/2));
	}

	if(!taskQueue.empty()){
		Action frontAction = taskQueue.front();

		if(frontAction.type == Action::MOVE){
			float dist = frontAction.pos.distance(Vec2<float>(box.x, box.y));

			if(speed*dt > dist){
				box.x = frontAction.pos.x;
				box.y = frontAction.pos.y;
				taskQueue.pop();
			}
			else{
				Vec2<float> myPos = Vec2<float>(box.x, box.y);
				Vec2<float> vectorDiff = frontAction.pos - myPos;
				vectorDiff = vectorDiff.normalVec();
				vectorDiff *= (float)speed*dt;
				myPos += vectorDiff;
				
				box.x = myPos.x; box.y = myPos.y;
			}
		}
		else{
			taskQueue.pop();
			if(minionArray.size() != 0){
				int indMinion = 0;
				float closest = frontAction.pos.distance(Vec2<float>(minionArray[0]->box.x, minionArray[0]->box.y));
				
				for(unsigned i = 1; i < minionArray.size(); i++){
					float curDistance = frontAction.pos.distance(Vec2<float>(minionArray[i]->box.x, minionArray[i]->box.y));
					if(curDistance < closest){
						indMinion = i;
						closest = curDistance;
					}
				}

				minionArray[indMinion]->shoot(frontAction.pos);
			}
		}
	}

	for(unsigned i = 0; i < minionArray.size(); i++){
		minionArray[i]->update(dt);
	}
}

void Alien::render(){
	sp.render(box.x - Camera::pos.x, box.y - Camera::pos.y, rotation);

	for(unsigned i = 0; i < minionArray.size(); i++){
		minionArray[i]->render();
	}
}

bool Alien::isDead(){
	return (hp <= 0);
}

// -------- Action ---------

Action::Action(ActionType _type, float _x, float _y) :
	pos(_x,_y),
	type(_type){}