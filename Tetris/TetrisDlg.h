
// TetrisDlg.h : ͷ�ļ�
//

#pragma once
#include "Rank.h"
#include "Achieve.h"

// CTetrisDlg �Ի���
class CTetrisDlg : public CDialogEx
{
public:
	Rank *rank;
	Achieve *achieve;
// ����
public:
	CTetrisDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TETRIS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBegingame();
	afx_msg void OnBnClickedButtonHelp();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonAchieve();
	void Help();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
