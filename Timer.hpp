#ifndef _TIMER_HPP_
    #define _TIMER_HPP_

#include "SDL.h"
#include <string>
#include <sstream>
#include <iomanip>

class CTimer
{
    public:
        CTimer();

        void StartTicks();
        void StopTicks();

        int GetCurrentTicks();
        std::string GetCurrentTicksInString();

        bool SetTimeLimit(int TimeLimitInMilliseconds);

        void Reset();

    private:
        int m_StartTime;
        int m_StopTime;

        int m_CurrentTicks;

        bool m_bHasStarted;
        bool m_bHasStopped;

        std::stringstream tt;
        std::string m_sCurrentTime;

};


#endif // _TIMER_HPP_


