// GameDlg.cpp : ʵ���ļ�
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

// CGameDlg �Ի���

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

void CGameDlg::showInfo()
{
	CString dif;
	dif.Format(_T("%d"), game->difficu);
	SetDlgItemText(IDC_STATIC_GAMEDIFFICU, dif);
	CString stringScores;
	stringScores.Format(_T("%d"), game->scores);
	SetDlgItemText(IDC_STATIC_GAMESCORE, stringScores);
}

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
	SetTimer(1, game->baseSpeed - 100 * game->difficu, nullptr);

	return TRUE;
}
void CGameDlg::InitInfo(int pattern, int difficu)
{
	switch (pattern)
	{
	case 0:
		SetDlgItemText(IDC_STATIC_GAMEPATTERN, L"����ģʽ");
		break;
	case 1:
		SetDlgItemText(IDC_STATIC_GAMEPATTERN, L"�о�ģʽ");
		break;
	case 2:
		SetDlgItemText(IDC_STATIC_GAMEPATTERN, L"�������ģʽ");
		break;
	}
	CString dif;
	dif.Format(_T("%d"), difficu);
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
	ON_WM_TIMER() // ӳ�������Ϣ
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������


void CGameDlg::OnBnClickedButtonGamereturn()
{
	if (MessageBoxA(nullptr, "�Ƿ񷵻������棿", "��ѡ��", MB_OKCANCEL) == IDOK)
	{
		ShowMain();
		GetParent()->SendMessage(WM_CLOSE);
		this->SendMessage(WM_CLOSE);
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

BOOL CGameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
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
		Invalidate(true);// �ػ滭��
	}
	return false;
}

void CGameDlg::ShowMain()//��ʾ������
{
	CWnd* main = GetParent()->GetParent();
	main->ShowWindow(SW_SHOW);
}

void CGameDlg::OnCancel()//ֱ�Ӱ������Ϲرռ�ʱ
{
	delete game;
	ShowMain();
	GetParent()->SendMessage(WM_CLOSE);
	CDialogEx::OnCancel();
}


void CGameDlg::OnBnClickedButtonGamerestart()
{
	Restart();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CGameDlg::Restart()
{
	KillTimer(1);
	delete game;//���ٴ���Ϸ
	CChooseDlg *cDlg = (CChooseDlg *)GetParent();
	InitInfo(cDlg->pattern, cDlg->difficu);
	game = new Game(cDlg->pattern, cDlg->difficu);//�����µ�һ����Ϸ
	Invalidate(true);// �ػ滭��
	game->start();
	showInfo();
	SetTimer(1,game->baseSpeed - 100 * cDlg->difficu , nullptr);
}
void CGameDlg::OnPaint()
{
	CDialog::OnPaint();
	PaintBigCanvas();
	PaintSmallCanvas();
}

void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (game->CanMoveDown())
	{
		game->MoveDown();
		if (game->pattern == 2)
		{
			game->randSpeedCount += (game->baseSpeed - 100*game->difficu);
			if(game->randSpeedCount >= 5000)
			{
				KillTimer(1);
				srand(time(NULL));
				game->difficu = rand() % 9 + 1;
				SetTimer(1, game->baseSpeed - 100 * game->difficu,nullptr);
				showInfo();
				game->randSpeedCount = 0;
			}
		}
	}
	else
	{
		game->AddBox(0);//�Ѹ÷�����뾲ֹ����
		int tmpLines = game->DeleteLines();//������
		game->CalScore(tmpLines);//�������
		CTetrisDlg *tDlg = (CTetrisDlg *)GetTopLevelParent();
		if (game->UpdateDifficu(tmpLines))
		{
			KillTimer(1);
			SetTimer(1, game->baseSpeed - 100 * game->difficu, nullptr);
		}
		GetAchieve(tDlg, tmpLines);
		showInfo();
		if (game->IsDead())//�������
		{
			game->SetDeathNum(++game->deathNum);
			game->isRun = false;
			GetAchieve(tDlg,tmpLines);
			//�ȶ���Ϸ�÷֣��������ϰ�ķ���д�����а��ļ�
			if (game->pattern == 0)//����ģʽ
			{
				if (tDlg->rank->caninsert(tDlg->rank->scorePtn0, game->scores))
				{
					tDlg->rank->insert(tDlg->rank->scorePtn0, game->scores);
					tDlg->rank->textwrite("dataPtn0.txt", tDlg->rank->scorePtn0);
				}
			}
			else if(game->pattern == 1)//�о�ģʽ
			{
				if (tDlg->rank->caninsert(tDlg->rank->scorePtn1, game->scores))
				{
					tDlg->rank->insert(tDlg->rank->scorePtn1, game->scores);
					tDlg->rank->textwrite("dataPtn1.txt", tDlg->rank->scorePtn1);

				}
			}
			else if (game->pattern == 2)//�������ģʽ
			{
				if (tDlg->rank->caninsert(tDlg->rank->scorePtn2, game->scores))
				{
					tDlg->rank->insert(tDlg->rank->scorePtn2, game->scores);
					tDlg->rank->textwrite("dataPtn2.txt", tDlg->rank->scorePtn2);
				}
			}
		}
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
		MessageBoxA(nullptr, "Game Over!", "��ʾ", MB_OK);
		if (MessageBoxA(nullptr, "����һ�֣�", "��ѡ��", MB_OKCANCEL) == IDOK)
		{
			Restart();
		}
		else
		{
			delete game;
			ShowMain();
			GetParent()->SendMessage(WM_CLOSE);
			CDialogEx::OnCancel();
		}
	}
	Invalidate(true);// �ػ滭��
}
void CGameDlg::OnBnClickedButtonGamestoporconti()
{
	game->PauseOrContinue();
	if (!game->isRun)
		KillTimer(1);
	if (game->isRun)
		SetTimer(1, game->baseSpeed - 100*game->difficu, nullptr);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CGameDlg::PaintBigCanvas()
{
	CRect rect;

	CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
	CDC *MemDC;
	MemDC = wnd->GetDC();
	CBrush brushMap;//����Ҫ�ر�ע�⣬��Ȼ�����ǲ�ͬ����ɫ������Ҫ�ֱ����뻭ˢ
	brushMap.CreateSolidBrush(RGB(0, 255, 255));
	MemDC->SelectObject(&brushMap);
	wnd->GetClientRect(&rect);

	game->AddBox(1);
	for (int i = 0; i<game->CANVAS_HEIGHT; i++)
		for (int j = 0; j<game->CANVAS_WIDTH; j++)
			if (game->canvas[i][j] == 1)
			{
				MemDC->Rectangle(
					j*rect.Width() / game->CANVAS_WIDTH,
					i*rect.Height() / game->CANVAS_HEIGHT,
					(j + 1)*rect.Width() / game->CANVAS_WIDTH,
					(i + 1)*rect.Height() / game->CANVAS_HEIGHT);
			}

}

void CGameDlg::PaintSmallCanvas()
{
	CRect rect;

	CWnd *wnd = GetDlgItem(IDC_PIC_SMALL);
	CDC *MemDC;
	MemDC = wnd->GetDC();
	CBrush brushMap;//����Ҫ�ر�ע�⣬��Ȼ�����ǲ�ͬ����ɫ������Ҫ�ֱ����뻭ˢ
	brushMap.CreateSolidBrush(RGB(0, 255, 255));
	MemDC->SelectObject(&brushMap);

	wnd->GetClientRect(&rect);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			game->smallCanvas[i][j] = game->nextBox->_data[i][j];

	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			if (game->smallCanvas[i][j] == 1)
				MemDC->Rectangle(
					j*rect.Width() / 4,
					i*rect.Height() / 4,
					(j + 1)*rect.Width() / 4,
					(i + 1)*rect.Height() / 4);
}

void CGameDlg::GetAchieve(CTetrisDlg *tDlg, int tmpLines)
{
	CString outPut;
	if (!tDlg->achieve->hasgetachieve(0))
		if (game->scores >= 100)
		{
			tDlg->achieve->getnewachive(0);
			outPut = tDlg->achieve->achievename[0];
			SetDlgItemText(IDC_STATIC_GAMEDIFFICU, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(1))
		if (game->scores >= 500)
		{
			tDlg->achieve->getnewachive(1);
			outPut = tDlg->achieve->achievename[1];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(2))
		if (game->scores >= 1000)
		{
			tDlg->achieve->getnewachive(2);
			outPut = tDlg->achieve->achievename[2];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(3))
		if (game->difficu == 9)
		{
			tDlg->achieve->getnewachive(3);
			outPut = tDlg->achieve->achievename[3];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(4))
		if (game->difficu == 9 && game->totalLines >= 10)
		{
			tDlg->achieve->getnewachive(4);
			outPut = tDlg->achieve->achievename[4];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(5))
		if (game->difficu == 9 && game->totalLines >= 30)
		{
			tDlg->achieve->getnewachive(5);
			outPut = tDlg->achieve->achievename[5];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(6))
		if (game->scores == 233)
		{
			tDlg->achieve->getnewachive(6);
			outPut = tDlg->achieve->achievename[6];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(7))
		if (game->scores == 666)
		{
			tDlg->achieve->getnewachive(7);
			outPut = tDlg->achieve->achievename[7];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(8))
		if (game->scores == 6666)
		{
			tDlg->achieve->getnewachive(8);
			outPut = tDlg->achieve->achievename[8];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(9))
		if (game->totalLines == 0 && game->IsDead())
		{
			tDlg->achieve->getnewachive(9);
			outPut = tDlg->achieve->achievename[9];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(10))
		if (game->totalLines == 1)
		{
			tDlg->achieve->getnewachive(10);
			outPut = tDlg->achieve->achievename[10];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(11))
		if (tmpLines == 2)
		{
			tDlg->achieve->getnewachive(11);
			outPut = tDlg->achieve->achievename[11];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(12))
		if (tmpLines == 3)
		{
			tDlg->achieve->getnewachive(12);
			outPut = tDlg->achieve->achievename[12];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(13))
		if (tmpLines == 4)
		{
			tDlg->achieve->getnewachive(13);
			outPut = tDlg->achieve->achievename[13];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(14))
		if (game->deathNum >= 10)
		{
			tDlg->achieve->getnewachive(14);
			outPut = tDlg->achieve->achievename[14];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(15))
		if (game->deathNum >= 50)
		{
			tDlg->achieve->getnewachive(15);
			outPut = tDlg->achieve->achievename[15];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(16))
		if (game->deathNum >= 100)
		{
			tDlg->achieve->getnewachive(16);
			outPut = tDlg->achieve->achievename[16];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
	if (!tDlg->achieve->hasgetachieve(17))
		if (game->deathNum == 1)
		{
			tDlg->achieve->getnewachive(17);
			outPut = tDlg->achieve->achievename[17];
			SetDlgItemText(IDC_STATIC_GAMEACHIEVE, outPut);
			Sleep(200);
		}
}

