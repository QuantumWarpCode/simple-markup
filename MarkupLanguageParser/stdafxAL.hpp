//stdafxGL.hpp

#pragma once

#include "stdafx.hpp"

#ifdef USE_OS_STANDARD

//Standard Windows Environment

#ifdef _WIN32
#include <Windows.h>
#endif

#endif

#ifdef USE_OPENAL
#	include <AL/al.h>
#	ifdef _WIN32
#	pragma comment(lib, "OpenAL32.lib")
#	endif
#endif

#ifdef USE_SDL
#	include <SDL/SDL.h>
#	ifdef _WIN32
#	pragma comment(lib, "SDL2main.lib")
#	pragma comment(lib, "SDL2.lib")
#	endif
#endif