#include "Timer.hpp"
#include <iostream>


CTimer::CTimer()
{
    m_StartTime = 0;
    m_StopTime = 0;

    m_bHasStarted = false;
    m_bHasStopped = false;
}


void CTimer::StartTicks()
{
    if (m_bHasStarted = false)
    {
        m_StartTime = SDL_GetTicks();
    }
}

void CTimer::StopTicks()
{
    if (m_bHasStarted == true)
    {
        m_StopTime = SDL_GetTicks();
    }
    else
    {
        std::cout << "Timer needs to be started before he can be stopped!\n";
    }

}

int CTimer::GetCurrentTicks()
{
    m_CurrentTicks = (int) ((SDL_GetTicks() - m_StartTime)/1000);

    return m_CurrentTicks;
}

std::string CTimer::GetCurrentTicksInString()
{
    m_CurrentTicks = (int) ((SDL_GetTicks() - m_StartTime)/1000);

    tt.str("");
    tt << std::setw(4) << std::setfill(' ') << m_CurrentTicks;
 	m_sCurrentTime = "";
 	m_sCurrentTime = tt.str().c_str();

    return m_sCurrentTime;
}

bool CTimer::SetTimeLimit(int TimeLimitInMilliseconds)
{
    if (TimeLimitInMilliseconds - (SDL_GetTicks() - m_StartTime) > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void CTimer::Reset()
{
    m_StartTime = 0;
    m_StartTime = SDL_GetTicks();
}
