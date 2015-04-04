#ifndef _CAMERA_HPP_
    #define _CAMERA_HPP_

#include "SDL.h"
#include <iostream>
#include "Player.hpp"
#include "Map.hpp"

enum {CAMERA_CENTERED = 0,
      CAMERA_DEADZONES = 1};


class CCamera
{
    public:
        static CCamera Camera;
        CCamera();

        void Do(CPlayer& Player, CMap& Map, int CameraMode);

        float GetPosX();
        float GetPosY();

        SDL_Rect Viewport;

    private:
        float m_PosX;
        float m_PosY;
        float m_Width;
        float m_Height;

};

#endif // _CAMERA_HPP_

