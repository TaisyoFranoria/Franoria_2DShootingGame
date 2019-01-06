#pragma once
#include<Dxlib.h>
#define PI    (3.1415926535897932384626433832795f)
class shot {
public:
	shot();
	virtual ~shot();
	virtual void shoot(int x,int y);
	virtual void update();
	virtual void draw();
	virtual void onColl();
	bool alive;
protected:
	
	int x, y;
	int gra;
};