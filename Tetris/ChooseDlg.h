#pragma once


// CChooseDlg �Ի���

class CChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChooseDlg)

public:
	CChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChooseDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHOOSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChooseok();
	afx_msg void OnBnClickedButtonChoosereturn();
	afx_msg void OnCbnSelchangeComboChoosedifficui();

};
