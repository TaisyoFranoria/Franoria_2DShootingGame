#include"game_scene.hpp"

GameScene::GameScene() {
	initialize();
}

GameScene::~GameScene() {
	finalize();
}

void GameScene::initialize() {
	time = 0;
	//あとで変更
	x = 0;
	y = 0;

	pl = new player();
	for (int i = 0; i < 8; i++)p_efk.push_back(new shikimi_shotEfects());//0~8　プレイヤーのショット
	pefk_count = 0;
	pefk_length = (unsigned)p_efk.size();

	for (int i = 0; i < 150; i++)ed_efk.push_back(new EnemyDestroyEFK());
	edefk_count = 0;
	edefk_length = (unsigned)ed_efk.size();
	
	for (int i = 0; i < 100; i++)enm.push_back(new Unknown_());
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++)pl_Bull[i] = new shikimi_shot();
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)Item[i] = new atkup();
	bullet_count = 0;
	UI = new UI_gamescene(pl);
	bg = new BackGraph();

	phase = 0;
	phase_frame = 0;
	stage_title[0] = LoadGraph("img/Back/stage_debug/stage_name_dummy.png");
	stage_title[1] = LoadGraph("img/Back/stage_debug/cloud.png");

	pose_now = false;
}

void GameScene::finalize() {
	delete pl;
	for (int i = 0, n = (unsigned)p_efk.size(); i < n; i++)delete p_efk[i];
	for (int i = 0, n = (unsigned)enm.size(); i < n;i++)delete enm[i];
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++)delete pl_Bull[i];
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)delete Item[i];
	delete UI;
	delete bg;
}

void GameScene::update() {
	update_abs();
}

void GameScene::update_abs() {
	for (int i = 0, n = (unsigned)enm.size(); i < n; i++) { 
		enm[i]->update(ed_efk[edefk_count]);
		edefk_count++;
		if (edefk_count >= edefk_length)edefk_count = 0;
	}
	pl->update();
	if (time%3==0&&pl->get_now(1)&&!pl->get_now(2))shot_emit(pl->get_point(0), pl->get_point(1), pl->get_status(2), pl->get_now(0));
	if (pl->get_now(2))clear_enemy();
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)Item[i]->update(pl);
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++) {
		pl_Bull[i]->update();
		for (int j = 0, n2 = (unsigned)enm.size(); j < n2; j++)if (pl_Bull[i]->alive) { 
			pl_Bull[i]->enemy_coll(enm[j], p_efk[pefk_count]); 
			pefk_count++; 
			if (pefk_count >= pefk_length)pefk_count = 0; 
		}
	}
	for (int i = 0, n = (unsigned)(p_efk.size()); i < n; i++)p_efk[i]->update();
	for (int i = 0, n = (unsigned)(ed_efk.size()); i < n; i++)ed_efk[i]->update();
	if (bullet_count >= ((unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0]) - 5)))bullet_count = 0;

	if (CheckHitKey(KEY_INPUT_Q))pose_now = true;
}

void GameScene::draw() {
	draw_abs();
}

void GameScene::draw_abs() {
	for (int i = 0, n = (unsigned)enm.size(); i < n; i++)enm[i]->draw();
	for (int i = 0, n = (unsigned)(sizeof(Item) / sizeof(Item[0])); i < n; i++)Item[i]->draw();
	pl->draw();
	for (int i = 0, n = (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])); i < n; i++) pl_Bull[i]->draw();
	for (int i = 0, n = (unsigned)p_efk.size(); i < n; i++)p_efk[i]->draw();
	for (int i = 0, n = (unsigned)ed_efk.size(); i < n; i++)ed_efk[i]->draw();
}

