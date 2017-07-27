// RankDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "RankDlg.h"
#include "afxdialogex.h"


// CRankDlg 对话框

IMPLEMENT_DYNAMIC(CRankDlg, CDialogEx)

CRankDlg::CRankDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_RANK, pParent)
{
	
}

CRankDlg::~CRankDlg()
{
}

void CRankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRankDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RANKRETURN, &CRankDlg::OnBnClickedButtonRankreturn)
	ON_BN_CLICKED(IDC_BUTTON_RANKCLEAR, &CRankDlg::OnBnClickedButtonRankclear)
END_MESSAGE_MAP()


// CRankDlg 消息处理程序


void CRankDlg::OnBnClickedButtonRankreturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CRankDlg::OnBnClickedButtonRankclear()
{
	CTetrisDlg *main = (CTetrisDlg*)GetTopLevelParent();
	main->rank->clear();//删除所有分数数据
	MessageBoxA(nullptr, "清理成功！", "提示", MB_OK);
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}

BOOL CRankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTetrisDlg *tetrisDlg = (CTetrisDlg *)GetTopLevelParent();
	tetrisDlg->rank->display(*this);//打印排行榜

	return TRUE;
}
