#include<Dxlib.h>
#include<iostream>
#include"Game.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("•Œ¶‚Ìƒtƒ‰ƒmƒŠƒA");
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Game* GAME = new Game();

	while (ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()) {
		GAME->all();
		if (!GAME->alive)break;
	}

	delete GAME;

	DxLib_End();
	return 0;
}