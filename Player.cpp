#include "Player.hpp"
#include "Camera.hpp"
#include <fstream>
#include <ctime>

CPlayer::CPlayer() : CSDLGameObject()
{
    m_Name = "";
    m_bRight = false;
    m_bLeft = false;
    m_bIsJumping = false;
    m_State = "STAND_RIGHT";
    m_bLockJump = false;
    m_bOffsetIsSet = false;
    m_bApexReached = false;
    m_bTouchesGround = false;

    m_bGameOver = false;

    m_PosX = 200;
    m_PosY = 300;
    m_Width = 28;
    m_Height = 32;

    m_VelX = 5;
    m_VelY = 35;

    m_JumpingHeight = 300;

    m_CurrentFrame = 0;
    m_CurrentRow = 0;

    m_Score = 0;
    m_sScore = "";

    m_Lives = 1;
    m_sLives = "";

    m_Coins = 0;
    m_sCoins = "";

    cJump = NULL;
    cBlockhit = NULL;
    cCoinCollected = NULL;
    cDeath = NULL;
    cGameOver = NULL;

}

void CPlayer::Load(SDL_Renderer* pRenderer, int R, int G, int B)
{
    ObjectTexture = PlayerSprite.Load(pRenderer,"data/imgs/player/Mario.png",R,G,B);

    cJump = Mix_LoadWAV("data/sounds/jump.wav");
    if (cJump == NULL)
    {
        std::cout << "Failed to load the jump.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }

    cBlockhit = Mix_LoadWAV("data/sounds/blockhit.wav");
    if (cBlockhit == NULL)
    {
        std::cout << "Failed to load the blockhit.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }

    cCoinCollected = Mix_LoadWAV("data/sounds/coin.wav");
    if (cCoinCollected == NULL)
    {
        std::cout << "Failed to load the coin.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }

    cDeath = Mix_LoadWAV("data/sounds/death.wav");
    if (cDeath == NULL)
    {
        std::cout << "Failed to load the death.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }

    cGameOver = Mix_LoadWAV("data/sounds/gameover.wav");
    if (cGameOver == NULL)
    {
        std::cout << "Failed to load the gameover.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }
}

void CPlayer::HandleInput(SDL_Event Event)
{
    switch (Event.type)
    {
        case SDL_KEYDOWN:
            switch (Event.key.keysym.sym)
            {
                case SDLK_a:
                    m_bLeft = true;
                    break;
                case SDLK_d:
                    m_bRight = true;
                    break;
                case SDLK_SPACE:
                    if (m_bLockJump == false)
                    {
                        m_bIsJumping = true;
                    }
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (Event.key.keysym.sym)
            {
                case SDLK_a:
                    m_bLeft = false;
                    m_State = "STAND_LEFT";
                    break;
                case SDLK_d:
                    m_bRight = false;
                    m_State = "STAND_RIGHT";
                    break;
                case SDLK_SPACE:
                    m_bIsJumping = false;
                    m_bApexReached = true;
                    break;
            }
    }
}

void CPlayer::Update(CMap* Map)
{
    int TilePos = 0;

    m_VelX = 5;
	m_VelY = 30;

	m_bScoreChanged = false;
	m_bLivesChanged = false;
	m_bCoinsChanged = false;

	m_bTouchesGround = false;

	//x axis first (--)
	if(m_bRight == true)
    {
        if (m_State != "JUMPING")
        {
            m_State = "WALKING_RIGHT";
        }
        else
        {
            m_State = "JUMPING";
        }

		if(Collision_Ver(m_PosX + m_Width + m_VelX, m_PosY, TilePos, Map) == 1)
        {
			m_PosX = (TilePos * Tile.GetSize()) - m_Width;
			Mix_PlayChannel(-1,cBlockhit,0);
        }
        else if (Collision_Ver(m_PosX + m_Width + m_VelX, m_PosY, TilePos, Map) == 2)
        {
            m_PosX = (TilePos * Tile.GetSize()) - m_Width;
            Mix_PlayChannel(-1,cBlockhit,0);
        }
        else if (Collision_Ver(m_PosX + m_Width + m_VelX, m_PosY, TilePos, Map) == 3) //Lava
        {
            m_VelX = 0;
            m_bDead = true;
            m_State = "DYING";
            m_Lives -= 1;
            m_bLivesChanged = true;
        }
        else if (Collision_Ver(m_PosX + m_Width + m_VelX, m_PosY, TilePos, Map) == 5) //Coins
        {
            m_PosX += m_VelX;
            m_Score += 100;
            m_bScoreChanged = true;
			m_Coins += 1;
			m_bCoinsChanged = true;
			Mix_PlayChannel(-1,cCoinCollected,0);

			Map->SetTileAtPos( (int) (m_PosX / 32), (int) (m_PosY / 32),0,0);
        }
		else
        {
            m_PosX += m_VelX;
        }
	}
	else if(m_bLeft)
	{
	    if (m_State != "JUMPING")
        {
            m_State = "WALKING_LEFT";
        }
        else
        {
            m_State = "JUMPING";
        }

		if(Collision_Ver(m_PosX - m_VelX, m_PosY, TilePos, Map) == 1)
        {
            m_PosX = (TilePos + 1)* Tile.GetSize();
            Mix_PlayChannel(-1,cBlockhit,0);
        }
        else if (Collision_Ver(m_PosX - m_VelX, m_PosY, TilePos, Map) == 2)
        {
            m_PosX = (TilePos + 1)* Tile.GetSize();
        }
        else if (Collision_Ver(m_PosX - m_VelX, m_PosY, TilePos, Map) == 3)
        {
            m_VelX = 0;
            m_State = "DYING";
            m_Lives -= 1;
            m_bLivesChanged = true;
        }
        else if (Collision_Ver(m_PosX - m_VelX, m_PosY, TilePos, Map) == 5) //Coins
        {
            m_PosX -= m_VelX;
            m_Score += 100;
            m_bScoreChanged = true;
			m_Coins += 1;
			m_bCoinsChanged = true;
			Mix_PlayChannel(-1,cCoinCollected,0);

			Map->SetTileAtPos( (int) ((m_PosX - m_VelX) / 32), (int) (m_PosY / 32),0,0);
        }
        else if (Collision_Ver(m_PosX, m_PosY, TilePos, Map) == 6) //
        {
            m_PosX = (TilePos + 1)* Tile.GetSize();
        }
		else
        {
            m_PosX -= m_VelX;
        }
	}

	//then y axis (|)
 	if(m_bIsJumping == true) //up
    {
        m_State = "JUMPING";

        Mix_PlayChannel(-1,cJump,0);

		if(Collision_Hor(m_PosX, (m_PosY - m_VelY), TilePos, Map) == 1)
        {
			m_PosY = (TilePos + 1)* Tile.GetSize();
			m_VelY = 0;
			m_bLockJump = true;
			m_bApexReached = true;
			if (m_bApexReached == true)
            {
                m_PosY += m_Gravity;
            }

			Mix_PlayChannel(-1,cBlockhit,0);
		}
		else if(Collision_Hor(m_PosX, (m_PosY - m_VelY), TilePos, Map) == 2)
        {
			m_PosY	-= m_VelY;
		}
		else if(Collision_Hor(m_PosX, (m_PosY - m_VelY), TilePos, Map) == 3)
        {
            m_VelX = 0;
            m_PosY += m_Gravity;
			m_State = "DYING";
            m_Lives -= 1;
            m_bLivesChanged = true;
		}
		else if(Collision_Hor(m_PosX, (m_PosY - m_VelY), TilePos, Map) == 5)
        {
			m_PosY	-= m_VelY;
			m_sScore = "";
			m_Score += 100;
			m_bScoreChanged = true;
			Mix_PlayChannel(-1,cCoinCollected,0);

			m_sCoins = "";
			m_Coins += 1;
			m_bCoinsChanged = true;

			Map->SetTileAtPos( (int) (m_PosX / 32), (int) (m_PosY / 32),0,0);

		}
		else if(Collision_Hor(m_PosX, (m_PosY - m_VelY), TilePos, Map) == 6)
        {
			m_PosY = (TilePos + 1)* Tile.GetSize();
			m_VelY = 0;
			Mix_PlayChannel(-1,cBlockhit,0);
		}
		else if(Collision_Hor(m_PosX, (m_PosY - m_VelY), TilePos, Map) == 7)
        {
			m_PosY = (TilePos + 1)* Tile.GetSize();
			m_VelY = 0;
		}
		else
        {
            if (m_bLockJump == false && m_bApexReached == false)
            {
                if (m_bOffsetIsSet == false)
                {
                    m_JumpOffset = m_PosY;
                    m_JumpApex = m_JumpOffset - m_JumpingHeight;
                    m_bOffsetIsSet = true;
                }

                if (m_PosY > m_JumpApex)
                {
                    m_PosY -= m_Gravity; //Move up at same speed like we move down
                }
                else if (m_PosY <= m_JumpApex)
                {
                    m_bApexReached = true;
                    m_bLockJump = true;
                }
            }

            if (m_bApexReached == true)
            {
                m_PosY += m_Gravity;
            }
		}
	}
	else
    {
		if(Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) == 1)
		{
            m_PosY = (TilePos * Tile.GetSize()) - m_Height - m_Gravity;
			m_VelY = 0;

			m_bTouchesGround = true;
			m_bIsJumping = false;
			m_bLockJump = false;
			m_bApexReached = false;

		}
		else if(Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) == 2)
		{
			m_PosY = (TilePos * Tile.GetSize()) - m_Height - m_Gravity;
			m_VelY = 0;

			m_bTouchesGround = true;
			m_bIsJumping = false;
			m_bLockJump = false;
			m_bApexReached = false;
		}
		else if(Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) == 3)
		{
			m_State = "DYING";
            m_Lives -= 1;

            m_bLockJump = true;
            m_bApexReached = false;
		}
		else if(Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) == 5)
		{
			m_VelY = m_Gravity;
			m_Score += 100;
			m_Coins += 1;
            Mix_PlayChannel(-1,cCoinCollected,0);

			Map->SetTileAtPos( (int) (m_PosX / 32), (int) (m_PosY / 32),0,0);

			m_bLockJump = true;
		}
		else if(Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) == 6)
		{
			m_PosY += m_VelX;
		}
        else
        {
			m_VelY = m_Gravity;

			if(m_VelY >= Tile.GetSize())
            {
				m_VelY = Tile.GetSize();
            }
			m_bLockJump = true;
		}

		std::cout << "m_bTouchesGround: " << m_bTouchesGround << "\n";

		if (m_bTouchesGround == true)
        {
            if (m_bRight == true)
            {
                m_State = "WALKING_RIGHT";
            }
            else if (m_bLeft == true)
            {
                m_State = "WALKING_LEFT";
            }
        }
        else
        {
            m_State = "JUMPING";
        }

        m_PosY += m_VelX;
	}

	UpdateScore();
	UpdateLives();
	UpdateCoins();

    HandleStates();
}

void CPlayer::Render(SDL_Renderer* pRenderer)
{
    PlayerSprite.SetDestinationRect(m_PosX - CCamera::Camera.GetPosX(),m_PosY - CCamera::Camera.GetPosY(),m_Width,m_Height);
    PlayerSprite.Render(pRenderer);
}

int CPlayer::Collision_Hor(int x, int y, int &TileCoordY, CMap* Map)
{
	int TileXInPixels = x - (x % Tile.GetSize());
	int CheckEnd = x + m_Width;

	TileCoordY = y / Tile.GetSize();

	int TileCoordX = TileXInPixels / Tile.GetSize();

	while(TileXInPixels <= CheckEnd)
    {
        return Map->GetTypeOfTileAtPos(TileCoordX,TileCoordY);

 		TileCoordX++;
		TileXInPixels += Tile.GetSize();
	}
}

int CPlayer::Collision_Ver(int x, int y, int &TileCoordX, CMap* Map)
{
	int TileYInPixels = y - (y % Tile.GetSize());
	int CheckEnd = y + m_Height;

 	TileCoordX = x / Tile.GetSize();
 	std::cout << TileCoordX << "\n";

	int TileCoordY = TileYInPixels / Tile.GetSize();

	while(TileYInPixels <= CheckEnd)
    {
        return Map->GetTypeOfTileAtPos(TileCoordX,TileCoordY);

		TileCoordY++;
		TileYInPixels += Tile.GetSize();
	}
}

void CPlayer::SetPosX(float NewPosX)
{
    m_PosX = NewPosX;
}

void CPlayer::SetPosY(float NewPosY)
{
    m_PosY = NewPosY;
}

std::string CPlayer::GetName()
{
    return m_Name;
}

void CPlayer::SetName(std::string Name)
{
    m_Name = Name;
}

void CPlayer::SetMaxFrames(int NewMaxFrames)
{
    m_MaxFrames = NewMaxFrames;
}

void CPlayer::HandleStates() //Handling the sprite animation depending on state
{
    if (m_State == "STAND_RIGHT")
    {
        m_CurrentRow = 0;
        m_CurrentFrame = 0;
    }
    else if (m_State == "STAND_LEFT")
    {
        m_CurrentRow = 1;
        m_CurrentFrame = 0;
    }
    else if (m_State == "JUMPING")
    {
        m_CurrentFrame = 1;
    }
    else if (m_State == "WALKING_RIGHT")
    {
        m_CurrentRow = 0;
        if (m_CurrentFrame < 4)
        {
            m_CurrentFrame++;
        }
        else
        {
            m_CurrentFrame = 2;
        }
    }
    else if (m_State == "WALKING_LEFT")
    {
        m_CurrentRow = 1;
        if (m_CurrentFrame < 4)
        {
            m_CurrentFrame++;
        }
        else
        {
            m_CurrentFrame = 2;
        }
    }
    else if (m_State == "DYING")
    {
        m_CurrentRow = 0;
        m_CurrentFrame = 5;
    }
    else if (m_State == "SLIDING_END")
    {
        m_CurrentRow = 0;
        m_CurrentFrame = 6;
    }

    PlayerSprite.SetSourceRect(m_Width * m_CurrentRow, m_Height * m_CurrentFrame,m_Width,m_Height);
}

void CPlayer::UpdateScore()
{
    if (m_Score <= 0)
    {
        m_Score = 0;
    }

    ss.str("");
    ss << std::setw(6) << std::setfill('0') << m_Score;
 	m_sScore = "";
 	m_sScore = ss.str().c_str();

}

void CPlayer::UpdateLives()
{
    if (m_PosY + m_Height >= 480)
    {
        m_Lives -= 1;
        Mix_PlayChannel(-1,cDeath,0);
    }

    if (m_Lives <= 0)
    {
        m_Lives = 0;
        if (m_PosY >= 750)
        {
            m_bGameOver = true;
        }
    }
    else if (m_Lives >= 99)
    {
        m_Lives = 99;
    }

    if (m_bGameOver == true)
    {
        SaveAllStats();
        Mix_PlayChannel(-1,cGameOver,0);
    }

    ll.str("");
    ll << std::setw(2) << std::setfill('0') << m_Lives;
    m_sLives = ll.str().c_str();

}

void CPlayer::UpdateCoins()
{
    if (m_Coins <= 0)
    {
        m_Coins = 0;
    }
    else if (m_Coins >= 999)
    {
        m_Coins = 999;
    }

    cc.str("");
    cc << std::setw(3) << std::setfill('0') << m_Coins;
    m_sCoins = cc.str().c_str();
}

void CPlayer::ResetAllStats()
{
    m_Name = "";
    m_bRight = false;
    m_bLeft = false;
    m_bIsJumping = false;
    m_State = "STAND_RIGHT";
    m_bLockJump = false;
    m_bOffsetIsSet = false;
    m_bApexReached = false;
    m_bTouchesGround = false;

    m_bGameOver = false;

    m_PosX = 200;
    m_PosY = 300;
    m_Width = 28;
    m_Height = 32;

    m_VelX = 5;
    m_VelY = 35;

    m_JumpingHeight = 300;

    m_CurrentFrame = 0;
    m_CurrentRow = 0;

    m_Score = 0;
    m_sScore = "";

    m_Lives = 1;
    m_sLives = "";

    m_Coins = 0;
    m_sCoins = "";

    cJump = NULL;
    cBlockhit = NULL;
    cCoinCollected = NULL;
    cDeath = NULL;
    cGameOver = NULL;
}

void CPlayer::SaveAllStats()
{
    std::ofstream highscorefile;

    highscorefile.open("data/highscores.txt");
    highscorefile << m_Score << "\t" << m_Coins << "\t" << m_Time << "\n";
    highscorefile.close();
}
