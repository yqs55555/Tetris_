// AchieveDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "AchieveDlg.h"
#include "RankDlg.h"
#include "Rank.h"
#include "TetrisDlg.h"
#include "afxdialogex.h"


// CAchieveDlg 对话框

IMPLEMENT_DYNAMIC(CAchieveDlg, CDialogEx)

CAchieveDlg::CAchieveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ACHIEVE, pParent)
{

}

CAchieveDlg::~CAchieveDlg()
{
}

void CAchieveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAchieveDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ACHIEVERETURN, &CAchieveDlg::OnBnClickedButtonAchievereturn)
	ON_BN_CLICKED(IDC_BUTTON_RANK, &CAchieveDlg::OnBnClickedButtonRank)
END_MESSAGE_MAP()


// CAchieveDlg 消息处理程序

void CAchieveDlg::OnBnClickedButtonAchievereturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}

void CAchieveDlg::OnBnClickedButtonRank()
{
	CTetrisDlg* tetrisDlg = (CTetrisDlg *)GetParent();
	tetrisDlg->rank->display();
	CRankDlg rankDlg;
	rankDlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}
