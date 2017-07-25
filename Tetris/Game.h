#pragma once
#include "Box.h"
class Game : public CWnd
{
public:
	Game(int pa,int di);
	~Game();
	void start();
	void PauseOrContinue();
	BOOL Crash(int x, int y);
	Box *box;
	Box *nextBox;
	static const int CANVAS_WIDTH = 9;
	static const int CANVAS_HEIGHT = 20;
public:
	BOOL CanMoveDown();
	BOOL CanMoveLeft();
	BOOL CanMoveRight();
	BOOL CanRoll();
	void Roll();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	BOOL isRun = TRUE;

private:
	int pattern;
	int difficu;
	static const int RECT_SIZE = 30;
	int bigCanvas[20][10];
	int smallCanvas[4][4];
	int DeleteLines();
	void DeleteLine(int index);
	BOOL CanDeleteLine(int index);
	void CalScore(int line);
	void AddBox();
	BOOL GameOver();
};

