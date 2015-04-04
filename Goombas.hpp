#ifndef _GOOMBAS_HPP_
    #define _GOOMBAS_HPP_


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Timer.hpp"
#include "Player.hpp"
#include "SDLGameObject.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include "TTF.hpp"


class CGoombas : public CSDLGameObject
{
    public:
        CGoombas();

        void Load(SDL_Renderer* pRenderer, int R, int G, int B);
        void HandleInput(SDL_Event Event);
        void Update(CMap* Map);
        void Render(SDL_Renderer* pRenderer);

        int Collision_Hor(int x, int y, int &TileCoordY, CMap* Map);
        int Collision_Ver(int x, int y, int &TileCoordX, CMap* Map);

        void SetPosX(float NewPosX);
        float GetPosX () { return m_PosX; }

        void SetPosY(float NewPosY);
        float GetPosY () { return m_PosY; }

        float GetWidth() { return m_Width; }
        float GetHeight() { return m_Height; }

        int GetCurrentFrame() { return m_CurrentFrame; }
        void SetMaxFrames(int NewMaxFrames);

        std::string GetState() { return m_State; }
        void SetState(std::string NewState);
        void HandleStates();

        int GetCurrentLives() { return m_Lives; }
        void UpdateLives();

    private:
        std::string m_State;

        int m_Lives;
        std::string m_sLives;
        std::stringstream ll;

        bool m_bDead;
        bool m_bIsFalling;

        CSprite GoombasSprite;
        CTile Tile;

};


#endif // _GOOMBAS_HPP_

