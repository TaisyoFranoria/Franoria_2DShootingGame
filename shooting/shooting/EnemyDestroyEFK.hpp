#pragma once
#include"EfectBase.hpp"

class EnemyDestroyEFK : public EfectBase {
public :
	EnemyDestroyEFK();
	~EnemyDestroyEFK();
	void update();
private:
	int edefk_count;
};