#pragma once
#include<Dxlib.h>


class InputManager {
public:
	InputManager();
	~InputManager();
	int checkinput();
private:
	void initialize();
	void finalize();

};