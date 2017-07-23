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
}


Game::~Game()
{
}

