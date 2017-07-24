#pragma once
#include "Box.h"
class Game
{
public:
	Game(int pa,int di);
	~Game();
	Box *box;
	Box *nextBox;

private:
	int pattern;
	int difficu;
	static const int CANVAS_WIDTH = 9;
	static const int CANVAS_HEIGHT = 20;
	int bigCanvas[20][9];
	int smallCanvas[4][4];
	void PaintBigCanvas();
	void PaintSmallCanvas();
	void start();
	BOOL can
};

