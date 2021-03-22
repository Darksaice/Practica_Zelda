#ifndef RENDERER_H
#define RENDERER_H

#include "includes.h"
#include <SFML/Graphics.hpp>

class Renderer {

public:
	Renderer();
	~Renderer();

	//! Inits the screen
	void initWindow();

	//! Clean Window
	void windowClear();
	
	//! Performs Screen Draw (screen flip)
	void windowRefresh();

	//! Return true if window exists
	bool windowIsOpen();

	//! Rectabgle shape draw
	void drawRectangle(C_Rectangle rect, Color col, bool outline = false);

	//!Sprite draw
	void drawSprite(int ID, int posX, int posY, C_Rectangle rect);

	//! Returns the window pointer
	sf::RenderWindow* getWindow() { return mWindow; };

	//! Limit Framerate
	void setFramerate(int framerate);

	//! This Class is Singleton
	static Renderer* getInstance();

private:
	static Renderer* instance;

	sf::RenderWindow*	mWindow;
	int					mWindowWidth;
	int					mWindowHeight;

};



#endif
