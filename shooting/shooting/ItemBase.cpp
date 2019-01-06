#include"ItemBase.hpp"

ItemBase::ItemBase() {
	x, y, gra = 0;
	pl_up = false;
}

ItemBase::~ItemBase(){
	DeleteGraph(gra);
}

void ItemBase::update(player* pl) {
	if (pl->get_point(x));
}

void ItemBase::draw() {

}

void ItemBase::onColl() {

}