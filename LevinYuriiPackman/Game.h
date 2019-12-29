#pragma once

#include "Packman.h"
#include "Constants.h"
#include "Ghost.h"
#include "Pellet.h"

class Game
{
public:
	Game();
	~Game();

	void start();
	void startLoop();
	void loadField();

	char getField(int y, int x);
	void eatPellet(int y, int x, char c);


private:
	char field_[FIELD_HEIGHT][FIELD_WIDTH];
	Packman* packman;
	Ghost* ghost[4];
	Pellet* pellet[4];

};