#include "Stdafx.h"
#include "FontManager.h"

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWidth, LPCWSTR printString, int Iength, COLORREF color)
{
	SetBkMode(hdc, TRANSPARENT);

	HFONT hFont = CreateFont
	(
		fontSize, 0, 0, 5, fontWidth,
		0, 0, 0,
		HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT(fontName)
	);

	auto oldFont = (HFONT)SelectObject(hdc, hFont);
	auto oldColor = GetTextColor(hdc);

	SetTextColor(hdc, color);
	TextOutW(hdc, destX, destY, printString, Iength);
	SelectObject(hdc, oldFont);
	DeleteObject(hFont);

	SetTextColor(hdc, oldColor);
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fontSize, int fontWidth, LPCWSTR* printStringArr, int Iength, COLORREF color)
{
	SetBkMode(hdc, TRANSPARENT);
	int arraySize = sizeof(printStringArr) / sizeof(*printStringArr);

	HFONT hFont = CreateFont
	(
		fontSize, 0, 0, 5, fontWidth,
		0, 0, 0,
		HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT(fontName)
	);

	auto oldFont = (HFONT)SelectObject(hdc, hFont);
	auto oldColor = GetTextColor(hdc);	SetTextColor(hdc, RGB(0, 0, 0));

	SetTextColor(hdc, color);
	TextOutW(hdc, destX, destY, printStringArr[arraySize], Iength);

	SelectObject(hdc, oldFont);
	DeleteObject(hFont);

	SetTextColor(hdc, oldColor);
}