#pragma once
#include<DxLib.h>
#include<vector>
#include<string>

class Talk {
private:
	std::vector<int> char1_gra; //会話するキャラのグラフィック
	std::vector<int> chae2_gra;
	int TW_gra; //ウィンドウのグラフィックハンドル
	int page;//頁
	std::vector<std::string> talk_text;
public:
	Talk();
	~Talk();

};
