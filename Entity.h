#ifndef ENTITY_H
#define ENTITY_H

#include "ofMain.h"
#include "Utils.h"

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

class Entity {		


public:
	Entity();
	~Entity();

	virtual void init(int x, int y);

	virtual void update();
	virtual void render();

	void setCollisionMap(std::vector<std::vector<bool>>* colmap, int w, int h);
	
	C_Rectangle getRect() { return mpRect; };

	int collidesWithEntity(Entity* ent);

	virtual GameClasses getClass() { return ENTITY; };

	bool isAlive() { return mpAlive; }
	void setAlive(bool alive);

protected:
	C_Rectangle mpRect; // Collision and position

	virtual Direction getNextDirection();
	void updateControls();
	void move();
	bool checkCollisionWithMap();


	std::vector < std::vector<bool>>* mpColMap;
	int mMapHeight;
	int mMapWidth;

	bool mpMoving; //saber si estoy llegando al sito o ya me puedo volver a mover
	int mpSpeed; //velocidad que tengo
	int mpDirection; //saber la direccion que tengo //al crear esto hemso creado los enumeradores, quizas estan relacionados con que se tengan que usar aqui

	int mpXtoGo; //saber donde voy
	int mpYtoGo;

	bool mpAlive;

};





#endif
