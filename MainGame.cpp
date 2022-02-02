#include "Stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init(void)
{
	GameNode::init(TRUE);

	_start = new StartScene;
	_start->init();

	_second = new SecondScene;
	_second->init();

    _third = new ThirdScene;
    _third->init();

    _fourth = new FourthScene;
    _fourth->init();

	_fifth = new FifthScene;
	_fifth->init();

	_currentScene = _start;			
	assert(_currentScene != nullptr);

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	SAFE_DELETE(_start);
	SAFE_DELETE(_second);
	SAFE_DELETE(_third);
	SAFE_DELETE(_fourth);
	SAFE_DELETE(_fifth);
}

void MainGame::update(void)
{
	GameNode::update();

	_currentScene->update();

	if (KEYMANAGER->isOnceKeyDown('Q')) _currentScene = _start;
	if (KEYMANAGER->isOnceKeyDown('W')|| _start->getMoveSecond()) _currentScene = _second;
	if (KEYMANAGER->isOnceKeyDown('E')|| _second->getMoveThird()) _currentScene = _third;
	if (KEYMANAGER->isOnceKeyDown('R')|| _third->getMoveFourth()) _currentScene = _fourth;
	if (KEYMANAGER->isOnceKeyDown('T')|| _fourth->getMoveFifth()) _currentScene = _fifth;
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	_currentScene->render();
	this->getBackBuffer()->render(getHDC());
}