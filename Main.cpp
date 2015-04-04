#include "Game.hpp"
#include "MainMenuState.hpp"


const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;


int main (int argc, char* argv[])
{
	CGame Game;
	Uint32 frameStart;
    Uint32 frameTime;

	Game.Init();

	// load the intro
	Game.ChangeState( CMainMenuState::Instance() );

	// main loop
	while ( Game.Running() )
	{
	    frameStart = SDL_GetTicks();

		Game.HandleEvents();
		Game.Update();
		Game.Render();

		frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        }
	}

	// cleanup the engine
	Game.Cleanup();

	return 0;
}
