// AchieveDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tetris.h"
#include "AchieveDlg.h"
#include "RankDlg.h"
#include "Rank.h"
#include "TetrisDlg.h"
#include "afxdialogex.h"


// CAchieveDlg �Ի���

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


// CAchieveDlg ��Ϣ�������

void CAchieveDlg::OnBnClickedButtonAchievereturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CAchieveDlg::OnBnClickedButtonRank()
{
	CTetrisDlg* tetrisDlg = (CTetrisDlg *)GetParent();
	tetrisDlg->rank->display();
	CRankDlg rankDlg;
	rankDlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
