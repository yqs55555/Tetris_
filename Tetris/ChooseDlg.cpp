// ChooseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tetris.h"
#include "ChooseDlg.h"
#include "afxdialogex.h"
#include "GameDlg.h"


// CChooseDlg �Ի���

IMPLEMENT_DYNAMIC(CChooseDlg, CDialogEx)

CChooseDlg::CChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHOOSE, pParent)
{

}

CChooseDlg::~CChooseDlg()
{
}

void CChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChooseDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSEOK, &CChooseDlg::OnBnClickedButtonChooseok)
	ON_BN_CLICKED(IDC_BUTTON_CHOOSERETURN, &CChooseDlg::OnBnClickedButtonChoosereturn)
	ON_CBN_SELCHANGE(IDC_COMBO_CHOOSEDIFFICUI, &CChooseDlg::OnCbnSelchangeComboChoosedifficui)
END_MESSAGE_MAP()



// CChooseDlg ��Ϣ�������


void CChooseDlg::OnBnClickedButtonChooseok()
{
	this->SendMessage(WM_CLOSE);
	CWnd* main = GetParent();
	main->ShowWindow(HIDE_WINDOW);
	CGameDlg gameDlg;
	gameDlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CChooseDlg::OnBnClickedButtonChoosereturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CChooseDlg::OnCbnSelchangeComboChoosedifficui()
{
	//(CComboBox*)GetDlgItem(IDC_COMBO_CHOOSEDIFFICUI)
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

