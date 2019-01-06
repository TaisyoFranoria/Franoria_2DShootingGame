#pragma once
#include"ItemBase.hpp"

class atkup :public ItemBase {
public :
	atkup();
	~atkup();
	void onColl(player* pl);
};