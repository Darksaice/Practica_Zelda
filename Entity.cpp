#include"Entity.h"


Entity::Entity() {
	mpRect = C_Rectangle{ 0,0,TILE_SIZE,TILE_SIZE };
	mMapHeight = 0;
	mMapWidth = 0;

	mpMoving = false;
	mpSpeed = 200;
	mpDirection = NONE;

	mpXtoGo = 0;
	mpYtoGo = 0;

	mpAlive = true;

}

Entity::~Entity() {



}

void Entity::init(int x, int y) {
	mpRect.x = x;
	mpRect.y = y;
	mpXtoGo = x;
	mpYtoGo = y;

}

void Entity::update() {
	updateControls();
	if (!checkCollisionWithMap()) {
		move();
	}
	else {
		mpMoving = false;
	}

}
void Entity::render() {
	ofDrawRectangle(mpRect.x, mpRect.y, mpRect.w, mpRect.h);
}

void Entity::setCollisionMap(std::vector<std::vector<bool>>* colmap, int w, int h) {
	mpColMap = colmap;
	mMapHeight = h;
	mMapWidth = w;

}

void Entity::updateControls()
{
	if (!mpMoving) {
		mpDirection = NONE;//eso es para que si no se esta moviendo se uqede quieto
		mpXtoGo = mpRect.x;//eso es para que si no se esta moviendo se uqede quieto
		mpYtoGo = mpRect.y; //eso es para que si no se esta moviendo se uqede quieto
		mpDirection = getNextDirection();

		if (mpDirection != NONE) {
			mpMoving = true;
		}
		switch (mpDirection) { //segun donde me tenga que mover la direccion objetivo cambiara
		default:break;
		case UP:
			mpYtoGo -= TILE_SIZE;
			break;
		case DOWN:
			mpYtoGo += TILE_SIZE;
			break;
		case LEFT:
			mpXtoGo -= TILE_SIZE;
			break;
		case RIGHT:
			mpXtoGo += TILE_SIZE;
			break;
		}
	}
}

void Entity::move()
{
	int xx = mpRect.x; //es la posicion en la que estamos ahora sin ahcer ningun movimiento
	int yy = mpRect.y;
	if (xx < mpXtoGo) {
		xx = xx + mpSpeed * global_delta_time / 1000;
	}
	else if (xx > mpXtoGo) {
		xx = xx - mpSpeed * global_delta_time / 1000;
	}
	if (yy < mpYtoGo) {
		yy = yy + mpSpeed * global_delta_time / 1000;
	}
	else if (yy > mpYtoGo) {
		yy = yy - mpSpeed * global_delta_time / 1000;
	}

	if ((mpRect.x < mpXtoGo && xx > mpXtoGo) || (mpRect.x > mpXtoGo && xx < mpXtoGo)) {
		xx = mpXtoGo;
	}
	if ((mpRect.y < mpYtoGo && yy > mpYtoGo) || (mpRect.y > mpYtoGo && yy < mpYtoGo)) {
		yy = mpYtoGo;
	}

	mpRect.x = xx;
	mpRect.y = yy;

	if (mpRect.x == mpXtoGo && mpRect.y == mpYtoGo) {
		mpMoving = false;
	}
}

bool Entity::checkCollisionWithMap()
{
	if (mpDirection == NONE) { return false; } //si no se esta moviendo no hace falta mirar la collision

	int checkX = mpXtoGo / TILE_SIZE;
	int checkY = mpYtoGo / TILE_SIZE;

	if (checkX < 0 || checkX >= mMapWidth || checkY < 0 || checkY >= mMapHeight) { //esto es para que no me salga del mapa
		return true;
	}

	return (*mpColMap)[checkY][checkX];
}

Direction Entity::getNextDirection() {
	return NONE;
}

void Entity::setAlive(bool alive)
{
	mpAlive = alive;
}

int Entity::collidesWithEntity(Entity* ent) {
	C_Rectangle rectEnt = ent->getRect();
	if (C_RectangleCollision(mpRect, rectEnt)) {
			//Mirar de qué tipo es 'ent'
		return ent->getClass();
	}
	else {
		return NOTHING;
	}
}
