#pragma once
#include "SingletonBase.h"
#include "Text.h"

class FontManager : public SingletonBase <FontManager>
{
public:
	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWidth, LPCWSTR printStringArr, int Iength, COLORREF color);

	void drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWidth, LPCWSTR* printString, int Iength, COLORREF color);

	FontManager() { }
	~FontManager() { }
};

