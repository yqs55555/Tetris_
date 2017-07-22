#pragma once


// CAchieveDlg 对话框

class CAchieveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAchieveDlg)

public:
	CAchieveDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAchieveDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ACHIEVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAchievereturn();
	afx_msg void OnBnClickedButtonRank();
};
