#include "../../include/UI/window.h"

Window::Window()
{
	//Initialize non-existant window
	mWindow = NULL;
	mRenderer = NULL;

	mMouseFocus = false;
	mKeyboardFocus = false;
	mFullScreen = false;
	mShown = false;
	mWindowID = -1;
	mWidth = 0;
	mHeight = 0;
}

SDL_Window* Window::init()
{
   //Create window
   	mWindow = SDL_CreateWindow("General Settings", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

   	if (mWindow != NULL) {

   		mMouseFocus = false;
   		mKeyboardFocus = false;
   		mWidth = SCREEN_WIDTH;
   		mHeight = SCREEN_HEIGHT;

   		//Create renderer for window
   		mRenderer = SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED );
   		if (mRenderer == NULL) {
   			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
   			SDL_DestroyWindow( mWindow );
   			mWindow = NULL;
   		}
   		else {
   			//Initialize renderer color
   			SDL_SetRenderDrawColor( mRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

   			//Grab window identifier
   			mWindowID = SDL_GetWindowID( mWindow );
   			//Flag as opened
   			mShown = true;
            SDL_SetWindowPosition(mWindow, 85,110);

   		}
   	}
   	else {
   		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
   	}

   	return mWindow;
}

int Window:: LWLeftClick(SDL_MouseButtonEvent& b) {
    if(b.button == SDL_BUTTON_LEFT){
        int posX;
        int posY;
        SDL_GetMouseState(&posX, &posY);

        for (int i = 0; i < (int) LWButtons.size(); i++) {
            int temp = LWButtons[i]->ProcessClick(posX, posY, LWButtons[i]->getID());
            if (temp!=-1)
            {
                return temp;
            }
        }

        for (int i = 0; i < (int) LWToggleButtons.size(); i++) {
            int temp = LWToggleButtons[i]->ProcessClick(posX, posY);
            if (temp!=-1)
            {
                return temp;
            }
        }
    }
    return -1;
}

int Window::handleButtonClick(SDL_Event& e)
{
    if (e.type == SDL_MOUSEBUTTONDOWN && e.window.windowID == mWindowID) {
        return LWLeftClick(e.button);
    }
    return -1;
}

void Window::handleEvent( SDL_Event& e )
{
	//If an event was detected for this window

	if( e.type == SDL_WINDOWEVENT && e.window.windowID == mWindowID )
	{
		//Caption update flag
		bool updateCaption = false;

		switch( e.window.event )
		{

			//Window appeared
			case SDL_WINDOWEVENT_SHOWN:
			mShown = true;
			break;

			//Window disappeared
			case SDL_WINDOWEVENT_HIDDEN:
			mShown = false;
			break;

			//Get new dimensions and repaint
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			mWidth = e.window.data1;
			mHeight = e.window.data2;
			SDL_RenderPresent( mRenderer );
			break;

			//Repaint on expose
			case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent( mRenderer );
			break;

			//Mouse enter
			case SDL_WINDOWEVENT_ENTER:
			mMouseFocus = true;
			updateCaption = true;
			break;

			//Mouse exit
			case SDL_WINDOWEVENT_LEAVE:
			mMouseFocus = false;
			updateCaption = true;
			break;

			//Keyboard focus gained
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			mKeyboardFocus = true;
			updateCaption = true;
			break;

			//Keyboard focus lost
			case SDL_WINDOWEVENT_FOCUS_LOST:
			mKeyboardFocus = false;
			updateCaption = true;
			break;

			//Window minimized
			case SDL_WINDOWEVENT_MINIMIZED:
            mMinimized = true;
            break;

			//Window maxized
			case SDL_WINDOWEVENT_MAXIMIZED:
			mMinimized = false;
            break;

			//Window restored
			case SDL_WINDOWEVENT_RESTORED:
			mMinimized = false;
            break;

			//Hide on close
			case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow( mWindow );
			break;
		}

		//Update window caption with new data
		if( updateCaption )
		{
			std::stringstream caption;
			caption << "Physics Engine - ID: " << mWindowID << " MouseFocus:" << ( ( mMouseFocus ) ? "On" : "Off" ) << " KeyboardFocus:" << ( ( mKeyboardFocus ) ? "On" : "Off" );
			SDL_SetWindowTitle( mWindow, caption.str().c_str() );
		}
	}
}

void Window::LWUIHandler(TTF_Font* font) {
    SDL_Color White = {255, 255, 255};
    int posX;
    int posY;
    SDL_GetMouseState(&posX, &posY);

    for (int i = 0; i < (int) LWButtons.size(); i++) {
      LWButtons[i]->Update(mRenderer, posX, posY, White, font, mWindow);
    }

    for (int i = 0; i < (int) LWToggleButtons.size(); i++) {
      LWToggleButtons[i]->Update(mRenderer, posX, posY, White, font, mWindow);
    }

}
void Window::focus()
{
	//Restore window if needed
	if( !mShown )
	{
		SDL_ShowWindow( mWindow );
	}

	//Move window forward
	SDL_RaiseWindow( mWindow );
}

void Window::LWFillScreen()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

void Window::LWRenderPresent()
{
    SDL_RenderPresent( mRenderer );
}


void Window::free()
{
	if( mWindow != NULL )
	{
		SDL_DestroyWindow( mWindow );
	}

	mMouseFocus = false;
	mKeyboardFocus = false;
	mWidth = 0;
	mHeight = 0;
}

int Window::getWidth()
{
	return mWidth;
}

int Window::getHeight()
{
	return mHeight;
}

bool Window::hasMouseFocus()
{
	return mMouseFocus;
}

bool Window::hasKeyboardFocus()
{
	return mKeyboardFocus;
}

bool Window::isMinimized()
{
	return mMinimized;
}

bool Window::isShown()
{
	return mShown;
}

SDL_Renderer* Window::getRenderer()
{
    return mRenderer;
}
SDL_Window* Window::getWindow() { 
    return mWindow;
}
