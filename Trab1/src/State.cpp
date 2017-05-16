#include "../include/State.hpp"

State::State() : varQuitRequested(false), bg("img/ocean.jpg"){}

bool State::quitRequested(){
	return varQuitRequested;
}

void State::requestQuit(){
	varQuitRequested = true;
}

void State::loadAssets(){

}

void State::update(double dt){

}

void State::render(){
	// bg.render(0,0);
}