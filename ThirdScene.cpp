#include "Stdafx.h"
#include "ThirdScene.h"

HRESULT ThirdScene::init(void)
{

	IMAGEMANAGER->addImage("�����丮", "Resources/Images/Object/s_delete.bmp", WINSIZE_X / 4, WINSIZE_Y, true, RGB(255, 0, 255));

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
		IMAGEMANAGER->alphaRender("����ȭ��", getMemDC(), 0, 0, 70);
		IMAGEMANAGER->render("���簢��â", getMemDC());

		LPCWSTR script = { L"Player! �츮 �Ѹ��� ������ �����غ���?" };
		LPCWSTR script2 = { L"��" };
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X *0.41, WINSIZE_Y *0.45, "����������_ac", 25, FW_BOLD, script, wcslen(script), RGB(0, 0, 0));
		FONTMANAGER->drawText(getMemDC(), WINSIZE_X *0.49, WINSIZE_Y *0.55, "a��̳�M", 40, FW_BOLD, script2, wcslen(script2), RGB(255, 255, 255));
	}
	else
	{
		IMAGEMANAGER->loopRender("������", getMemDC(), &RectMake(0, 0, WINSIZE_X, WINSIZE_Y), _bgSpeed, _bgSpeed);
		IMAGEMANAGER->alphaRender("����ȭ��", getMemDC(), 0, 0, _bgAlpha);
		IMAGEMANAGER->alphaRender("��������", getMemDC(), WINSIZE_X*0.42, WINSIZE_Y*0.1, _bgAlpha);
		IMAGEMANAGER->alphaRender("���γ���Ű", getMemDC(), WINSIZE_X*0.55, WINSIZE_Y*0.15, _bgAlpha);
		IMAGEMANAGER->alphaRender("�����丮", getMemDC(), WINSIZE_X*0.35, WINSIZE_Y*0.25, _bgAlpha);
		IMAGEMANAGER->alphaRender("���θ��ī", getMemDC(), WINSIZE_X*0.58, WINSIZE_Y*0.15, _bgAlpha);
		IMAGEMANAGER->alphaRender("�ΰ�", getMemDC(), WINSIZE_X*0.07, -WINSIZE_Y * 0.05, _bgAlpha);

		LPCWSTR info1 = { L"?r�����츠r?�에��t?무줵_t" };
		LPCWSTR info2 = { L"���� ����" };
		FONTMANAGER->drawText(getMemDC(), _moveBox[0].left, _moveBox[0].top, "a��̳�M", 40, FW_BOLD, info1, wcslen(info1), RGB(194, 118, 157));
		FONTMANAGER->drawText(getMemDC(), _moveBox[1].left, _moveBox[1].top, "a��̳�M", 40, FW_BOLD, info2, wcslen(info2), RGB(194, 118, 157));
	}
}

bool ThirdScene::getMoveFourth(void)
{
	return _moveFourth;
}
