#include "Stdafx.h"
#include "FourthScene.h"

HRESULT FourthScene::init(void)
{
	IMAGEMANAGER->addFrameImage("사요리에러", "Resources/Images/Object/error.bmp", WINSIZE_X*0.65*1.43, WINSIZE_X*0.35*1.43, 2, 1);
	IMAGEMANAGER->addFrameImage("사요리에러2", "Resources/Images/Object/secondError.bmp", WINSIZE_X * 3, WINSIZE_Y, 3, 1, true, RGB(0, 128, 0));

	IMAGEMANAGER->addImage("노이즈", "Resources/Images/BackGround/noise.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("캐릭터선택버튼", "Resources/Images/Object/select_button.bmp", WINSIZE_X / 4, WINSIZE_Y / 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("캐릭터선택한버튼", "Resources/Images/Object/selected_button.bmp", WINSIZE_X / 4, WINSIZE_Y / 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("흰배경", "Resources/Images/BackGround/whiteBg.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("동아리skill배경", "Resources/Images/BackGround/club-skill.bmp", WINSIZE_X, WINSIZE_Y);
	IMAGEMANAGER->addImage("동아리skill배경2", "Resources/Images/BackGround/club-skill2.bmp", WINSIZE_X, WINSIZE_Y);

	IMAGEMANAGER->addImage("나츠키패닉2", "Resources/Images/Object/n_panic2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나츠키울음", "Resources/Images/Object/n_sad.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("나츠키구토", "Resources/Images/Object/n_vomit.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("유리매드", "Resources/Images/Object/y_mad.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리매드2", "Resources/Images/Object/y_mad2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리눈", "Resources/Images/Object/eyes1.bmp", WINSIZE_X *0.3, WINSIZE_Y*0.26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리확대", "Resources/Images/BackGround/y_noeyes.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리킬", "Resources/Images/Object/y_kill1.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리킬2", "Resources/Images/Object/y_kill2.bmp", WINSIZE_X / 2, WINSIZE_X / 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리킬배경", "Resources/Images/BackGround/ykillbg.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리킬배경2", "Resources/Images/BackGround/ykillbg2.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리킬배경3", "Resources/Images/BackGround/ykillbg3.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유리킬배경4", "Resources/Images/BackGround/ykillbg4.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_rcS = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y*0.6, WINSIZE_X*0.35*1.43, WINSIZE_X*0.35*1.43);
	_rcS2 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y*0.5, WINSIZE_X, WINSIZE_Y);
	for (int i = 0; i < SELECTNUM; i++)
	{
		_selectBox[i] = RectMakeCenter(WINSIZE_X *0.51, WINSIZE_Y*0.09*i, WINSIZE_X *0.2, WINSIZE_Y / 20);
	}

	_count = 0;
	_moveCount = 0;
	_textBufferCnt = 0;
	_drop = 0;
	_rndEyeMove = 0;
	_textIndex = 0;
	_frameIndex = 0;
	_loofIndex = 0;
	_alpha = 0;
	_eventAlpha = 0;
	_bgAlpha = 0;
	_textAlpha = 0;
	_moveFifth = false;
	_isTurn_S_error = false;
	_isWrongButton = false;
	_bgMoved = WINSIZE_X;

	return S_OK;
}

void FourthScene::release(void)
{
}

void FourthScene::update(void)
{
	_count++;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_textBufferCnt < wcslen(_text[_textIndex].script))
		{
			_textBufferCnt = wcslen(_text[_textIndex].script);
		}
		else if (_textIndex == 5)
		{
			_isTurn_S_error = true;
		}
		else if (266 <= _textIndex && _textIndex <= 292)
		{
			_eventAlpha += RND->getInt(10);
			_textBufferCnt = 0;
			_textIndex++;
		}
		else if (_textIndex == 647 || _textIndex == 722 || _textIndex == 753)
		{
		}
		else
		{
			_textBufferCnt = 0;
			_textIndex++;
		}
	}

	if (_textIndex == 5 && _isTurn_S_error)
	{
		if (_count % 1 == 0 && 0 <= _loofIndex && _loofIndex <= 20)
		{
			_frameIndex++;
			if (_frameIndex > 2)
			{
				_frameIndex = 0;
				_loofIndex++;
			}
			IMAGEMANAGER->findImage("사요리에러")->setFrameY(0);
			IMAGEMANAGER->findImage("사요리에러")->setFrameX(_frameIndex);

		}
		else if (_count % 1 == 0 && 20 < _loofIndex && _loofIndex <= 35)
		{
			_frameIndex++;
			if (_frameIndex > 3)
			{
				_frameIndex = 0;
				_loofIndex++;
			}
			IMAGEMANAGER->findImage("사요리에러2")->setFrameY(0);
			IMAGEMANAGER->findImage("사요리에러2")->setFrameX(_frameIndex);

		}
		else if (_count % 3 == 0 && 35 < _loofIndex && _loofIndex <= 36)
		{
			_bgAlpha = 0;
			_textIndex++;
			_textBufferCnt = 0;
			_loofIndex = 0;
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

	if (_count % 2 == 0 && _textBufferCnt < wcslen(_text[_textIndex].script))
	{
		_textBufferCnt++;
	}

	if (_textIndex == 9 || _textIndex == 85 || _textIndex == 199 || _textIndex == 210
		|| _textIndex == 298 || _textIndex == 318 || _textIndex == 339 || _textIndex == 550)
	{
		_bgMoved -= 60;
		_alpha = 100;
		if (_bgMoved >= -WINSIZE_X * 0.7)
		{
			_alpha = 0;

		}
		else if (_bgMoved <= -WINSIZE_X)
		{
			_textIndex++;
			_alpha = 0;
		}
	}
	else if (_textIndex == 647)
	{
		for (int i = 3; i < 6; i++)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{

				if (PtInRect(&_selectBox[3], _ptMouse) || PtInRect(&_selectBox[4], _ptMouse))
				{
					_isWrongButton = true;
					_eventAlpha = 0;
				}
				else  if (PtInRect(&_selectBox[5], _ptMouse) && !_isWrongButton)
				{
					_textBufferCnt = 0;
					_textIndex++;
				}
			}

		}
		if (_count % 3 == 0 && _isWrongButton)
		{
			_moveCount++;
			if (_moveCount % 5 == 0)
			{
				_rndEyeMove += RND->getInt(3);
			}
			else
			{
				_rndEyeMove -= RND->getInt(3);
			}
			for (int i = 0; i < SELECTNUM; i++)
			{
				if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
				{

					if (PtInRect(&_selectBox[i], _ptMouse))
					{
						_rndEyeMove -= RND->getInt(30);
						_rndEyeMove += RND->getInt(30);
						_eventAlpha += 5;
					}
				}
			}
			if (_eventAlpha == 255)
			{
				_textBufferCnt = 0;
				_moveCount = 0;
				_textIndex++;
			}
		}
	}
	else if (_textIndex == 722)
	{
		if (_count % 30 == 0 && 0 <= _loofIndex && _loofIndex <= 4)
		{
			_loofIndex++;
			_eventAlpha += 5;
		}
		else if (_count % 2 == 0 && 4 < _loofIndex && _loofIndex <= 38)
		{
			_loofIndex++;
			_eventAlpha += 5;
		}
		else if (_count % 30 == 0 && 38 < _loofIndex && _loofIndex <= 70)
		{
			_loofIndex++;
			_bgAlpha = 255;
		}
		else if (_count % 30 == 0 && _loofIndex == 71)
		{
			_bgAlpha = 255;
			_textBufferCnt = 0;
			_textIndex++;
		}
	}
	else if (_textIndex == 753)
	{
		if (_count % 4 == 0)_moveCount++;
		if (20 < _moveCount && _moveCount <= 30)
		{
			_bgAlpha -= 10;
			_alpha -= 10;

			if (_bgAlpha <= 0) _bgAlpha = 0;
			if (_alpha <= 0) _alpha = 0;
		}
		else if (39 < _moveCount && _moveCount <= 40)
		{
			_moveFifth = true;
		}
	}
	else
	{
		_alpha += 30;
		_bgAlpha += 4;
		_textAlpha += 4;
	}

	if (_bgMoved <= -WINSIZE_X) _bgMoved = WINSIZE_X;
	if (_bgAlpha >= 255) _bgAlpha = 255;
	if (_alpha >= 255) _alpha = 255;
	if (_eventAlpha >= 255) _eventAlpha = 255;
	if (_textAlpha >= 230) _textAlpha = 230;
}

void FourthScene::render(void)
{
	for (size_t i = 0; i < BgImageNUMTWO; i++)
	{
		if (_textIndex <= _bgImage[i]._textIndex)
		{
			IMAGEMANAGER->alphaRender(_bgImage[i]._fileName, getMemDC(), _bgAlpha);
			break;
		}
	}

	if (_textIndex == 350 || _textIndex == 650)
	{
		IMAGEMANAGER->alphaRender("동아리skill배경", getMemDC(), _bgAlpha);
	}
	if (_textIndex == 5 && _isTurn_S_error)
	{
		if (_count % 1 == 0 && 0 <= _loofIndex && _loofIndex <= 20)
		{
			IMAGEMANAGER->frameRender("사요리에러", getMemDC(), _rcS.left, _rcS.top);
		}
		else if (_count % 1 == 0 && 20 < _loofIndex && _loofIndex <= 35)
		{
			IMAGEMANAGER->frameRender("사요리에러2", getMemDC(), _rcS2.left, _rcS2.top);
		}
	}

	int size = _text[_textIndex].imageMoodVec.size();

	if (259 <= _textIndex && _textIndex <= 297)
	{
		IMAGEMANAGER->alphaRender("노이즈", getMemDC(), -RND->getInt(3), -RND->getInt(3), _eventAlpha);
	}
	else if (_textIndex == 722)
	{

		IMAGEMANAGER->alphaRender("동아리skill배경2", getMemDC(), 100 + _eventAlpha);

		if (0 <= _loofIndex && _loofIndex <= 30)
		{
			if (_loofIndex % 3 == 1)
			{
				IMAGEMANAGER->render("유리킬2", getMemDC(), WINSIZE_X / 2 - WINSIZE_X / 4, WINSIZE_Y / 10);
				IMAGEMANAGER->alphaRender("컷전환", getMemDC(), 0, 0, _eventAlpha);
			}
			else
			{
				IMAGEMANAGER->render("유리킬", getMemDC(), WINSIZE_X / 2 - WINSIZE_X / 4, WINSIZE_Y / 10);
			}
		}
		else if (30 < _loofIndex && _loofIndex <= 40)
		{
			if (_count % 2 == 0)
			{
				if (_drop >= 255)
				{
					_drop = 255;
				}
				else _drop += 20;
			}
			IMAGEMANAGER->render("유리킬2", getMemDC(), WINSIZE_X / 2 - WINSIZE_X / 4, WINSIZE_Y / 10 + _drop);
			IMAGEMANAGER->alphaRender("컷전환", getMemDC(), 0, 0, _drop * 5);

		}
		else if (40 < _loofIndex && _loofIndex <= 70)
		{
			if (40 < _loofIndex && _loofIndex <= 48)IMAGEMANAGER->alphaRender("유리킬배경", getMemDC(), 0, 0, _bgAlpha);
			else if (48 < _loofIndex && _loofIndex <= 54)IMAGEMANAGER->alphaRender("유리킬배경2", getMemDC(), 0, 0, _bgAlpha);
			else if (54 < _loofIndex && _loofIndex <= 62)IMAGEMANAGER->alphaRender("유리킬배경3", getMemDC(), 0, 0, _bgAlpha);
			else if (62 < _loofIndex && _loofIndex <= 70)IMAGEMANAGER->alphaRender("유리킬배경4", getMemDC(), 0, 0, _bgAlpha);
		}
	}

	for (int i = 0; i < size; i++)
	{
		IMAGEMANAGER->alphaRender(_text[_textIndex].imageMoodVec[i], getMemDC(), (WINSIZE_X * (i + 1) / (size + 1)) - WINSIZE_X / 4, WINSIZE_Y / 10, _alpha);
	}

	LPCWSTR info1 = { L" 유 리 " };
	LPCWSTR info2 = { L"나 츠 키" };
	LPCWSTR info3 = { L"모 니 카" };
	if (_textIndex == 647 && !_isWrongButton)
	{
		for (int i = 3; i < 6; i++)
		{
			IMAGEMANAGER->render("캐릭터선택버튼", getMemDC(), _selectBox[i].left - WINSIZE_X * 0.04, _selectBox[i].top - WINSIZE_X * 0.02);
			if (PtInRect(&_selectBox[i], _ptMouse))
			{
				IMAGEMANAGER->alphaRender("캐릭터선택한버튼", getMemDC(), _selectBox[i].left - WINSIZE_X * 0.04, _selectBox[i].top - WINSIZE_X * 0.02, 170);

			}
		}
		FONTMANAGER->drawText(getMemDC(), _selectBox[3].left + WINSIZE_X * 0.06, _selectBox[3].top, "a어린이날M", 26, FW_BOLD, info1, wcslen(info1), RGB(0, 0, 0));
		FONTMANAGER->drawText(getMemDC(), _selectBox[4].left + WINSIZE_X * 0.06, _selectBox[4].top, "a어린이날M", 26, FW_BOLD, info2, wcslen(info2), RGB(0, 0, 0));
		FONTMANAGER->drawText(getMemDC(), _selectBox[5].left + WINSIZE_X * 0.06, _selectBox[5].top, "a어린이날M", 26, FW_BOLD, info3, wcslen(info3), RGB(0, 0, 0));
	}
	else if (_textIndex == 647 && _isWrongButton)
	{
		IMAGEMANAGER->render("흰배경", getMemDC());
		IMAGEMANAGER->alphaRender("유리확대", getMemDC(), WINSIZE_X* 0.05 - _rndEyeMove / 3, -WINSIZE_Y / 20 - _rndEyeMove / 3, _eventAlpha);
		IMAGEMANAGER->render("유리눈", getMemDC(), WINSIZE_X * 0.25 + _rndEyeMove, WINSIZE_Y / 4 + _rndEyeMove);
		for (int i = 0; i < SELECTNUM; i++)
		{
			IMAGEMANAGER->render("캐릭터선택버튼", getMemDC(), _selectBox[i].left - WINSIZE_X * 0.04, _selectBox[i].top - WINSIZE_X * 0.02);
			FONTMANAGER->drawText(getMemDC(), _selectBox[2].left + WINSIZE_X * 0.06, _selectBox[i].top, "a어린이날M", 26, FW_BOLD, info3, wcslen(info3), RGB(255, 255, 255));
		}
		for (int i = 0; i < SELECTNUM; i++)
		{
			if (PtInRect(&_selectBox[i], _ptMouse))
			{
				IMAGEMANAGER->alphaRender("캐릭터선택한버튼", getMemDC(), _selectBox[i].left - WINSIZE_X * 0.04, _selectBox[i].top - WINSIZE_X * 0.02, 170);
			}
		}
	}

	IMAGEMANAGER->alphaRender("텍스트창", getMemDC(), _textAlpha);
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.26, WINSIZE_Y*0.75, "a어린이날M", 27, 15, _text[_textIndex].name, wcslen(_text[_textIndex].name), RGB(0, 0, 0));

	const int SCRIPT_MAX_LENGTH = 55;
	FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.84, "나눔스퀘어_ac", 30, 100, _text[_textIndex].script, ((_textBufferCnt) > SCRIPT_MAX_LENGTH ? SCRIPT_MAX_LENGTH : (_textBufferCnt)), RGB(255, 255, 255));

	if (wcslen(_text[_textIndex].script) > SCRIPT_MAX_LENGTH && _textBufferCnt > SCRIPT_MAX_LENGTH)
	{
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X*0.22, WINSIZE_Y*0.90, "나눔스퀘어_ac", 30, 100,
			_text[_textIndex].script + SCRIPT_MAX_LENGTH, (_textBufferCnt > wcslen(_text[_textIndex].script)) ?
			wcslen(_text[_textIndex].script) - SCRIPT_MAX_LENGTH : _textBufferCnt - SCRIPT_MAX_LENGTH, RGB(255, 255, 255));
	}

	if (295 <= _textIndex && _textIndex <= 297)
	{
		IMAGEMANAGER->alphaRender("모니카보통", getMemDC(), WINSIZE_X*0.25, WINSIZE_Y / 10, _alpha);

	}

	if (_textIndex == 9 || _textIndex == 85 || _textIndex == 199 || _textIndex == 210 || _textIndex == 298 || _textIndex == 318 || _textIndex == 339 || _textIndex == 550)
	{
		IMAGEMANAGER->render("컷전환", getMemDC(), _bgMoved, 0);
	}
}
bool FourthScene::getMoveFifth(void)
{
	return _moveFifth;
}