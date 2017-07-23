// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tetris.h"
#include "GameDlg.h"
#include "afxdialogex.h"

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

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GAMERETURN, &CGameDlg::OnBnClickedButtonGamereturn)
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������


void CGameDlg::OnBnClickedButtonGamereturn()
{
	//CWnd* main = GetParent()->GetParent();
	//main->ShowWindow(SW_SHOW);
	ShowMain();
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
	CDialogEx::OnCancel();
}

