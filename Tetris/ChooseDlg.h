#pragma once


// CChooseDlg 对话框

class CChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseDlg)

public:
	CChooseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChooseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHOOSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChooseok();
	afx_msg void OnBnClickedButtonChoosereturn();
	afx_msg void OnCbnSelchangeComboChoosedifficui();

};
