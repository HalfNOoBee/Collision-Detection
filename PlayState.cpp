#include "GameState.hpp"
#include "Game.hpp"
#include "PlayState.hpp"
#include "PauseMenuState.hpp"
#include "GameOverState.hpp"
#include "Camera.hpp"


CPlayState CPlayState::m_PlayState;


void CPlayState::Init(SDL_Renderer* pRenderer)
{
	std::cout << "CPlayState Init\n";

	Map.Load(pRenderer,"data/maps/1-1.txt",2560,480);

    Player.Load(pRenderer,255,0,255);
    Goombas.Load(pRenderer,255,0,255);

    PlayTime.StartTicks();

	PauseButton = new CButton(0,0,false);
	PauseButton->Load(pRenderer,"data/imgs/buttons/Pause.png");

    Soundtrack = Mix_LoadMUS("data/sounds/Super Mario Galaxy - Dream Drifting (Remix).mp3");
    if (Soundtrack == NULL)
    {
        std::cout << "Failed to load the soundtrack! Mix_GetError(): " << Mix_GetError() << "\n";
    }

    ScoreField = new CTTF(80,20);
    LivesField = new CTTF(250,20);
    CoinsField = new CTTF(350,20);
    TimeField = new CTTF(450,20);

    LivesTexture = LivesSprite.Load(pRenderer,"data/imgs/player/Mario.png",255,0,255);
    CoinsTexture = CoinsSprite.Load(pRenderer,"data/imgs/player/Minicoins.png",255,0,255);

    ScoreField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);
    LivesField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);
    CoinsField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);
    TimeField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);

    Mix_PlayMusic(Soundtrack,-1);
}

void CPlayState::Cleanup()
{
    delete PauseButton;

    SDL_DestroyTexture(LivesTexture);
    SDL_DestroyTexture(CoinsTexture);

    Mix_FreeMusic(Soundtrack);
    Soundtrack = NULL;

	std::cout << "CPlayState Cleanup\n";
}

void CPlayState::Pause()
{
	std::cout << "CPlayState Pause\n";
}

void CPlayState::Resume()
{
	std::cout << "CPlayState Resume\n";
}

void CPlayState::HandleEvents(CGame* game)
{
    SDL_Event Event;


    if (PauseButton->IsClicked() == true)
    {
        game->PushState(CPauseMenuState::Instance());
    }

	while (SDL_PollEvent(&Event))
    {
        Player.HandleInput(Event);

		switch (Event.type)
		{
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (Event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						game->Quit();
						break;

                    case SDLK_p:
                        game->PushState(CPauseMenuState::Instance());
                        break;
				}
				break;
		}
	}
}

void CPlayState::Update(CGame* game)
{
    Player.Update(&Map);
    Goombas.Update(&Map);
    CCamera::Camera.Do(Player,Map,0);
    PauseButton->Update();

    if (Player.m_bGameOver == true)
    {
        PlayTime.StopTicks();
        game->ChangeState(CGameOverState::Instance());
        Player.ResetAllStats();
    }

    if (Player.CoinsChanged() == true)
    {
        CoinsField->NeedsUpdate(true);
    }

    if (Player.LivesChanged() == true)
    {
        LivesField->NeedsUpdate(true);
    }

    if (Player.ScoreChanged() == true)
    {
        ScoreField->NeedsUpdate(true);
    }

    if (PlayTime.GetCurrentTicks() - 1 <= PlayTime.GetCurrentTicks())
    {
        TimeField->NeedsUpdate(true);
    }

    if (CurrentFrame >= 2)
    {
        CurrentFrame = 0;
    }
    else
    {
        CurrentFrame++;
    }

    LivesSprite.SetSourceRect(0,0,28,32);
    LivesSprite.SetDestinationRect(230,21,17,20);

    CoinsSprite.SetSourceRect(10 * CurrentFrame,0,10,16);
    CoinsSprite.SetDestinationRect(335,25,10,16);
}

void CPlayState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,10,50,0);
    SDL_RenderClear(game->MainRenderer);

    Map.Render(game->MainRenderer);
    Goombas.Render(game->MainRenderer);
    Player.Render(game->MainRenderer);
	PauseButton->Render(game->MainRenderer);

    ScoreField->Render(game->MainRenderer,"Mario\n" + Player.GetCurrentScore(),255,255,255);
    LivesField->Render(game->MainRenderer,"x" + Player.GetCurrentLives(),255,255,255);
    LivesSprite.Render(game->MainRenderer);
    CoinsField->Render(game->MainRenderer,"x" + Player.GetCurrentAmountOfCoins(),255,255,255);
    CoinsSprite.Render(game->MainRenderer);
    TimeField->Render(game->MainRenderer,"Time\n" + PlayTime.GetCurrentTicksInString(),255,255,255);

	SDL_RenderPresent(game->MainRenderer);
}
