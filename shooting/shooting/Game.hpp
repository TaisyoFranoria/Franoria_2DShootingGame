//#include"game_scene.hpp"
#include"debug_zone.hpp"
#include"PoseScene.hpp"

#define GAME_TITLE (0xFFFFFFFFF1)
#define GAME_MAIN (0xFFFFFFFFFF2)
#define GAME_POSE (0xFFFFFFFFFF3)


class Game {
public:
	Game();
	~Game();	
	bool alive;
	void all();
private:
	std::vector<scene*> sc;
	void initialize();
	void finalize();
	void update();
	void draw();
	void update_late();

	int scene_num;
	int state;
};