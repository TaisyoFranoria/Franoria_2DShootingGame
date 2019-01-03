#pragma once
#include<Dxlib.h>
#include<string>

class player {
private:
	int x, y;
	int gra[3];
	int move_num;//1:左に移動 2:デフォルト 3:右に移動
	int anim_counter;
	struct status{
		int LIFE;
		int BOMB;
		int COUNTINUE;
	}status;

	int DrawPlayerGraph(int num);
public:
	player();
	~player();
	void initialize();

	void finalize();

	void update();
	void draw();
	void update_late();

	int get_point(int num);
	int get_status(int num);
	int InitLoadGraph(int num);
};