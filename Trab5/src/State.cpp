#include "../include/State.hpp"
#include "../include/InputManager.hpp"
#include "../include/Camera.hpp"
#include "../include/Alien.hpp"

State* State::instance = NULL;

State::State(std::string tsFile, std::string tmName) :
    varQuitRequested(false),
    bg("img/ocean.jpg"),
    tileSet(64,64,tsFile),
    tileMap(tmName, &tileSet){
        instance = this;
        objectArray.emplace_back(new Alien(512,300,3,230));
    }

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

    tileMap.renderLayer(0,Camera::pos.x, Camera::pos.y);

    for(int i = 0; i < (int)objectArray.size(); i++){
        objectArray[i]->render();
    }

	tileMap.renderLayer(1,Camera::pos.x*2.0, Camera::pos.y*2.0);
}

State::~State(){
	objectArray.clear();
}

void State::addObject(GameObject* ptr){
    objectArray.emplace_back(ptr);
}

State& State::getInstance(){
    return *instance;
}