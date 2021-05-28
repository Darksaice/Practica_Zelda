#ifndef GHOST_H

#define GHOST_H

#include "ofMain.h"
#include "Utils.h"
#include "Entity.h"

enum GState {NO, NOEAT, EAT};

class Ghost : public Entity {	//fantasmas  mezclar puntos con pacman moverse como pacman, colision como puntos tiene que morir si tiene el super coco
					//se moveran con una direcion aleatoria
					// random en movimiento pacman donde pone WASD que se moveran arriba abajo izquierda derecha
					//en el scene.cpp en update el fantasma ponmos que si el pacman se enfrenta con ellos se muere o se los come
public:
	Ghost();
	~Ghost();

	void render();

	virtual GameClasses getClass() { return GHOST; };

protected:
	Direction getNextDirection();
};

#endif
