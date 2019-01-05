#include"game_scene.hpp"

class Game {
public:
	Game();
	~Game();	
	bool alive;
	void all();
private:
	scene* sc;
	void initialize();
	void finalize();
	void update();
	void draw();
	void update_late();
};