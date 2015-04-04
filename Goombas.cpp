#include "Goombas.hpp"
#include "Camera.hpp"


CGoombas::CGoombas() : CSDLGameObject() //Here is the error
{
    m_bRight = false;
    m_bLeft = true;
    m_bIsFalling = true;
    m_State = "WALKING";

    m_PosX = 400;
    m_PosY = 300;
    m_Width = 32;
    m_Height = 32;

    m_VelX = 4;
    m_VelY = 35;

    m_CurrentFrame = 0;
    m_CurrentRow = 0;

    m_Lives = 1;
}

void CGoombas::Load(SDL_Renderer* pRenderer, int R, int G, int B)
{
    ObjectTexture = GoombasSprite.Load(pRenderer,"data/imgs/enemies/Goombas_Brown.png",R,G,B);
}

void CGoombas::Update(CMap* Map)
{
    int TilePos = 0;
	m_VelY = 30;
	m_bIsFalling = true;

	if (m_State != "DEAD")
    {
        m_State = "WALKING";
    }

	//x axis first (--)
	if(m_bRight == true)
    {
		if(Collision_Ver(m_PosX + m_Width + m_VelX, m_PosY, TilePos, Map) > 0) //Change direction if the goombas hits anything but a blank tile
        {
			m_PosX = (TilePos * Tile.GetSize()) - m_Width;
			m_VelX = -m_VelX;
			std::cout << "Changed VelX to " << m_VelX << "\n";
        }
        else
        {
            m_PosX += m_VelX;
        }
	}
	else if(m_bLeft == true)
	{
		if(Collision_Ver(m_PosX - m_VelX, m_PosY, TilePos, Map) > 0)
        {
            m_PosX = (TilePos + 1)* Tile.GetSize();
            m_VelX = -m_VelX;
            std::cout << "Changed VelX to " << m_VelX << "\n";
        }
		else
        {
            m_PosX -= m_VelX;
        }
	}

	//then y axis (|)
	if (m_bIsFalling == true)
    {
		if(Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) != 0 && Collision_Hor(m_PosX, (m_PosY + m_Gravity + m_Height), TilePos, Map) != 5)
		{
            m_PosY = (TilePos * Tile.GetSize()) - m_Height - m_Gravity;
			m_VelY = 0;

			m_bIsFalling = true;
		}
		else
		{
		    m_VelY = m_Gravity;
		}

        m_PosY += m_VelY;

	}

	UpdateLives();

    HandleStates();
}

void CGoombas::Render(SDL_Renderer* pRenderer)
{
    GoombasSprite.SetDestinationRect(m_PosX - CCamera::Camera.GetPosX(),m_PosY - CCamera::Camera.GetPosY(),m_Width,m_Height);
    GoombasSprite.Render(pRenderer);
}

int CGoombas::Collision_Hor(int x, int y, int &TileCoordY, CMap* Map)
{
	int TileXInPixels = x - (x % Tile.GetSize()) ;
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

int CGoombas::Collision_Ver(int x, int y, int &TileCoordX, CMap* Map)
{
	int TileYInPixels = y - (y % Tile.GetSize());
	int CheckEnd = y + m_Height;

 	TileCoordX = x / Tile.GetSize();

	int TileCoordY = TileYInPixels / Tile.GetSize();

	while(TileYInPixels <= CheckEnd)
    {
        return Map->GetTypeOfTileAtPos(TileCoordX,TileCoordY);

		TileCoordY++;
		TileYInPixels += Tile.GetSize();
	}
}

void CGoombas::SetPosX(float NewPosX)
{
    m_PosX = NewPosX;
}

void CGoombas::SetPosY(float NewPosY)
{
    m_PosY = NewPosY;
}

void CGoombas::SetMaxFrames(int NewMaxFrames)
{
    m_MaxFrames = NewMaxFrames;
}

void CGoombas::HandleStates() //Handling the sprite animation depending on state
{
    if (m_State == "WALKING")
    {
        m_CurrentRow = 0;
        if (m_CurrentFrame == 0 )
        {
            m_CurrentFrame = 1;
        }
        else if (m_CurrentFrame == 1)
        {
            m_CurrentFrame = 0;
        }

        std::cout << m_CurrentFrame << "\n";
    }
    else if (m_State == "DEAD")
    {
        m_CurrentRow = 0;
        m_CurrentFrame = 2;
    }
    else
    {
        std::cout << "Undefined state of animation for goombas...\n";
    }

    GoombasSprite.SetSourceRect(m_Width * m_CurrentFrame, m_Height * m_CurrentRow,m_Width,m_Height);
}

void CGoombas::UpdateLives()
{
    if (m_Lives <= 0)
    {
        m_Lives = 0;
        m_bDead = true;
    }
    else if (m_Lives >= 99)
    {
        m_Lives = 99;
    }
}
