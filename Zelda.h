#ifndef ZELDA_H
#define ZELDA_H

#include "ofMain.h"
#include "Utils.h"
#include "Entity.h"

class Zelda : public Entity {		//poner funcion de setstate que cuando le toque el punto gordo a el pacman se vuevla immortal
									//crear enumerador con el estado del pacman para la funcion setstate

public:
	Zelda();
	~Zelda();

	void update();
	void render();

	void setState();


	virtual GameClasses getClass() { return ZELDA; };

protected:

	Direction getNextDirection();

	void updateInmortal(); //esta funcion se tiene que llamar desde el update que hemos puesta arriba

	int mpInmortalTime;
	bool mpInmortal;

};



#endif
