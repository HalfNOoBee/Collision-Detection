#ifndef _SDLGAMEOBJECT_HPP_
    #define _SDLGAMEOBJECT_HPP_


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Sprite.hpp"
#include "Map.hpp"

class CSDLGameObject
{
    public:
        CSDLGameObject() {m_PosX = 0;
                          m_PosY = 0;
                          m_Width = 0;
                          m_Height = 0;
                          m_VelX = 0;
                          m_VelY = 0;
                          m_Gravity = 8;
                          m_CurrentFrame = 0;
                          m_CurrentRow = 0;
                          m_MovingSpeed = 0;
                          m_JumpingHeight = 0;
                          m_bIsJumping = false;
                          m_bLeft = false;
                          m_bRight = false;
                          m_bDead = false; }

    public:
        virtual void Load(SDL_Renderer* pRenderer, int R, int G, int B) = 0;
        //virtual void HandleInput(SDL_Event Event) = 0;
        virtual void Update(CMap* Map) = 0;
        virtual void Render(SDL_Renderer* pRenderer) = 0;

        virtual void SetPosX(float NewPosX) = 0;
        virtual float GetPosX () { return m_PosX; }

        virtual void SetPosY(float NewPosY) = 0;
        virtual float GetPosY () { return m_PosY; }

        virtual float GetWidth() { return m_Width; }
        virtual float GetHeight() { return m_Height; }

        virtual int GetCurrentFrame() { return m_CurrentFrame; }
        virtual void SetMaxFrames(int NewMaxFrames) = 0;


    protected:
        CSprite ObejctSprite;
        SDL_Texture* ObjectTexture;

        bool m_bIsJumping;
        bool m_bRight;
        bool m_bLeft;

        bool m_bDead;

        float m_PosX;
        float m_PosY;
        float m_Width;
        float m_Height;

        float m_VelX;
        float m_VelY;
        float m_Gravity;

        int m_CurrentFrame;
        int m_CurrentRow;
        int m_MaxFrames;

        int m_MovingSpeed;
        int m_JumpingHeight;
};

#endif // _SDLGAMEOBJECT_HPP_

