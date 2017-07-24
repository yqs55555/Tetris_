#include "stdafx.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "AchieveDlg.h"
#include "afxdialogex.h"
#include "ChooseDlg.h"
#include "Game.h"

Game::Game(int pa,int di)
	:pattern(pa),difficu(di)
{
	memset(bigCanvas, 0, sizeof(bigCanvas));
	memset(smallCanvas, 0, sizeof(smallCanvas));
	srand(time(NULL));
	box = new Box(rand() % 7 + 1);
	srand(difficu);
	nextBox = new Box(rand() % 7 + 1);
}


Game::~Game()
{
}

void Game::PaintBigCanvas()
{
}

void Game::PaintSmallCanvas()
{
}

void Game::start()
{

}

