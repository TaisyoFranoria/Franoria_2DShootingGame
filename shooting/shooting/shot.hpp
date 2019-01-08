#pragma once
#include<Dxlib.h>
#include"EnemyBase.hpp";
#include"EfectBase.hpp";
#define PI    (3.1415926535897932384626433832795f)
class shot {
public:
	shot();
	virtual ~shot();
	virtual void shoot(int x,int y);
	virtual void update();
	virtual void enemy_coll(EnemyBase* ene,EfectBase* efk);
	virtual void draw();
	virtual void onColl();
	virtual void onColl(EnemyBase* ene,EfectBase* efk);
	bool alive;
protected:
	
	int x, y;
	int r;
	int gra;
};