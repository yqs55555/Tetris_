// AchieveDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "AchieveDlg.h"
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
END_MESSAGE_MAP()


// CAchieveDlg 消息处理程序
