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
	Game game(cDlg->pattern, cDlg->difficu);
	return TRUE;
}
void CGameDlg::InitInfo(int pattern,int difficu)
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
	dif.Format(_T("%d"),difficu);
	SetDlgItemText(IDC_STATIC_GAMEDIFFICU, dif);
}
void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GAMERETURN, &CGameDlg::OnBnClickedButtonGamereturn)
	ON_STN_CLICKED(IDC_STATIC_GAMEPATTERN, &CGameDlg::OnStnClickedStaticGamepattern)
	ON_STN_CLICKED(IDC_STATIC_GAMEDIFFICU, &CGameDlg::OnStnClickedStaticGamedifficu)
	ON_STN_CLICKED(IDC_STATIC_GAMESCORE, &CGameDlg::OnStnClickedStaticGamescore)
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������


void CGameDlg::OnBnClickedButtonGamereturn()
{
	ShowMain();
	GetParent()->SendMessage(WM_CLOSE);
	this->SendMessage(WM_CLOSE);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

BOOL CGameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN)
	{
		if (KEY_DOWN('H'))
			MessageBoxA(nullptr,
				"\t�����̷����ϼ�����������˳ʱ����ת����\n\t���·�����¼������������ӿ����\n\t���������������ʱ����ƽ��\n\t���Ҽ�����������ʱ����ƽ��\n\t����H�����Ի�ȡ����\n",
				"Help", MB_OK);
	}
	return false;
}

void CGameDlg::ShowMain()
{
	CWnd* main = GetParent()->GetParent();
	main->ShowWindow(SW_SHOW);
}

void CGameDlg::OnCancel()
{
	ShowMain();
	GetParent()->SendMessage(WM_CLOSE);
	CDialogEx::OnCancel();
}



void CGameDlg::OnStnClickedStaticGamepattern()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CGameDlg::OnStnClickedStaticGamedifficu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CGameDlg::OnStnClickedStaticGamescore()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
