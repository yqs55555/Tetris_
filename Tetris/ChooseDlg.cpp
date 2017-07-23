// ChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tetris.h"
#include "ChooseDlg.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CChooseDlg 消息处理程序


void CChooseDlg::OnBnClickedButtonChooseok()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CChooseDlg::OnBnClickedButtonChoosereturn()
{
	this->SendMessage(WM_CLOSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CChooseDlg::OnCbnSelchangeComboChoosedifficui()
{
	//(CComboBox*)GetDlgItem(IDC_COMBO_CHOOSEDIFFICUI)
	// TODO: 在此添加控件通知处理程序代码
}
