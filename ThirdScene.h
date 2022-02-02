#pragma once
#include "GameNode.h"

class ThirdScene :public GameNode
{
private:
	RECT _moveBox[3];
	string _playerName;
	int _alphaA;
	float _alpha;
	float _bgAlpha;
	float _bgSpeed;
	bool _isStart;
	bool _moveFourth;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	bool getMoveFourth(void);

	ThirdScene() {}
	~ThirdScene() {}
};
