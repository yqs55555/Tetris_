// GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "GameDlg.h"
#include "afxdialogex.h"


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
	CWnd* main = GetParent()->GetParent();
	main->ShowWindow(SW_SHOW);
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}
