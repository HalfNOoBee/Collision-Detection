#include "Game.hpp"
#include "GameState.hpp"
#include "PauseMenuState.hpp"
#include "MainMenuState.hpp"


CPauseMenuState CPauseMenuState::m_PauseMenuState;

void CPauseMenuState::Init(SDL_Renderer* pRenderer)
{

	std::cout << "CPauseMenuState Init\n";

	ContinueButton = new CButton(100,100,true);
	ContinueButton->Load(pRenderer,"data/imgs/buttons/Continue.png");

	QuitButton = new CButton(100,200,true);
	QuitButton->Load(pRenderer,"data/imgs/buttons/Quit.png");
}

void CPauseMenuState::Cleanup()
{
	delete ContinueButton;
	delete QuitButton;

	std::cout << "CPauseMenuState Cleanup\n";
}

void CPauseMenuState::Pause()
{
	std::cout << "CPauseMenuState Pause\n";
}

void CPauseMenuState::Resume()
{
	std::cout << "CPauseMenuState Resume\n";
}

void CPauseMenuState::HandleEvents(CGame* game)
{
	SDL_Event event;

	if (ContinueButton->IsClicked() == true)
    {
        std::cout << "Continueing...\n";
        game->PopState();
    }
    else if (QuitButton->IsClicked() == true)
    {
        std::cout << "Quitting...\n";
        game->Quit();
    }

	if (SDL_PollEvent(&event))
    {
		switch (event.type)
		{
			case SDL_QUIT:
				game->Quit();
				break;

		}
	}
}

void CPauseMenuState::Update(CGame* game)
{
    ContinueButton->Update();
    QuitButton->Update();
}

void CPauseMenuState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,0,0,0);
    SDL_RenderClear(game->MainRenderer);

	ContinueButton->Render(game->MainRenderer);
	QuitButton->Render(game->MainRenderer);
	SDL_RenderPresent(game->MainRenderer);
}
