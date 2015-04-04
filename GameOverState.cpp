#include "GameOverState.hpp"
#include "GameState.hpp"
#include "Game.hpp"
#include "HighScoreState.hpp"


CGameOverState CGameOverState::m_GameOverState;

void CGameOverState::Init(SDL_Renderer* pRenderer)
{
	std::cout << "CGameOverState Init\n";

	GameOverField = new CTTF(200,200);
	GameOverField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",30);

}

void CGameOverState::Cleanup()
{
    delete GameOverField;

	std::cout << "CGameOverState Cleanup\n";
}

void CGameOverState::Pause()
{
	std::cout << "CGameOverState Pause\n";
}

void CGameOverState::Resume()
{
	std::cout << "CGameOverState Resume\n";
}

void CGameOverState::HandleEvents(CGame* game)
{
	SDL_Event event;

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

void CGameOverState::Update(CGame* game)
{
    SDL_Delay(5000);

    game->ChangeState(CHighScoreState::Instance());
}

void CGameOverState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,0,0,0);
    SDL_RenderClear(game->MainRenderer);

	GameOverField->Render(game->MainRenderer,"Game over",255,255,255);

	SDL_RenderPresent(game->MainRenderer);
}


