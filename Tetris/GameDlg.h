#pragma once

#include "Game.h"
// CGameDlg �Ի���

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)
private:
	Game *game;
	void showInfo();
public:
	CGameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGameDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME };
#endif

protected:
	void InitInfo(int pattern,int difficu);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGamereturn();
	BOOL PreTranslateMessage(MSG * pMsg);
	void ShowMain();
	afx_msg void OnCancel();
	afx_msg void OnBnClickedButtonGamerestart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void OnBnClickedButtonGamestoporconti();
	void PaintBigCanvas();
	void PaintSmallCanvas();
protected:
	afx_msg void Restart();
	void OnPaint();
	virtual BOOL OnInitDialog();

};
