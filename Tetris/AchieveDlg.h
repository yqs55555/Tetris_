#pragma once


// CAchieveDlg �Ի���

class CAchieveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAchieveDlg)

public:
	CAchieveDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAchieveDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ACHIEVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAchievereturn();
	afx_msg void OnBnClickedButtonRank();
	afx_msg void OnBnClickedButtonAchieve();
};
