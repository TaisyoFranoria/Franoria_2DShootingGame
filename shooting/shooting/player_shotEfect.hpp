#pragma once
#include"EfectBase.hpp"

class player_shotefect : public EfectBase {
public:
	player_shotefect();
	virtual ~player_shotefect();
	void update();
};