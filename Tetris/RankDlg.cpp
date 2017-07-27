// RankDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tetris.h"
#include "TetrisDlg.h"
#include "RankDlg.h"
#include "afxdialogex.h"


// CRankDlg �Ի���

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


// CRankDlg ��Ϣ�������


void CRankDlg::OnBnClickedButtonRankreturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CRankDlg::OnBnClickedButtonRankclear()
{
	CTetrisDlg *main = (CTetrisDlg*)GetTopLevelParent();
	main->rank->clear();//ɾ�����з�������
	MessageBoxA(nullptr, "����ɹ���", "��ʾ", MB_OK);
	this->SendMessage(WM_CLOSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

BOOL CRankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTetrisDlg *tetrisDlg = (CTetrisDlg *)GetTopLevelParent();
	tetrisDlg->rank->display(*this);//��ӡ���а�

	return TRUE;
}
