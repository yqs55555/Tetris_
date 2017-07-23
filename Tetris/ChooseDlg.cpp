// ChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "ChooseDlg.h"
#include "afxdialogex.h"
#include "GameDlg.h"
#include "Game.h"


// CChooseDlg 对话框

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
	ON_BN_CLICKED(IDC_RADIO_PATTERN2, &CChooseDlg::OnBnClickedRadioPattern2)
	ON_BN_CLICKED(IDC_RADIO_PATTERN0, &CChooseDlg::OnBnClickedRadioPattern0)
	ON_BN_CLICKED(IDC_RADIO_PATTERN1, &CChooseDlg::OnBnClickedRadioPattern1)
END_MESSAGE_MAP()



// CChooseDlg 消息处理程序


void CChooseDlg::OnBnClickedButtonChooseok()
{

	CGameDlg gameDlg;
	CWnd* main = GetParent();
	this->ShowWindow(HIDE_WINDOW);
	main->ShowWindow(HIDE_WINDOW);
	gameDlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CChooseDlg::OnBnClickedButtonChoosereturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CChooseDlg::OnCbnSelchangeComboChoosedifficui()
{
	CString res;
	CComboBoxEx* test = (CComboBoxEx *)GetDlgItem(IDC_COMBO_CHOOSEDIFFICUI);
	test->GetLBText(test->GetCurSel(), res);
	difficu = _ttoi(res);
	//this->difficu = m_Box.GetCurSel();
	//m_Box.GetLBText(this->difficu, strBox);

	// TODO: 在此添加控件通知处理程序代码
}

void CChooseDlg::OnBnClickedRadioPattern0()
{
	this->pattern = 0;
	// TODO: 在此添加控件通知处理程序代码
}


void CChooseDlg::OnBnClickedRadioPattern1()
{
	this->pattern = 1;
	// TODO: 在此添加控件通知处理程序代码
}

void CChooseDlg::OnBnClickedRadioPattern2()
{
	this->pattern = 2;
	// TODO: 在此添加控件通知处理程序代码
}
