#include"PoseScene.hpp"

PoseScene::PoseScene() {
	initialize();
	state = 0;
	gra[0] = LoadGraph("img/UI/pose_win0.png");
	gra[1] = LoadGraph("img/UI/pose_win1.png");
	pose_now = true;
}

PoseScene::~PoseScene() {
	DeleteGraph(gra[0]);
	DeleteGraph(gra[1]);
}

void PoseScene::update() {
	switch (state) {
	case 0:
		if (CheckHitKey(KEY_INPUT_Z))pose_now = false;
		//if (CheckHitKey(KEY_INPUT_UP))state = 1;
		if (CheckHitKey(KEY_INPUT_DOWN))state = 1;
		break;
	case 1:
		if (CheckHitKey(KEY_INPUT_Z))pose_now = false;
		if (CheckHitKey(KEY_INPUT_UP))state = 0;
		//if (CheckHitKey(KEY_INPUT_DOWN))state = 0;
		break;
	default:
		DebugBreak();
		break;
	}
}

void PoseScene::draw() { DrawGraph(300,300,gra[state],TRUE); }
