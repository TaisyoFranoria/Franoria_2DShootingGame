#pragma once
#include"EnemyBase.hpp"

class Unknown : public EnemyBase {
public :
	Unknown();
	~Unknown();
	void update();
	void draw();
	void spawn(int x,int y);
};