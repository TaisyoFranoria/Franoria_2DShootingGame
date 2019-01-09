#pragma once
#include"EnemyBase.hpp"

class Unknown_ : public EnemyBase {
public :
	Unknown_();
	Unknown_(int x,int y,int hp,int atk);
	~Unknown_();
	void update();
	void draw();
	void spawn(int x,int y);
	void respawn(int x,int y);
private:
	int move_lange;
	int pt;
};