#include "Ghost.h"

Ghost::Ghost() : Entity() {


}

Ghost::~Ghost() {

}

void Ghost::render() {
	ofSetColor(255, 0, 0);
	Entity::render();
}

Direction Ghost::getNextDirection() {
	Direction dir = (Direction)(rand() % 4 + 1);
	return dir;
}