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
	BOOL UpdateDifficu(int tmpLines);//�����Ѷ�
	void SetDeathNum(int num);
	Box *box;
	Box *nextBox;
	int deathNum;
	static const int CANVAS_WIDTH = 9;
	static const int CANVAS_HEIGHT = 20;
	int bigCanvas[20][9];//�洢��ֹ����Ļ���
	int smallCanvas[4][4];//С����
	int canvas[20][9];//����ӡ�Ļ���
	int totalLines;//������Ϸ����������
	long scores;//������Ϸ�÷�
	int difficu;//�Ѷ�
	int baseSpeed;//���������ٶ�
	int pattern;//��Ϸģʽ
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

