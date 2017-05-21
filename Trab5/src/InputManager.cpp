#include "../include/InputManager.hpp"

InputManager::InputManager(){
	memset(mouseState, 0, sizeof mouseState);
	memset(mouseUpdate, 0, sizeof mouseUpdate);
	memset(keyState, 0, sizeof keyState);
	memset(keyUpdate, 0, sizeof keyUpdate);

	updateCounter = 0;
	varQuitRequested = false;
}

InputManager::~InputManager(){}

int convertKey(const int key){
	if(key <= 0x7F)
		return key;
	return key - 0x3FFFFF81;
}

void InputManager::update(){
	SDL_Event event;

	updateCounter++;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (varQuitRequested == false && SDL_PollEvent(&event)) {
    	if(event.key.repeat) continue;
        switch(event.type){
	    	case SDL_QUIT: // se o event for quit
	            {
	            	varQuitRequested = true;
	            	break;
	            }

	        case SDL_KEYDOWN: // tecla pressionada
	        	{
	        		int idKey = convertKey(event.key.keysym.sym);
	        		keyState[idKey] = true;
	        		keyUpdate[idKey] = updateCounter;
	        		break;
	        	}

	        case SDL_KEYUP: // tecla despressionada
	        	{
	        		int idKey = convertKey(event.key.keysym.sym);
	        		keyState[idKey] = false;
	        		keyUpdate[idKey] = updateCounter;
	        		break;
	        	}

	        case SDL_MOUSEBUTTONDOWN: // clique
	        	{
	        		int idButton = event.button.button;
	        		mouseState[idButton] = true;
	        		mouseUpdate[idButton] = updateCounter;
	        		break;
	        	}

	        case SDL_MOUSEBUTTONUP: // soltar clique
	        	{
	        		int idButton = event.button.button;
	        		mouseState[idButton] = false;
	        		mouseUpdate[idButton] = updateCounter;
	        		break;
	        	}
	   	}

        
    }
}

bool InputManager::keyPress(const int key) const{
	int newKey = convertKey(key);
	return (keyState[newKey] && updateCounter - keyUpdate[newKey] == 0);
}

bool InputManager::keyRelease(const int key) const{
int newKey = convertKey(key);
	return (!keyState[newKey] && updateCounter - keyUpdate[newKey] == 0);
}

bool InputManager::isKeyDown(const int key) const{
	int newKey = convertKey(key);
	return keyState[newKey];
}


bool InputManager::mousePress(const int button) const{
	return (mouseState[button] && updateCounter - mouseUpdate[button] == 0);
}

bool InputManager::mouseRelease(const int button) const{
return (!mouseState[button] && updateCounter - mouseUpdate[button] == 0);
}

bool InputManager::isMouseDown(const int button) const{
	return mouseState[button];
}


int InputManager::getMouseX() const{
	return mouseX;
}

int InputManager::getMouseY() const{
	return mouseY;
}

int InputManager::getUpdateCounter() const{
	return updateCounter;
}

bool InputManager::quitRequested() const{
	return varQuitRequested;
}

InputManager& InputManager::getInstance(){
	static InputManager instance;
	return instance;
}
