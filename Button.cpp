#include "Button.hpp"



CButton::CButton(int x, int y, bool center_horizontal)
{
    m_PosX = x;
    m_PosY = y;

    CurrentState = BUTTON_NOT_CLICKED;

    Centered_Hor = center_horizontal;

    m_tButton = NULL;
}


void CButton::Load(SDL_Renderer* pRenderer, const char* cPath)
{
    m_tButton = ButtonSprite.Load(pRenderer,cPath,255,0,255);
}



void CButton::Update()
{
    if (MouseOver() == true)
    {
        if (IsClicked() == true)
        {
            CurrentState = BUTTON_IS_CLICKED;
        }
        else
        {
            CurrentState = MOUSE_OVER_BUTTON;
        }
    }
    else
    {
        CurrentState = BUTTON_NOT_CLICKED;
    }

    int TempWidth;
    int TempHeight;

    SDL_QueryTexture(m_tButton,NULL,NULL,&TempWidth,&TempHeight);

    m_Width = TempWidth/2;
    m_Height = TempHeight;

    ButtonSprite.SetSourceRect(m_Width*CurrentState,0,m_Width,m_Height);

}

void CButton::Render(SDL_Renderer* pRenderer)
{
    if (Centered_Hor == true)
    {
        m_PosX = (Game.GetWindowWidth()/2) - (m_Width/2);
    }

    ButtonSprite.SetDestinationRect(m_PosX,m_PosY,m_Width,m_Height);
    ButtonSprite.Render(pRenderer);

}

bool CButton::MouseOver()
{
    SDL_GetMouseState(&MousePosX,&MousePosY);

    if (MousePosX > m_PosX &&
        MousePosX < m_PosX + m_Width &&
        MousePosY > m_PosY &&
        MousePosY < m_PosY + m_Height)
    {
            return true;
    }
    else
    {
        return false;
    }

}

bool CButton::IsClicked()
{
    SDL_Event Event;

    SDL_GetMouseState(&MousePosX,&MousePosY);

    if (MousePosX > m_PosX &&
        MousePosX < m_PosX + m_Width &&
        MousePosY > m_PosY &&
        MousePosY < m_PosY + m_Height)
    {
        if (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
                case SDL_MOUSEBUTTONDOWN:

                    switch(Event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            return true;
                            break;
                    }
            }
        }
    }

    else
    {
        return false;
    }
}

void CButton::CleanUp()
{
    ButtonSprite.CleanUp();
    SDL_DestroyTexture(m_tButton);
}

