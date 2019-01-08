#pragma once
#include"shot.hpp"
#include"shikimi_shotEfects.hpp"

class shikimi_shot:public shot {
public :
	shikimi_shot();
	~shikimi_shot();
	void update();

	void onColl();
};