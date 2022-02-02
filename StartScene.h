#pragma once
#include "GameNode.h"

class StartScene :public GameNode
{
private:
	RECT _moveBox[3];
	string _playerName;
	int _alphaA;
	float _alpha;
	float _bgAlpha;
	float _bgSpeed;
	bool _isStart;
	bool _moveSecond;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	bool getMoveSecond(void);

	StartScene() {}
	~StartScene() {}
};