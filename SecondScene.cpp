#include "Stdafx.h"
#include "SecondScene.h"
HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("컷전환", "Resources/Images/BackGround/cutChange.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("길거리배경", "Resources/Images/BackGround/residential.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("교실배경", "Resources/Images/BackGround/class.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("복도배경", "Resources/Images/BackGround/corridor.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("동아리배경", "Resources/Images/BackGround/club.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("집앞배경", "Resources/Images/BackGround/house.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("사요리킬배경", "Resources/Images/BackGround/s_kill_pos.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("사요리킬2배경", "Resources/Images/BackGround/s_kill_bg2.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("텍스트창", "Resources/Images/Object/text.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("시", "Resources/Images/Object/s_poem.bmp", WINSIZE_X*0.5, WINSIZE_Y*0.8, false, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("사요리패닉", "Resources/Images/Object/s_panic.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("사요리보통", "Resources/Images/Object/s_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("사요리웃음", "Resources/Images/Object/s_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("사요리소심", "Resources/Images/Object/s_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("사요리슬픔", "Resources/Images/Object/s_sad.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("사요리킬", "Resources/Images/Object/s_sad.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("사요리킬2", "Resources/Images/Object/s_sad2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("모니카보통", "Resources/Images/Object/m_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("모니카웃음", "Resources/Images/Object/m_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("모니카소심", "Resources/Images/Object/m_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("모니카포즈", "Resources/Images/Object/m_pose.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("나츠키보통", "Resources/Images/Object/n_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나츠키보통2", "Resources/Images/Object/n_nor2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나츠키패닉", "Resources/Images/Object/n_panic.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나츠키웃음", "Resources/Images/Object/n_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나츠키소심", "Resources/Images/Object/n_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("유리보통", "Resources/Images/Object/y_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리패닉", "Resources/Images/Object/y_panic.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리웃음", "Resources/Images/Object/y_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리소심", "Resources/Images/Object/y_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	_count = 0;
	_moveCount = 0;
	_textBufferCnt = 0;
	_textIndex = 0;
	_alpha = 0;
	_eventAlpha = 0;
	_bgAlpha = 0;
	_textAlpha = 0;
	_moveThird = false;
	_bgMoved = WINSIZE_X;
	return S_OK;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
	_count++;
	if (_count % 2 == 0 && _textBufferCnt < wcslen(_text[_textIndex].script))
	{
		_textBufferCnt++;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_textBufferCnt < wcslen(_text[_textIndex].script))
		{
			_textBufferCnt = wcslen(_text[_textIndex].script);
		}
		else if (_textIndex >= 1015)
		{
		}
		else
		{
			_textBufferCnt = 0;
			_textIndex++;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		_textBufferCnt = 0;
		_bgAlpha = 255;
		_alpha = 255;
		_textIndex += 1;
		_bgMoved = WINSIZE_X;
	}

	if (_textIndex == 20 || _textIndex == 84 || _textIndex == 290 || _textIndex == 302 || _textIndex == 488 || _textIndex == 510 || _textIndex == 758 || _textIndex == 865 || _textIndex == 885 || _textIndex == 950)
	{
		_bgMoved -= 60;
		if (_bgMoved >= -WINSIZE_X / 3)
		{
			_alpha = 0;
		}
		else if (_bgMoved <= -WINSIZE_X)
		{
			_textIndex++;
			_alpha = 0;
		}
	}
	else if (935 <= _textIndex && _textIndex <= 938)
	{
		_eventAlpha += 4.0f;
		if (_eventAlpha >= 255) _eventAlpha = 255;
	}
	else if (963 < _textIndex && _textIndex <= 970)
	{
		if (_bgAlpha <= 3) _bgAlpha = 0;
		else _bgAlpha -= 4;
	}
	else if (990 < _textIndex&& _textIndex <= 1014)
	{
		if (_bgAlpha <= 0) _bgAlpha = 0;
		else _bgAlpha -= 1;
	}
	else if (1014 < _textIndex && _textIndex <= 1016)
	{
		if (_count % 4 == 0)_moveCount++;
		if (_moveCount > 40)
		{
			_moveThird = true;
		}
	}
	else
	{
		_alpha += 30.0f;
		_bgAlpha += 4.0f;
		_textAlpha += 4.0f;
		_eventAlpha = 0;
	}

	if (_bgMoved <= -WINSIZE_X) _bgMoved = WINSIZE_X;
	if (_bgAlpha >= 255) _bgAlpha = 255;
	if (_alpha >= 255) _alpha = 255;
	if (_textAlpha >= 230) _textAlpha = 230;
}

void SecondScene::render(void)
{
	for (size_t i = 0; i < BgImageNUM; i++)
	{
		if (_textIndex <= _bgImage[i]._textIndex)
		{
			IMAGEMANAGER->alphaRender(_bgImage[i]._fileName, getMemDC(), _bgAlpha);
			break;
		}
	}

	int size = _text[_textIndex].imageMoodVec.size();

	for (int i = 0; i < size; i++)
	{
		IMAGEMANAGER->alphaRender(_text[_textIndex].imageMoodVec[i], getMemDC(), (WINSIZE_X * (i + 1) / (size + 1)) - WINSIZE_X / 4, 100, _alpha);
	}

	if (937 <= _textIndex && _textIndex <= 939)
	{
		IMAGEMANAGER->alphaRender("시", getMemDC(), WINSIZE_X / 4, 0, _eventAlpha);
	}

	IMAGEMANAGER->alphaRender("텍스트창", getMemDC(), _textAlpha);
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.26, WINSIZE_Y*0.75, "a어린이날M", 27, 15, _text[_textIndex].name, wcslen(_text[_textIndex].name), RGB(0, 0, 0));
	if (1014 <= _textIndex && _textIndex <= 1015)
	{
		LPCWSTR ending = { L"E N D" };
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.45, WINSIZE_Y / 2, "DejaVuSansMono", 27, 15, ending, wcslen(ending), RGB(255, 255, 255));
	}
	const int SCRIPT_MAX_LENGTH = 55;
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.84, "나눔스퀘어_ac", 30, 100, _text[_textIndex].script,
		((_textBufferCnt) > SCRIPT_MAX_LENGTH ? SCRIPT_MAX_LENGTH : (_textBufferCnt)), RGB(255, 255, 255));

	if (wcslen(_text[_textIndex].script) > SCRIPT_MAX_LENGTH && _textBufferCnt > SCRIPT_MAX_LENGTH)
	{
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.90, "나눔스퀘어_ac", 30, 100,
			_text[_textIndex].script + SCRIPT_MAX_LENGTH, (_textBufferCnt > wcslen(_text[_textIndex].script)) ?
			wcslen(_text[_textIndex].script) - SCRIPT_MAX_LENGTH : _textBufferCnt - SCRIPT_MAX_LENGTH, RGB(255, 255, 255));
	}

	if (_textIndex == 20 || _textIndex == 84 || _textIndex == 290 || _textIndex == 302 || _textIndex == 488 || _textIndex == 510 || _textIndex == 758 || _textIndex == 865 || _textIndex == 885 || _textIndex == 950)
	{
		IMAGEMANAGER->render("컷전환", getMemDC(), _bgMoved, 0);
	}
}
bool SecondScene::getMoveThird(void)
{
	return _moveThird;
}