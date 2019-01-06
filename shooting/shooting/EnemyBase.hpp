#pragma once
#include<Dxlib.h>

class EnemyBase {
public:
	EnemyBase();
	virtual ~EnemyBase();
	virtual void update();
	virtual void draw();
	virtual bool get_Enemystatus();
protected:
	int x, y;
	int gra;
	bool alive;
	bool shot;
};

