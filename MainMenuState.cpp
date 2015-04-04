#include "Game.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "ExplanationState.hpp"
#include "OptionsState.hpp"

CMainMenuState CMainMenuState::m_CMainMenuState;

void CMainMenuState::Init(SDL_Renderer* pRenderer)
{
	std::cout << "CMainMenuState Init\n";

	Background = BackgroundSprite.Load(pRenderer,"data/imgs/states/MainMenuState/MainMenu - Final.png",255,0,255);
	Mario = MarioSprite.Load(pRenderer,"data/imgs/player/Mario.png",255,0,255);

	PlayButton = new CButton(75,350,false);
	PlayButton->Load(pRenderer,"data/imgs/buttons/Play.png");

	OptionsButton = new CButton(235,350,false);
	OptionsButton->Load(pRenderer,"data/imgs/buttons/Options.png");

	QuitButton = new CButton (439,350,false);
	QuitButton->Load(pRenderer,"data/imgs/buttons/Quit.png");
}

void CMainMenuState::Cleanup()
{
    SDL_DestroyTexture(Background);

    PlayButton->CleanUp();
    delete PlayButton;

    OptionsButton->CleanUp();
    delete OptionsButton;

    QuitButton->CleanUp();
    delete QuitButton;

	std::cout << "CMainMenuState Cleanup\n";
}

void CMainMenuState::Pause()
{
	std::cout << "CMainMenuState Pause\n";
}

void CMainMenuState::Resume()
{
	std::cout << "CMainMenuState Resume\n";
}

void CMainMenuState::HandleEvents(CGame* game)
{
	if (PlayButton->IsClicked() == true)
    {
        game->ChangeState(CExplanationState::Instance());
    }
    else if (OptionsButton->IsClicked() == true)
    {
        game->ChangeState(COptionsState::Instance());
    }
    else if (QuitButton->IsClicked() == true)
    {
        game->Quit();
    }

    SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;
		}
	}
}

void CMainMenuState::Update(CGame* game)
{
    BackgroundSprite.SetSourceRect(0,0,640,480);
    MarioSprite.SetSourceRect(0,0,28,32);

    PlayButton->Update();
    OptionsButton->Update();
    QuitButton->Update();
}

void CMainMenuState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,0,0,0);
    SDL_RenderClear(game->MainRenderer);

    BackgroundSprite.SetDestinationRect(0,0,640,480);
    BackgroundSprite.Render(game->MainRenderer);
    MarioSprite.SetDestinationRect(15,384,28,32);
    MarioSprite.Render(game->MainRenderer);
	PlayButton->Render(game->MainRenderer);
	OptionsButton->Render(game->MainRenderer);
	QuitButton->Render(game->MainRenderer);
	SDL_RenderPresent(game->MainRenderer);
}



