#include "HighScoreState.hpp"
#include "GameState.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "PlayState.hpp"


CHighScoreState CHighScoreState::m_HighScoreState;

void CHighScoreState::Init(SDL_Renderer* pRenderer)
{
	std::cout << "CHighScoreState Init\n";

	TitleField = new CTTF(50,20);
	TitleField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",40);

	/*DancingMarioTexture = DancingMarioSprite.Load(pRenderer, "data/imgs/others/Dancing Mario/Super Mario Dancing.png", 0,0,0);*/

	Soundtrack = Mix_LoadMUS("data/sounds/Avicii - Super Mario World Levels.mp3");
	if (Soundtrack == NULL)
    {
        std::cout << "Failed to load music of high score screen! Mix_Error(): " << Mix_GetError() << "\n";
    }

    Mix_PlayMusic(Soundtrack, -1);

}

void CHighScoreState::Cleanup()
{
    delete TitleField;

    Mix_FreeMusic(Soundtrack);
    Soundtrack = NULL;

    //Player.m_bGameOver = false;

	std::cout << "CHighScoreState Cleanup\n";
}

void CHighScoreState::Pause()
{
	std::cout << "CHighScoreState Pause\n";
}

void CHighScoreState::Resume()
{
	std::cout << "CHighScoreState Resume\n";
}

void CHighScoreState::HandleEvents(CGame* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
    {
		switch (event.type)
        {
			case SDL_QUIT:
				game->Quit();
				break;


            case SDL_KEYDOWN: //No matter which key, it will change state
                game->ChangeState(CMainMenuState::Instance());
                break;
		}
	}
}

void CHighScoreState::Update(CGame* game)
{
    /*if (m_CurrentFrame >= 51)
    {
        m_CurrentFrame = 0;
    }
    else
    {
        m_CurrentFrame++;
    }

    DancingMarioSprite.SetSourceRect(498 * m_CurrentFrame, 0, 498, 521); //Dimensions of mario*/

}

void CHighScoreState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,0,0,0);
    SDL_RenderClear(game->MainRenderer);

    /*DancingMarioSprite.SetDestinationRect(300,200,50,52);
    DancingMarioSprite.Render(game->MainRenderer);*/

	TitleField->Render(game->MainRenderer,"High Scores:",255,255,255);

	SDL_RenderPresent(game->MainRenderer);
}



