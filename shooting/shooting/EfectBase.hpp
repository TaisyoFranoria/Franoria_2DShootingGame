#pragma once
#include <Dxlib.h>
#include <Vector>
#include <string>

#define PI    (3.1415926535897932384626433832795f)

class EfectBase {
public:
	EfectBase();
	virtual ~EfectBase();
	virtual void update();
	void draw();
	void spawn(int x,int y);

	bool alive;
protected:
	int x;
	int y;
	std::vector<int> gra;
	int anim_length;
	int anim_State;

	void update_abs();
	void InitGraph(std::string filepath);
};
