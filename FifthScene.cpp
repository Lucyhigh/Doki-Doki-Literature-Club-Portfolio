#include "Stdafx.h"
#include "FifthScene.h"

HRESULT FifthScene::init(void)
{
	IMAGEMANAGER->addImage("빛배경", "Resources/Images/BackGround/monika_bg.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배경", "Resources/Images/BackGround/monika_bgnor.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("우주", "Resources/Images/BackGround/monika_bgEffect2.bmp", WINSIZE_X*0.65, WINSIZE_Y*0.67, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름", "Resources/Images/BackGround/monika_bgEffect.bmp", WINSIZE_X*0.65, WINSIZE_Y*0.67, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("우주배경", "Resources/Images/BackGround/monika_bgEffect3.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	Text _text[TEXTNumLast];
	_count = 0;
	_restCount = 0;
	_textBufferCnt = 0;
	_textIndex = 0;
	_bgSpeed = 0;
	_alpha = 0;
	_textAlpha = 0;
	_bgAlpha = 0;
	_reverse = 1;
	isMonicaRest = false;
	return S_OK;
}

void FifthScene::release(void)
{
}

void FifthScene::update(void)
{
	_count++;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_textBufferCnt < wcslen(_text[_textIndex].script))
		{
			_textBufferCnt = wcslen(_text[_textIndex].script);
		}
		else if (_textIndex == 84 || _textIndex == 114 || _textIndex == 123 || _textIndex == 160 || _textIndex == 171 || _textIndex == 182 || _textIndex == 192 || _textIndex == 214 || _textIndex == 231 || _textIndex == 235 || _textIndex == 258 || _textIndex == 274 || _textIndex == 304 || _textIndex == 312 || _textIndex == 321 || _textIndex == 341)
		{
			isMonicaRest = true;
		}
		else
		{
			_textBufferCnt = 0;
			_textIndex++;
		}
	}
	if (_count % 2 == 0 && _textBufferCnt < wcslen(_text[_textIndex].script))
	{
		_textBufferCnt++;
	}
	if (isMonicaRest)
	{
		monicaRest();
	}
	_bgAlpha += 0.5f * _reverse;
	_textAlpha += 4.0f;
	_bgSpeed += 3;
	if (_bgAlpha == 250 || _bgAlpha == 5)
	{
		_reverse *= -1;
	}
	if (_textAlpha >= 230) _textAlpha = 230;
}

void FifthScene::render(void)
{
	IMAGEMANAGER->loopRender("우주배경", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), _bgSpeed / 5, 0);
	IMAGEMANAGER->loopRender("우주", getMemDC(), &RectMake(0, WINSIZE_Y / 5, WINSIZE_X*0.65, WINSIZE_Y*0.67), _bgSpeed / 3, 0);
	IMAGEMANAGER->loopRender("구름", getMemDC(), &RectMake(0, WINSIZE_Y / 5, WINSIZE_X*0.65, WINSIZE_Y*0.67), _bgSpeed / 10, 30);
	IMAGEMANAGER->alphaRender("배경", getMemDC(), 0, 0, 255);
	IMAGEMANAGER->alphaRender("빛배경", getMemDC(), 0, 0, _bgAlpha);
	IMAGEMANAGER->alphaRender("텍스트창", getMemDC(), _textAlpha);

	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.26, WINSIZE_Y*0.75, "a어린이날M", 27, 15, _text[_textIndex].name, wcslen(_text[_textIndex].name), RGB(0, 0, 0));
	const int SCRIPT_MAX_LENGTH = 55;
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.84, "나눔스퀘어_ac", 30, 100, _text[_textIndex].script,
		((_textBufferCnt) > SCRIPT_MAX_LENGTH ? SCRIPT_MAX_LENGTH : (_textBufferCnt)), RGB(255, 255, 255));

	if (wcslen(_text[_textIndex].script) > SCRIPT_MAX_LENGTH && _textBufferCnt > SCRIPT_MAX_LENGTH)
	{
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.90, "나눔스퀘어_ac", 30, 100,
			_text[_textIndex].script + SCRIPT_MAX_LENGTH, (_textBufferCnt > wcslen(_text[_textIndex].script)) ?
			wcslen(_text[_textIndex].script) - SCRIPT_MAX_LENGTH : _textBufferCnt - SCRIPT_MAX_LENGTH, RGB(255, 255, 255));
	}
}

void FifthScene::monicaRest(void)
{
	if (_count % 7 == 0 && 0 <= _restCount && _restCount <= 20)
	{
		_restCount++;
	}
	else if (_restCount > 20)
	{
		if (_textIndex == 341)
		{
			_textIndex = 0;
		}
		_textIndex++;
		_textBufferCnt = 0;
		isMonicaRest = false;
		_restCount = 0;
	}
}
