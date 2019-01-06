#pragma once
#include"shot.hpp"

shot::shot() {
	x, y, gra = 0;
	alive = false;
}

shot::~shot() {
	DeleteGraph(gra);
}

void shot::shoot(int x,int y) {
	alive = true;
	this->x = x;
	this->y = y;
}

void shot::update() {

}

void shot::draw() {
	if(alive) DrawRotaGraph(x,y,1.5,PI*2,gra,TRUE);
}

void shot::onColl() {

}