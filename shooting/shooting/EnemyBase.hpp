#pragma once
#include<Dxlib.h>
#include<vector>
#include<string>
#include"EfectBase.hpp"

#define PI    (3.1415926535897932384626433832795f)


class EnemyBase {
public:
	EnemyBase();
	virtual ~EnemyBase();
	virtual void update() = 0;
	virtual void update(EfectBase* efk)=0;
	virtual void draw() = 0;
	virtual int get_EnemyValue(int num);
	virtual bool get_EnemyStatus(int num);
	virtual void Damage(int value);
protected:
	int x, y;
	std::vector<int> gra;
	int sound_handle;
	int anim_length;
	int animState;
	bool alive;
	bool shot;
	int hp, atk;
	int r;

	int count;

	void InitGraph(std::string file);
	void destroy();
	void destroy(EfectBase* efk);
};

