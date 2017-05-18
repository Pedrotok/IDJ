#include "../include/State.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"

State::State(std::string tsFile, std::string tmName) :
    varQuitRequested(false),
    bg("img/ocean.jpg"),
    tileSet(64,64,tsFile),
    tileMap(tmName, &tileSet){ }

bool State::quitRequested() {
	return varQuitRequested;
}

void State::requestQuit(){
	varQuitRequested = true;
}

void State::loadAssets(){

}

void State::update(double dt){
    InputManager& IMInstance = InputManager::getInstance();

    // se ESC foi pressionado ou quitRequested
    if(IMInstance.keyPress(ESCAPE_KEY) || IMInstance.quitRequested()){
        varQuitRequested = true;
    }

    if(IMInstance.keyPress(' ')){
        addObject(IMInstance.getMouseX() + Camera::pos.x, IMInstance.getMouseY() + Camera::pos.y);
    }

    for(int i = (int)objectArray.size() - 1; i >= 0; --i) {
        objectArray[i]->update(dt);
    }

	for(int i = 0; i < (int)objectArray.size(); i++){
		if(objectArray[i]->isDead())
			objectArray.erase(objectArray.begin() + i);
	}
}

void State::render(){
    bg.render(0,0);

    tileMap.renderLayer(0);

    for(int i = 0; i < (int)objectArray.size(); i++){
        objectArray[i]->render();
    }

	tileMap.renderLayer(1);
}

State::~State(){
	objectArray.clear();
}

void State::addObject(float mouseX, float mouseY){
	double ang = rand()%360*acos(-1)/180;
	float newX = cos(ang)*200 + mouseX;
	float newY = sin(ang)*200 + mouseY;
	objectArray.emplace_back(new Face(newX, newY));
}