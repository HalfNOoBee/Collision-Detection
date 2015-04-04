#include "ExplanationState.hpp"
#include "GameState.hpp"
#include "Game.hpp"
#include "PlayState.hpp"


CExplanationState CExplanationState::m_ExplanationState;

void CExplanationState::Init(SDL_Renderer* pRenderer)
{
	std::cout << "CExplanationState Init\n";

	ExplanationField = new CTTF(0,50);
	ExplanationField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);

    GetPlayerNameField = new CTTF(330,220);
	GetPlayerNameField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",30);

	EnterYourNameField = new CTTF(85,225);
	EnterYourNameField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);

	TaskField = new CTTF(75,170);
	TaskField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",20);

	PressEnterToContinueField = new CTTF (150,420);
	PressEnterToContinueField->Load(pRenderer,"data/fonts/karmatic-arcade.regular.ttf",18);

    Mario = MarioSprite.Load(pRenderer,"data/imgs/player/Mario.png",255,0,255);
	Peach = PeachSprite.Load(pRenderer,"data/imgs/others/Peach.png",255,0,255);
	Bowser = BowserSprite.Load(pRenderer,"data/imgs/others/Bowser.png",255,0,255);

	cTooManyChars = Mix_LoadWAV("data/sounds/blockinput.wav");
	if (cTooManyChars == NULL)
    {
        std::cout << "Failed to load input block sound effect... Mix_Error: " << Mix_GetError() << "\n";
    }

	m_PlayerName = "type here";
}

void CExplanationState::Cleanup()
{
    delete ExplanationField;
    delete GetPlayerNameField;
    delete EnterYourNameField;
    delete TaskField;
    delete PressEnterToContinueField;

    m_PlayerName = "";

	std::cout << "CExplanationState Cleanup\n";
}

void CExplanationState::Pause()
{
	std::cout << "CExplanationState Pause\n";
}

void CExplanationState::Resume()
{
	std::cout << "CExplanationState Resume\n";
}

void CExplanationState::HandleEvents(CGame* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
    {
		switch (event.type)
        {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						game->Quit();
						break;

                    case SDLK_BACKSPACE:
                        if (m_PlayerName.length() > 0)
                        {
                            m_PlayerName.pop_back();
                            GetPlayerNameField->NeedsUpdate(true);
                        }
                        break;

                    case SDLK_RETURN:
                        CExplanationState::ChangeState(game,CPlayState::Instance());
                        break;

                    case SDLK_c:
                        if(event.key.keysym.sym == SDL_GetModState() & KMOD_CTRL )
                        {
                            SDL_SetClipboardText(m_PlayerName.c_str());
                        }
                        break;

                    case SDLK_v:
                        if(event.key.keysym.sym == SDL_GetModState() & KMOD_CTRL )
                        {
                            m_PlayerName = SDL_GetClipboardText();
                            GetPlayerNameField->NeedsUpdate(true);
                        }
                        break;
				}
				break;

            case SDL_TEXTINPUT:
                m_PlayerName += event.text.text;
                GetPlayerNameField->NeedsUpdate(true);
                std::cout << event.text.text;
                break;
		}
	}
}

void CExplanationState::Update(CGame* game)
{
    while (m_PlayerName.length() > 10)
    {
        Mix_PlayChannel(-1,cTooManyChars,0);
        m_PlayerName.pop_back();
    }

    MarioSprite.SetSourceRect(0,0,28,32);
    PeachSprite.SetSourceRect(0,0,28,59);
    BowserSprite.SetSourceRect(0,0,76,86);
}

void CExplanationState::Render(CGame* game)
{
    SDL_SetRenderDrawColor(game->MainRenderer,0,0,0,0);
    SDL_RenderClear(game->MainRenderer);

	ExplanationField->Render(game->MainRenderer,"use 'A' and 'D' to move the player\nuse 'Space' to jump\npress 'P' to pause while playing",255,255,255);
	EnterYourNameField->Render(game->MainRenderer,"Enter your name:",255,255,255);
	TaskField->Render(game->MainRenderer,"Survive as long as possible!",255,0,0);
	PressEnterToContinueField->Render(game->MainRenderer,"Press ENTER to continue",255,255,255);

	MarioSprite.SetDestinationRect(190,343,28,32);
	MarioSprite.Render(game->MainRenderer);
	PeachSprite.SetDestinationRect(310,320,20,55);
	PeachSprite.Render(game->MainRenderer);
	BowserSprite.SetDestinationRect(340,300,76,86);
	BowserSprite.Render(game->MainRenderer);

	if (m_PlayerName == "")
    {
        m_PlayerName = " ";
    }
    else
    {
        GetPlayerNameField->Render(game->MainRenderer,m_PlayerName,255,255,255);
    }

	SDL_RenderPresent(game->MainRenderer);
}

