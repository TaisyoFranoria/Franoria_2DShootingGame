#pragma once
#include<Dxlib.h>
#include<vector>
#include<string>

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
	bool alive;
	bool shot;
	int hp, atk;

	void InitGraph(std::string file);
};