void GameScene::update_late() {
	pl->update_late();
	if (pl->get_status(0) <= 0) alive = false;

	//ゲームゾーンから出ないための処理
	if (pl->get_point(0) > GAME_WIDTH-64) pl->set_point(GAME_WIDTH-64, pl->get_point(1));
	if (pl->get_point(1) > GAME_HIGHT-64) pl->set_point(pl->get_point(0), GAME_HIGHT-64);
	if (pl->get_point(0) < 0)pl->set_point(0, pl->get_point(1));
	if (pl->get_point(1) < 0)pl->set_point(pl->get_point(0), 0);

	if (bullet_count >= (unsigned)(sizeof(pl_Bull) / sizeof(pl_Bull[0])))bullet_count = 0;
	if (Itemcount >= ((unsigned)(sizeof(Item) / sizeof(Item[0]))-10))Itemcount = 0;
	update_ALT();
}

void GameScene::shot_emit(int x, int y,int pw,bool slow) {
	if (pw > 95) {
		if (slow) {
			pl_Bull[bullet_count]->shoot(x + 40, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 35, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 45, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 30, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 50, y); bullet_count++;
		}
		else {
			pl_Bull[bullet_count]->shoot(x + 40, y - 10); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 30, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 50, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 10, y + 10); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 70, y + 10); bullet_count++;
		}
	}
	else if (pw > 80) {
		if (slow) {
			pl_Bull[bullet_count]->shoot(x + 35, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 45, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 30, y); bullet_count++;
			pl_Bull[bullet_count]->shoot(x + 50, y); bullet_count++;
		}
		else { 
		pl_Bull[bullet_count]->shoot(x + 30, y); bullet_count++; 
		pl_Bull[bullet_count]->shoot(x + 50, y ); bullet_count++;
		pl_Bull[bullet_count]->shoot(x + 10, y + 10); bullet_count++;
		pl_Bull[bullet_count]->shoot(x + 70, y + 10); bullet_count++;
		}
	}
	else if (pw > 60) {
		if (slow) { pl_Bull[bullet_count]->shoot(x + 30, y - 10); bullet_count++; pl_Bull[bullet_count]->shoot(x + 50, y - 10); bullet_count++; pl_Bull[bullet_count]->shoot(x + 40, y); bullet_count++; }
		else { pl_Bull[bullet_count]->shoot(x + 10, y-10);  bullet_count++; pl_Bull[bullet_count]->shoot(x + 70, y-10); bullet_count++; pl_Bull[bullet_count]->shoot(x+40,y); bullet_count++; }
	}
	else if (pw > 30) {
		if (slow) { pl_Bull[bullet_count]->shoot(x + 30, y);  bullet_count++; pl_Bull[bullet_count]->shoot(x + 40, y); bullet_count++; }
		else { pl_Bull[bullet_count]->shoot(x + 20, y); bullet_count++; pl_Bull[bullet_count]->shoot(x + 60, y); bullet_count++; }
	}
	else {
		pl_Bull[bullet_count]->shoot(x+40,y); bullet_count++;
	}
}

int GameScene::get_time() { return time; }

int GameScene::get_xy(int num) {
	if (num == 0)return x;
	else         return y;
}

void GameScene::clear_enemy() {
	for (int i = 0, n = (unsigned)enm.size(); i < n; i++)enm[i]->Damage(9999999999);
}

void GameScene::fadetitle() {
	if (phase_frame < 128) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (phase_frame * 2));
		DrawExtendGraph(50+(phase_frame/4),5,450+(phase_frame/4),155,stage_title[1],TRUE);
		DrawExtendGraph(450 - (phase_frame / 4), 600, 50 - (phase_frame / 4), 750, stage_title[1], TRUE);
		DrawGraph(100, 50, stage_title[0], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else if (phase_frame < 255) {
		DrawExtendGraph(82, 5, 482, 155, stage_title[1], TRUE);
		DrawExtendGraph(418, 600, 18, 750, stage_title[1], TRUE);
		DrawGraph(100, 50, stage_title[0], TRUE);
	}
	else if (phase_frame < 383) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (383 - phase_frame));
		DrawGraph(100, 50, stage_title[0], TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}