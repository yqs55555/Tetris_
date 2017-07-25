#pragma once

#include "Game.h"
// CGameDlg �Ի���

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)
private:
	Game *game;
	void showInfo();//չʾ��Ϸ��Ϣ
public:
	CGameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGameDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME };
#endif

protected:
	void InitInfo(int pattern,int difficu);//��ʼ����Ϸ��Ϣ
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGamereturn();//���ؿ�ʼ����
	BOOL PreTranslateMessage(MSG * pMsg);//��ȡ�û�����
	void ShowMain();//��ʾ������
	afx_msg void OnCancel();//ֱ�Ӱ������Ϲرռ�ʱ
	afx_msg void OnBnClickedButtonGamerestart();//
	afx_msg void OnTimer(UINT_PTR nIDEvent);//��ʱ��
	void OnBnClickedButtonGamestoporconti();
	void PaintBigCanvas();//�滭�󻭲�
	void PaintSmallCanvas();//�滭С����
protected:
	afx_msg void Restart();//���¿�ʼ��Ϸ
	void OnPaint();//�滭
	virtual BOOL OnInitDialog();
private:
	void GetAchieve(CTetrisDlg *tDlg, int tmpLines);//��óɾ�
};
