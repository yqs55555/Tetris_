// RankDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tetris.h"
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


// CRankDlg ��Ϣ��������


void CRankDlg::OnBnClickedButtonRankreturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
}


void CRankDlg::OnBnClickedButtonRankclear()
{
	MessageBoxA(nullptr, "�����ɹ���", "��ʾ", MB_OK);
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
}