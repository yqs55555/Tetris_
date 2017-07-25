// GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "AchieveDlg.h"
#include "afxdialogex.h"
#include "ChooseDlg.h"
#include "GameDlg.h"
#include "Game.h"

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

// CGameDlg 对话框

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_GAME, pParent)
{
}

CGameDlg::~CGameDlg()
{

}

BOOL CGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CChooseDlg *cDlg = (CChooseDlg *)GetParent();
	InitInfo(cDlg->pattern, cDlg->difficu);
	game = new Game(cDlg->pattern, cDlg->difficu);
	game->start();
	SetTimer(1, 500, NULL);

	return TRUE;
}
void CGameDlg::InitInfo(int pattern,int difficu)
{
	switch (pattern)
	{
	case 0:
		SetDlgItemText(IDC_STATIC_GAMEPATTERN, L"经典模式");
		break;
	case 1:
		SetDlgItemText(IDC_STATIC_GAMEPATTERN, L"残局模式");
		break;
	case 2:
		SetDlgItemText(IDC_STATIC_GAMEPATTERN, L"随机变速模式");
		break;
	}
	CString dif;
	dif.Format(_T("%d"),difficu);
	SetDlgItemText(IDC_STATIC_GAMEDIFFICU, dif);
}
void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GAMERETURN, &CGameDlg::OnBnClickedButtonGamereturn)
	ON_BN_CLICKED(IDC_BUTTON_GAMERESTART, &CGameDlg::OnBnClickedButtonGamerestart)
	ON_BN_CLICKED(IDC_BUTTON_GAMESTOPORCONTI, &CGameDlg::OnBnClickedButtonGamestoporconti)
	ON_WM_PAINT()
	ON_WM_TIMER() // 映射添加消息
END_MESSAGE_MAP()


// CGameDlg 消息处理程序


void CGameDlg::OnBnClickedButtonGamereturn()
{
	ShowMain();
	GetParent()->SendMessage(WM_CLOSE);
	this->SendMessage(WM_CLOSE);

	// TODO: 在此添加控件通知处理程序代码
}

BOOL CGameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		if (KEY_DOWN('H'))
		{
			CTetrisDlg* main = (CTetrisDlg*)GetTopLevelParent();
			main->Help();
		}
		if (KEY_DOWN(VK_UP))
		{
			if (game->CanRoll())
				game->Roll();
		}
		if (KEY_DOWN(VK_LEFT))
		{
			if (game->CanMoveLeft())
				game->MoveLeft();
		}
		if (KEY_DOWN(VK_RIGHT))
		{
			if (game->CanMoveRight())
				game->MoveRight();
		}
		if (KEY_DOWN(VK_DOWN))
		{
			if (game->CanMoveDown())
				game->MoveDown();
		}
		Invalidate(true);// 重绘画面
	}
	return false;
}

void CGameDlg::ShowMain()//显示主窗口
{
	CWnd* main = GetParent()->GetParent();
	main->ShowWindow(SW_SHOW);
}

void CGameDlg::OnCancel()//直接按下右上关闭键时
{
	ShowMain();
	GetParent()->SendMessage(WM_CLOSE);
	CDialogEx::OnCancel();
}


void CGameDlg::OnBnClickedButtonGamerestart()
{
	delete game;//销毁此游戏
	CChooseDlg *cDlg = (CChooseDlg *)GetParent();
	InitInfo(cDlg->pattern, cDlg->difficu);
	game = new Game(cDlg->pattern, cDlg->difficu);//创建新的一局游戏
	Invalidate(true);// 重绘画面
	game->start();
	
	// TODO: 在此添加控件通知处理程序代码
}

void CGameDlg::OnPaint()
{
	CDialog::OnPaint();
	PaintBigCanvas();
	PaintSmallCanvas();
#if 0 
		CDialogEx::OnPaint();
		CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
		CDC *MemDC;
		MemDC = wnd->GetDC();
		MemDC->SetBkColor(RGB(0, 255, 255));
		CBrush brushMap;//这里要特别注意，虽然两次是不同的颜色，但是要分别载入画刷
		brushMap.CreateSolidBrush(RGB(0, 255, 255));
		MemDC->SelectObject(&brushMap);
		MemDC->Rectangle(CRect(0, 0, 100, 100));
#endif
}

void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(game->CanMoveDown())
		game->MoveDown();
	else
	{
		game->DeleteLines();
		if (game->IsDead())
			game->isRun = false;
		else
		{
			srand((unsigned int)time(nullptr));
			delete game->box;
			game->box = game->nextBox;
			game->nextBox = new Box(rand() % 7 + 1);
		}
	}
	if (!game->isRun)
	{
		KillTimer(1);
		TCHAR *msg = _T("Game Over!");
		MessageBox(msg);
	}
	Invalidate(true);// 重绘画面
}
void CGameDlg::OnBnClickedButtonGamestoporconti()
{
	game->PauseOrContinue();
	if(!game->isRun)
		KillTimer(1);
	if (game->isRun)
		SetTimer(1, 500, nullptr);
	// TODO: 在此添加控件通知处理程序代码
}

void CGameDlg::PaintBigCanvas()
{
	CRect rect;

	CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
	CDC *MemDC;
	MemDC = wnd->GetDC();
	CBrush brushMap;//这里要特别注意，虽然两次是不同的颜色，但是要分别载入画刷
	brushMap.CreateSolidBrush(RGB(0, 255, 255));
	MemDC->SelectObject(&brushMap);
	wnd->GetClientRect(&rect);

	game->AddBox();
	for (int i = 0; i<game->CANVAS_HEIGHT; i++)
		for (int j = 0; j<game->CANVAS_WIDTH; j++)
			if (game->bigCanvas[i][j] == 1)
			{
				MemDC->Rectangle(
					j*rect.Width() / game->CANVAS_WIDTH,
					i*rect.Height() / game->CANVAS_HEIGHT,
					(j + 1)*rect.Width() / game->CANVAS_WIDTH,
					(i + 1)*rect.Height() / game->CANVAS_HEIGHT);
				if(game->CanMoveDown())
					game->bigCanvas[i][j] = 0;
			}

}

void CGameDlg::PaintSmallCanvas()
{
	CRect rect;

	CWnd *wnd = GetDlgItem(IDC_PIC_SMALL);
	CDC *MemDC;
	MemDC = wnd->GetDC();
	CBrush brushMap;//这里要特别注意，虽然两次是不同的颜色，但是要分别载入画刷
	brushMap.CreateSolidBrush(RGB(0, 255, 255));
	MemDC->SelectObject(&brushMap);

	wnd->GetClientRect(&rect);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			game->smallCanvas[i][j] = game->nextBox->_data[i][j];

	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			if(game->smallCanvas[j][i] == 1)
				MemDC->Rectangle(
					j*rect.Width() / 4,
					i*rect.Height() / 4,
					(j + 1)*rect.Width() / 4,
					(i + 1)*rect.Height() / 4);
}