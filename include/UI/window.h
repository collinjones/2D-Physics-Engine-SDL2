#ifndef _WINDOW_
#define _WINDOW_

//https://lazyfoo.net/tutorials/SDL/36_multiple_windows/index.php

//Using SDL, standard IO, strings, and string streams
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include "togglebutton.h"
#include "panel.h"
#include "slider.h"
#include "button.h"

//Screen dimension constants
const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

class Window
{
	public:
		//Intializes internals
		Window();

		//Creates window
		//1 for grav, 2 for circle, 3 for line, 4 for rect
        SDL_Window* init();
		//Handles window events
		void handleEvent( SDL_Event& e );

		//Focuses on window
		void focus();

		//Shows windows contents
		void render();

		//Deallocates internals
		void free();

		//Window dimensions
		int getWidth();
		int getHeight();

		//Window focii
		bool hasMouseFocus();
		bool hasKeyboardFocus();
		bool isMinimized();
		bool isShown();

        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();
        void LWUIHandler(TTF_Font* font);
        void LWRenderPresent();
        void LWFillScreen();
        int LWLeftClick(SDL_MouseButtonEvent& b);
        int handleButtonClick(SDL_Event& e);
	private:
		//Window data
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;
		unsigned int mWindowID; //made unsigned
		//Window dimensions
		int mWidth;
		int mHeight;

		//Window focus
		bool mMouseFocus;
		bool mKeyboardFocus;
		bool mFullScreen;
		bool mMinimized;
		bool mShown;

		vector<Button*> LWButtons;
		vector<ToggleButton*> LWToggleButtons;
        vector<DisplayPanel*> LWDisplays;
        vector<Slider*> LWSliders;
};

#endif
