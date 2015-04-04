#include "Game.hpp"
#include "GameState.hpp"

CGame::CGame()
{
    Screen_Width = 640;
    Screen_Height = 480;
}


void CGame::Init()
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized!\n";
    }
    MainWindow = SDL_CreateWindow ("Super Mario: Time Trip",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Screen_Width,Screen_Height,SDL_WINDOW_RESIZABLE);
    if (MainWindow == NULL)
    {
        std::cout << "SDL could not create the window! SDL_Error: " << SDL_GetError () << "\n";
    }
    else
    {
        MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
        if (MainRenderer == NULL)
        {
            std::cout << "SDL could not create the renderer! SDL_Error: " << SDL_GetError() << "\n";
        }
        else
        {
            MainWindowSurface = SDL_GetWindowSurface(MainWindow);
            if (MainWindowSurface == NULL)
            {
                std::cout << "SDL could not get the window surface! SDL_Error: " << SDL_GetError() << "\n";
            }
            else
            {
                MainIcon = IMG_Load("data/icons/Mario Block.png");
                if (MainIcon == NULL)
                {
                    std::cout << "Failed to load the main icon! IMG_Error: " << IMG_GetError() << "\n";
                }
                else
                {
                    SDL_SetWindowIcon(MainWindow,MainIcon);
                }
            }
        }
    }
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not be initialized!\n";
    }
    if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) == -1)
    {
        std::cout << "SDL_mixer could not be initialized!\n";
    }

	m_running = true;

	std::cout << "CGameEngine Init\n";
}

void CGame::Cleanup()
{
	while ( !StateList.empty() )
    {
		StateList.back()->Cleanup();
		StateList.pop_back();
	}

	std::cout << "CGameEngine Cleanup\n";

	SDL_DestroyWindow(MainWindow);

	TTF_Quit();
	SDL_Quit();
}

void CGame::ChangeState(CGameState* state)
{
	if ( !StateList.empty() )
    {
		StateList.back()->Cleanup();
		StateList.pop_back();
	}

	StateList.push_back(state);
	StateList.back()->Init(MainRenderer);
}

void CGame::PushState(CGameState* state)
{
	// pause current state
	if ( !StateList.empty() )
    {
		StateList.back()->Pause();
	}

	// store and init the new state
	StateList.push_back(state);
	StateList.back()->Init(MainRenderer);
}

void CGame::PopState()
{
	// cleanup the current state
	if ( !StateList.empty() )
    {
		StateList.back()->Cleanup();
		StateList.pop_back();
	}

	// resume previous state
	if ( !StateList.empty() )
    {
		StateList.back()->Resume();
	}
}


void CGame::HandleEvents()
{
	// let the state handle events
	StateList.back()->HandleEvents(this);
}

void CGame::Update()
{
	// let the state update the game
	StateList.back()->Update(this);
}

void CGame::Render()
{
	// let the state draw the screen
	StateList.back()->Render(this);
}
