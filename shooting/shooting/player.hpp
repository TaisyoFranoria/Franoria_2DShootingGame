#pragma once
#include<Dxlib.h>
#include<string>

#define PLAYER_SIZE (84)
#define PLAYER_RADIUS (42)

class player {
private:
	int x, y;
	int hx, hy;//判定のための座標位置(中心)
	int r; //判定の半径
	int gra[3];
	int move_num;//1:左に移動 2:デフォルト 3:右に移動
	int anim_counter;
	struct status{
		int LIFE;
		int BOMB;
		int POWER;
		int COUNTINUE;
	}status;
	bool slow;
	bool shot;
	bool bomb_now;
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
	bool get_now(int num);
	void set_status(int num,int value);
	void set_point(int x,int y);
	int InitLoadGraph(int num);
};