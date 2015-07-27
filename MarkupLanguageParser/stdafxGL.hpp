//stdafxGL.hpp

#pragma once

#include "stdafx.hpp"


#ifdef USE_OS_STANDARD

//Standard Windows Environment

#ifdef _WIN32
#include <Windows.h>
#endif

//Standard Linux Environment

#ifdef __linux__
#include <x11/Xlib.h>
#endif

#endif


//And some Microsoft stuff

#ifdef _WIN32

#ifdef USE_MFC
#		include <afx.h>
#		include <afxwin.h>
#		include <afxext.h>
#		ifndef _AFX_NO_OLE_SUPPORT
#			include <afxdtctl.h>
#		endif
#		ifndef _AFX_NO_AFXCMN_SUPPORT
#			include <afxcmn.h>
#		endif
#endif
#ifdef USE_ATL
#		include <atlbase.h>
#		include <atlstr.h>
#endif

#endif

//OpenGL

#ifdef USE_OPENGL

#ifdef USE_GL3W //Do not use with GLEW, GLFW3, or GLUT/FREEGLUT
#	include <GL/gl3w.h>
#else
#	ifdef USE_GLEW
#		include <GL/glew.h>
#		ifdef _WIN32
#		pragma comment(lib, "glew32.lib")
#		endif
#	endif
#	ifdef USE_GLFW3
#		include <GLFW/glfw3.h>
#		ifdef _WIN32
#		pragma comment(lib, "glfw3dll.lib")
#		endif
#	endif
#	ifdef USE_GLUT
#		ifdef USE_FREEGLUT
#			include <GL/freeglut.h>
#		else
#			include <GL/glut.h>
#		endif
#		ifdef _WIN32
#		pragma comment(lib, "freeglut.lib")
#		endif
#	endif
#endif

#ifdef USE_SDL
#	include <SDL/SDL.h>
#	ifdef _WIN32
#	pragma comment(lib, "SDL2main.lib")
#	pragma comment(lib, "SDL2.lib")
#	endif
#endif

#ifdef USE_GLM
#	include <glm/glm.hpp>
#	ifdef USE_GLI
#		include <gli/gli.hpp>
#	endif
#endif

#ifdef USE_GLU
#	include <GL/GLU.h>
#endif

#ifdef __linux__
#	ifndef USE_OS_STANDARD
#		include <x11/Xlib.h>
#	endif
#	include <GL/glx.h>
#endif

#include <GL/GL.h>

#endif

//DirectX and XNA
//Don't use this please
//Its unfinished...

#ifdef _WIN32

#ifdef USE_DIRECTX

#ifdef USE_DIRECT3D
#	include <d3dx11.h>
#endif

#endif

#endif