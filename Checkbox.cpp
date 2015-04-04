#include "Checkbox.hpp"

CCheckBox::CCheckBox(int x, int y, bool isTicked)
{
    m_PosX = x;
    m_PosY = y;
    m_tCheckBox = NULL;

    CurrentState = BOX_IS_ON;

    if (isTicked == true)
    {
        CurrentState = BOX_IS_ON;
        IsOn = true;
        IsOff = false;
    }
    else
    {
        CurrentState = BOX_NOT_ON;
        IsOn = false;
        IsOff = true;
    }
}


void CCheckBox::Load(SDL_Renderer* pRenderer)
{
    m_tCheckBox = CheckBoxSprite.Load(pRenderer,"data/imgs/checkboxes/Checkbox_White.png",255,0,255);
}



void CCheckBox::Update()
{
    if (IsOn == true)
    {
        IsOff = false;
    }
    else if (IsOff == true)
    {
        IsOn = false;
    }

    if (MouseOver() == true)
    {
        if (IsClicked() == true && IsOff == true)
        {
            CurrentState = BOX_IS_ON;
        }
        else if (IsClicked() == true && IsOn == true)
        {
            CurrentState = BOX_NOT_ON;
        }
        else
        {
            CurrentState = MOUSE_OVER_BOX;
        }
    }
    else
    {
        CurrentState = BOX_NOT_ON;
    }


    int TempWidth = 0;
    int TempHeight = 0;

    SDL_QueryTexture(m_tCheckBox,NULL,NULL,&TempWidth,&TempHeight);

    m_Width = TempWidth / 3;
    m_Height = TempHeight;

    CheckBoxSprite.SetSourceRect(m_Width*CurrentState,0,m_Width,m_Height);
}

void CCheckBox::Render(SDL_Renderer* pRenderer)
{
    CheckBoxSprite.SetDestinationRect(m_PosX,m_PosY,m_Width,m_Height);
    CheckBoxSprite.Render(pRenderer);

}

bool CCheckBox::MouseOver()
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

bool CCheckBox::IsClicked()
{


    SDL_GetMouseState(&MousePosX,&MousePosY);

    if (MousePosX > m_PosX &&
        MousePosX < m_PosX + m_Width &&
        MousePosY > m_PosY &&
        MousePosY < m_PosY + m_Height)
    {
        SDL_Event Event;

        while (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
                case SDL_MOUSEBUTTONDOWN:

                    switch(Event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            return true;
                            break;

                        default:
                            return false;
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


void CCheckBox::CleanUp()
{
    CheckBoxSprite.CleanUp();
}
