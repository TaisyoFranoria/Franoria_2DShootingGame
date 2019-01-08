#pragma once
#include<Dxlib.h>
#include<vector>
#include<string>

#define PI    (3.1415926535897932384626433832795f)


class EnemyBase {
public:
	EnemyBase();
	virtual ~EnemyBase();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual int get_EnemyValue(int num);
	virtual bool get_EnemyStatus(int num);
	virtual void Damage(int value);
protected:
	int x, y;
	std::vector<int> gra;
	int anim_length;
	int animState;
	bool alive;
	bool shot;
	int hp, atk;
	int r;

	void InitGraph(std::string file);
};

