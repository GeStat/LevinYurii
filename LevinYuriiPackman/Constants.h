#pragma once
#include <Windows.h>

const int FIELD_HEIGHT = 32;
const int FIELD_WIDTH = 18;
//const char NO_COLLISION_TILES[3] = { ' ','o','\xfa' };
const int GATE_X = 13;
const int GATE_Y = 12;

const char ALL_BUTTONS[4] = { 'w','a','s','d' };
const char PACKMAN_ICONS[4] = { 'v','>','^','<' };
const char GHOST_ICON = 'M';
const char DEAD_GHOST_ICON = '"';
const char NO_COLLISION_TILES[3] = { ' ','o','\xfa' };

const int WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
const int BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int DARK_BLUE = FOREGROUND_BLUE;
const int CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
const int YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int BLACK = 0;

const int SUPER_MAX = 500;
const int ONE_UP_MAX = 13;
const int PELLET_MAX = 8;
const int PACMAN_MAX = 8;
const int GHOST_MAX = 10;
const int RUN_MAX = 16;
const int DEAD_MAX = 3;
const int MODE_MAX = 1000;

const int BLINKY = 0;
const int PINKY = 1;
const int INKY = 2;
const int CLYDE = 3;
