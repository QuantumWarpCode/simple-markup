//stdafx.hpp

#pragma once

//Set to compile for most recent Windows version
//Doesn't apply to Linux or Mingw
#ifdef _MSC_VER
#	include <SDKDDKVer.h>
#	ifdef SUPER_LEAN
#	define WIN32_LEAN_AND_MEAN
#	define VC_EXTRALEAN
#	endif
#endif

#include <exception>

#ifdef _DEBUG
#include <assert.h>
#else
#define NDEBUG
#include <assert.h>
#endif

//Data types
#include <string> 
#include <cstring>
#include <tchar.h>

#include <cstdint>
#include <cmath>
#include <vector>

//Streams
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <fstream>

//Misc
#include <cstdlib>
#include <ctime>

//Libraries and Unsupported
#ifdef _MSC_VER
#	include <conio.h>
#endif

#ifdef __MINGW32__
#	include <conio.h>
#endif