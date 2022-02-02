#include "Stdafx.h"
#include "ThirdScene.h"

HRESULT ThirdScene::init(void)
{

	IMAGEMANAGER->addImage("지운사요리", "Resources/Images/Object/s_delete.bmp", WINSIZE_X / 4, WINSIZE_Y, true, RGB(255, 0, 255));

	_moveBox[0] = RectMakeCenter(WINSIZE_X *0.22, WINSIZE_Y *0.6, 520, 50);
	_moveBox[1] = RectMakeCenter(WINSIZE_X *0.22, WINSIZE_Y *0.7, 520, 50);
	_moveBox[2] = RectMakeCenter(WINSIZE_X *0.50, WINSIZE_Y *0.55, 50, 50);

	_alpha = 0;
	_bgAlpha = 0;
	_isStart = false;
	_moveFourth = false;

	return S_OK;
}

void ThirdScene::release(void)
{
}

void ThirdScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_moveBox[0], _ptMouse))
		{
			_isStart = true;
		}
		if (PtInRect(&_moveBox[2], _ptMouse))
		{
			_moveFourth = true;
		}
		if (PtInRect(&_moveBox[1], _ptMouse))
		{
			PostQuitMessage(0);
		}
	}

	_bgSpeed += 2;
	_bgAlpha += 2.0f;
	if (_bgAlpha >= 255) _bgAlpha = 255;
}

void ThirdScene::render(void)
{
	if (_isStart)
	{
		IMAGEMANAGER->alphaRender("시작화면", getMemDC(), 0, 0, 70);
		IMAGEMANAGER->render("정사각형창", getMemDC());

		LPCWSTR script = { L"Player! 우리 둘만의 게임을 시작해볼까?" };
		LPCWSTR script2 = { L"예" };
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X *0.41, WINSIZE_Y *0.45, "나눔스퀘어_ac", 25, FW_BOLD, script, wcslen(script), RGB(0, 0, 0));
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X *0.49, WINSIZE_Y *0.55, "a어린이날M", 40, FW_BOLD, script2, wcslen(script2), RGB(255, 255, 255));
	}
	else
	{
		IMAGEMANAGER->loopRender("배경루프", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), _bgSpeed, _bgSpeed);
		IMAGEMANAGER->alphaRender("시작화면", getMemDC(), 0, 0, _bgAlpha);
		IMAGEMANAGER->alphaRender("메인유리", getMemDC(), WINSIZE_X*0.42, WINSIZE_Y*0.1, _bgAlpha);
		IMAGEMANAGER->alphaRender("메인나츠키", getMemDC(), WINSIZE_X*0.55, WINSIZE_Y*0.15, _bgAlpha);
		IMAGEMANAGER->alphaRender("지운사요리", getMemDC(), WINSIZE_X*0.35, WINSIZE_Y*0.25, _bgAlpha);
		IMAGEMANAGER->alphaRender("메인모니카", getMemDC(), WINSIZE_X*0.58, WINSIZE_Y*0.15, _bgAlpha);
		IMAGEMANAGER->alphaRender("로고", getMemDC(), WINSIZE_X*0.07, -WINSIZE_Y * 0.05, _bgAlpha);

		LPCWSTR info1 = { L"?r━ㄺ섏툩r?ㅼ뿉━t?臾댁ㅅ_t" };
		LPCWSTR info2 = { L"게임 종료" };
		FONTMANAGER->drawText(getMemDC(), _moveBox[0].left, _moveBox[0].top, "a어린이날M", 40, FW_BOLD, info1, wcslen(info1), RGB(194, 118, 157));
		FONTMANAGER->drawText(getMemDC(), _moveBox[1].left, _moveBox[1].top, "a어린이날M", 40, FW_BOLD, info2, wcslen(info2), RGB(194, 118, 157));
	}
}

bool ThirdScene::getMoveFourth(void)
{
	return _moveFourth;
}
