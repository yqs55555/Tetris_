// GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "GameDlg.h"
#include "afxdialogex.h"

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

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GAMERETURN, &CGameDlg::OnBnClickedButtonGamereturn)
END_MESSAGE_MAP()


// CGameDlg 消息处理程序


void CGameDlg::OnBnClickedButtonGamereturn()
{
	//CWnd* main = GetParent()->GetParent();
	//main->ShowWindow(SW_SHOW);
	ShowMain();
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}

BOOL CGameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		if (KEY_DOWN('H'))
			MessageBoxA(nullptr,
				"\t按键盘方向上键（“↑”）顺时针旋转方块\n\t按下方向键下键（“↓”）加快掉落\n\t按左键（“←”）时向左平移\n\t按右键（“→”）时向右平移\n\t按下H键可以获取帮助\n",
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

