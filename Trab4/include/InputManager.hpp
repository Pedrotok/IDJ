#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "Sprite.hpp"
#include "TileSet.hpp"
#include <string>
#include <vector>

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager{
	bool mouseState[6];
	int mouseUpdate[6];
	bool keyState[416];
	int keyUpdate[416];
	int mouseX, mouseY;
	int updateCounter;
	bool varQuitRequested;

	InputManager();
	~InputManager();

	public:
		void update();
		bool keyPress(const int key) const;
		bool keyRelease(const int key) const;
		bool isKeyDown(const int key) const;

		bool mousePress(const int button) const;
		bool mouseRelease(const int button) const;
		bool isMouseDown(const int button) const;

		int getMouseX() const;
		int getMouseY() const;

		bool quitRequested() const;

		static InputManager& getInstance();
};

#endif