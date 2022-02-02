#include "Stdafx.h"
#include "SecondScene.h"
HRESULT SecondScene::init(void)
{
	IMAGEMANAGER->addImage("����ȯ", "Resources/Images/BackGround/cutChange.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("��Ÿ����", "Resources/Images/BackGround/residential.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("���ǹ��", "Resources/Images/BackGround/class.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("�������", "Resources/Images/BackGround/corridor.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("���Ƹ����", "Resources/Images/BackGround/club.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("���չ��", "Resources/Images/BackGround/house.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("��丮ų���", "Resources/Images/BackGround/s_kill_pos.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("��丮ų2���", "Resources/Images/BackGround/s_kill_bg2.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("�ؽ�Ʈâ", "Resources/Images/Object/text.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "Resources/Images/Object/s_poem.bmp", WINSIZE_X*0.5, WINSIZE_Y*0.8, false, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��丮�д�", "Resources/Images/Object/s_panic.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��丮����", "Resources/Images/Object/s_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��丮����", "Resources/Images/Object/s_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��丮�ҽ�", "Resources/Images/Object/s_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��丮����", "Resources/Images/Object/s_sad.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��丮ų", "Resources/Images/Object/s_sad.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��丮ų2", "Resources/Images/Object/s_sad2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("���ī����", "Resources/Images/Object/m_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ī����", "Resources/Images/Object/m_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ī�ҽ�", "Resources/Images/Object/m_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ī����", "Resources/Images/Object/m_pose.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("����Ű����", "Resources/Images/Object/n_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ű����2", "Resources/Images/Object/n_nor2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ű�д�", "Resources/Images/Object/n_panic.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ű����", "Resources/Images/Object/n_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����Ű�ҽ�", "Resources/Images/Object/n_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��������", "Resources/Images/Object/y_nor.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����д�", "Resources/Images/Object/y_panic.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "Resources/Images/Object/y_smile.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����ҽ�", "Resources/Images/Object/y_shy.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

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
		IMAGEMANAGER->alphaRender("��", getMemDC(), WINSIZE_X / 4, 0, _eventAlpha);
	}

	IMAGEMANAGER->alphaRender("�ؽ�Ʈâ", getMemDC(), _textAlpha);
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.26, WINSIZE_Y*0.75, "a��̳�M", 27, 15, _text[_textIndex].name, wcslen(_text[_textIndex].name), RGB(0, 0, 0));
	if (1014 <= _textIndex && _textIndex <= 1015)
	{
		LPCWSTR ending = { L"E N D" };
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.45, WINSIZE_Y / 2, "DejaVuSansMono", 27, 15, ending, wcslen(ending), RGB(255, 255, 255));
	}
	const int SCRIPT_MAX_LENGTH = 55;
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.84, "����������_ac", 30, 100, _text[_textIndex].script,
		((_textBufferCnt) > SCRIPT_MAX_LENGTH ? SCRIPT_MAX_LENGTH : (_textBufferCnt)), RGB(255, 255, 255));

	if (wcslen(_text[_textIndex].script) > SCRIPT_MAX_LENGTH && _textBufferCnt > SCRIPT_MAX_LENGTH)
	{
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.90, "����������_ac", 30, 100,
			_text[_textIndex].script + SCRIPT_MAX_LENGTH, (_textBufferCnt > wcslen(_text[_textIndex].script)) ?
			wcslen(_text[_textIndex].script) - SCRIPT_MAX_LENGTH : _textBufferCnt - SCRIPT_MAX_LENGTH, RGB(255, 255, 255));
	}

	if (_textIndex == 20 || _textIndex == 84 || _textIndex == 290 || _textIndex == 302 || _textIndex == 488 || _textIndex == 510 || _textIndex == 758 || _textIndex == 865 || _textIndex == 885 || _textIndex == 950)
	{
		IMAGEMANAGER->render("����ȯ", getMemDC(), _bgMoved, 0);
	}
}
bool SecondScene::getMoveThird(void)
{
	return _moveThird;
}