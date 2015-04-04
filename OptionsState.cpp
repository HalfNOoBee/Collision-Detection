#include "Game.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "OptionsState.hpp"


COptionsState COptionsState::m_OptionsState;

void COptionsState::Init(SDL_Renderer* pRenderer)
{
	std::cout << "CMenuState Init\n";

	Background = BackgroundSprite.Load(pRenderer,"data/imgs/states/OptionsState/Options - Final2.png",255,0,255);
    BackgroundSprite.SetSourceRect(0,0,640,480);

	BackButton = new CButton(100,350,false);
	BackButton->Load(pRenderer,"data/imgs/buttons/Back.png");

	SoundCheckBox = new CCheckBox(0,0,true);
	SoundCheckBox->Load(pRenderer);
}

void COptionsState::Cleanup()
{
    SDL_DestroyTexture(Background);

    BackButton->CleanUp();
	delete BackButton;

    SoundCheckBox->CleanUp();
	delete SoundCheckBox;

	std::cout << "COptionsState Cleanup\n";
}

void COptionsState::Pause()
{
	std::cout << "COptionsState Pause\n";
}

void COptionsState::Resume()
{
	std::cout << "COptionsState Resume\n";
}

void COptionsState::HandleEvents(CGame* game)
{
	SDL_Event event;

	if (BackButton->IsClicked() == true)
    {
        std::cout << "Back...\n";
        game->ChangeState(CMainMenuState::Instance());
    }

    if (SoundCheckBox->IsClicked() == true && SoundCheckBox->IsOff == true)
    {
        SoundCheckBox->IsOn = true;
        std::cout << "On...\n";
    }
    else if (SoundCheckBox->IsClicked() == true && SoundCheckBox->IsOn == true)
    {
        SoundCheckBox->IsOff = true;
        std::cout <<"Off...\n";
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

void COptionsState::Update(CGame* game)
{
    BackButton->Update();
    SoundCheckBox->Update();
}

void COptionsState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,0,0,0);
    SDL_RenderClear(game->MainRenderer);

    BackgroundSprite.SetDestinationRect(0,0,640,480);
    BackgroundSprite.Render(game->MainRenderer);
	BackButton->Render(game->MainRenderer);
	SoundCheckBox->Render(game->MainRenderer);
	SDL_RenderPresent(game->MainRenderer);
}
