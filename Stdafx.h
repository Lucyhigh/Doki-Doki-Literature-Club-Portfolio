#pragma once
#include <SDKDDKVer.H>
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <cassert>
#include <iostream>
#include <random>
#include <bitset>
#include <vector>
#include <map>

using namespace std;
#include "CommonMarcroFuntion.h"
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"

#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
#define WINNAME				(LPSTR)(TEXT("WindowsAPI"))
#define WINSTART_X			0
#define WINSTART_Y			0
#define WINSIZE_X			GetSystemMetrics(SM_CXSCREEN)			
#define WINSIZE_Y			GetSystemMetrics(SM_CYSCREEN)	
#define WINSTYLE			WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p)				{if(p) {delete(p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)		{if(p) {delete[](p); (p)=nullptr;}}
#define SAFE_RELEASE(p)				{if(p) {(p)->release(); (p)=nullptr;}}

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;