#ifndef SMALLDOT_H

#define SMALLDOT_H

#include "ofMain.h"
#include "Utils.h"
#include "Entity.h"

class SmallDot : public Entity {

public: 
	SmallDot();
	~SmallDot();

	
	void init(int x, int y);
	void render();

	virtual GameClasses getClass() { return SMALLDOT; }; //tendremos que hacer esto con el bigdot

	protected:
		


};

#endif
