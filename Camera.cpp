#include "Camera.hpp"



CCamera CCamera::Camera;

CCamera::CCamera()
{
    m_PosX = 0;
    m_PosY = 0;
    m_Width = 640;
    m_Height = 480;

    Viewport.x = m_PosX;
    Viewport.y = m_PosY;
    Viewport.w = m_Width;
    Viewport.h = m_Height;
}

void CCamera::Do(CPlayer &Player, CMap &Map, int CameraMode)
{
    if (CameraMode == 0)
    {
        m_PosX = Player.GetPosX() + (Player.GetWidth()/2) - 320;
    }
    else if (CameraMode == 1)
    {
        if (Player.GetPosX() <= 200)
        {
            m_PosX -= 2;
        }
        else if (Player.GetPosX() >= 440)
        {
            m_PosX += 2;
        }
    }
    else
    {
        std::cout << "This camera mode was not defined...\n";
    }

    if (m_PosX <= 0)
    {
        m_PosX = 0;
    }
    else if (m_PosX + m_Width >= Map.GetWidth())
    {
        m_PosX = Map.GetWidth() - m_Width;
    }

    Viewport.x = m_PosX;
}

float CCamera::GetPosX()
{
    return m_PosX;
}

float CCamera::GetPosY()
{
    return m_PosY;
}

