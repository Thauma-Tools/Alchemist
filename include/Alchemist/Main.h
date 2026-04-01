#ifndef __ALCHEMIST_MAIN_H_
#define __ALCHEMIST_MAIN_H_

#include <Alchemist/Config.h>
#include <Alchemist/Core/Log.h>

extern int TTAPI Alchemist_Main(void);

#if ALCHEMIST_PLATFORM_WIN32
#include <Windows.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) // NOLINT
#else
int main(int, char **) // NOLINT
#endif
{
    tt::Logger logger = tt::Logger::create("Alchemist::Main");
    std::string msg = "Loading Alchemist...";
    logger.log(msg);

    return Alchemist_Main();
}

#endif // __ALCHEMIST_MAIN_H_
