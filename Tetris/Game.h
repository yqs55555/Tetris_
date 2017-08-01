#pragma once
#include "Box.h"
class Game : public CWnd
{
public:
	Game(int pa, int di);
	~Game();
	void start();
	void PauseOrContinue();
	BOOL IsDead();
	int DeleteLines();
	void CalScore(int line);
	BOOL UpdateDifficu(int tmpLines);//更新难度
	void SetDeathNum(int num);
	Box *box;
	Box *nextBox;
	int deathNum;
	static const int CANVAS_WIDTH = 9;
	static const int CANVAS_HEIGHT = 20;
	int bigCanvas[20][9];//存储静止方块的画布
	int smallCanvas[4][4];//小画布
	int canvas[20][9];//被打印的画布
	int totalLines;//本局游戏总消除行数
	long scores;//本局游戏得分
	int difficu;//难度
	int baseSpeed;//基础下落速度
	int pattern;//游戏模式
	int randSpeedCount;
public:
	BOOL CanMoveDown();
	BOOL CanMoveLeft();
	BOOL CanMoveRight();
	BOOL CanRoll();
	void Roll();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void AddBox(int choose);//
	BOOL isRun = TRUE;
	BOOL end;

private:
	static const int RECT_SIZE = 30;
	void DeleteLine(int index);
	BOOL CanDeleteLine(int index);
	int& GetDeathNum();
};

