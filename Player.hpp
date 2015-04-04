#ifndef _PLAYER_HPP_
    #define _PLAYER_HPP_


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Timer.hpp"
#include "SDLGameObject.hpp"
#include "Map.hpp"
#include "Tile.hpp"
#include "TTF.hpp"


class CPlayer : public CSDLGameObject
{
    public:
        CPlayer();

        void Load(SDL_Renderer* pRenderer, int R, int G, int B);
        void HandleInput(SDL_Event Event);
        void Update(CMap* Map);
        void Render(SDL_Renderer* pRenderer);

        void DoCollisionCheckToMap(CMap* Map);
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

        std::string GetName();
        void SetName(std::string Name);

        std::string GetState() { return m_State; }
        void SetState(std::string NewState);
        void HandleStates();

        std::string GetCurrentScore() { return m_sScore; }
        void UpdateScore();
        bool ScoreChanged() { return m_bScoreChanged; }

        std::string GetCurrentLives() { return m_sLives; }
        void UpdateLives();
        bool LivesChanged() { return m_bLivesChanged; }

        std::string GetCurrentAmountOfCoins() { return m_sCoins; }
        void UpdateCoins();
        bool CoinsChanged() { return m_bCoinsChanged; }

        void ResetAllStats();
        void SaveAllStats();

        bool m_bGameOver;

    private:
        std::string m_Name;
        std::string m_State;

        int m_JumpOffset;
        int m_JumpApex;
        bool m_bOffsetIsSet;
        bool m_bApexReached;

        int m_Score;
        std::string m_sScore;
        std::stringstream ss;
        bool m_bScoreChanged;

        int m_Lives;
        std::string m_sLives;
        std::stringstream ll;
        bool m_bLivesChanged;

        int m_Coins;
        std::string m_sCoins;
        std::stringstream cc;
        bool m_bCoinsChanged;

        bool m_bDying;
        bool m_bLockJump;
        bool m_bTouchesGround;

        CSprite PlayerSprite;
        CTile Tile;

        int m_Time;
        std::string m_sTime;
        std::stringstream tt;

        Mix_Chunk* cJump;
        Mix_Chunk* cBlockhit;
        Mix_Chunk* cCoinCollected;
        Mix_Chunk* cDeath;
        Mix_Chunk* cGameOver;
        Mix_Music* Soundtrack;
};


#endif // _PLAYER_HPP_
