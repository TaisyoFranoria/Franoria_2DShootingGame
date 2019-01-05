//#include"game_scene.hpp"
#include"debug_zone.hpp"

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
};