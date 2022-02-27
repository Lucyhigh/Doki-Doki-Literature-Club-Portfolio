#pragma once
#include "GameNode.h"
#include "StartScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"
#include "FourthScene.h"
#include "FifthScene.h"

class MainGame : public GameNode
{
private:
	StartScene* _start;
	SecondScene* _second;
    ThirdScene* _third;
    FourthScene* _fourth;
	FifthScene* _fifth;
	GameNode* _currentScene;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() : _currentScene(nullptr) {}
	~MainGame() {}
};
/*

QWER키로 시작시 씬 전환이 가능합니다

스페이스로 대사를 넘깁니다.

*/