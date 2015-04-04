#include "Tile.hpp"
#include "Camera.hpp"

CTile::CTile()
{
    TileID = 0;
    TypeID = TILE_TYPE_NONE;
    CurrentFrame = 0;
}

int CTile::GetSize()
{
    return TILE_SIZE;
}

int CTile::GetTileID()
{
    return TileID;
}

int CTile::GetTypeID()
{
    return TypeID;
}

void CTile::SetTileID(int TempTileID)
{
    if (TempTileID <= 100)
    {
        TileID = TempTileID;
    }
    else
    {
        std::cout << "Error";
    }
}

void CTile::SetTypeID(int TempTypeID)
{
    if (TempTypeID <= 6)
    {
        TypeID = TempTypeID;
    }
    else
    {
        std::cout << "Error";
    }

}

bool CTile::IsOnScreen(int X, int Y)
{
    if (X + TILE_SIZE >= CCamera::Camera.Viewport.x &&
        X <= CCamera::Camera.Viewport.x + CCamera::Camera.Viewport.w &&
        Y + TILE_SIZE >= CCamera::Camera.Viewport.y &&
        Y <= CCamera::Camera.Viewport.y + CCamera::Camera.Viewport.h)
    {
         return true;
    }
    else
    {
        return false;
    }
}

void CTile::SetMaxFrames(int MaxFrames)
{
    m_MaxFrames = MaxFrames;
}

void CTile::Animate()
{
    if (CurrentFrame <= m_MaxFrames - 1)
    {
        CurrentFrame++;
    }
    else
    {
        CurrentFrame = 0;
    }
}
