#pragma once
#include"game_scene.hpp"

class debug_zone : public GameScene {
public:
	debug_zone();
	~debug_zone();
	void update();
	void draw();
};