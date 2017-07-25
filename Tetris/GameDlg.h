#pragma once

#include "Game.h"
// CGameDlg 对话框

class CGameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameDlg)
private:
	Game *game;
	void showInfo();//展示游戏信息
public:
	CGameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME };
#endif

protected:
	void InitInfo(int pattern,int difficu);//初始化游戏信息
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGamereturn();//返回开始界面
	BOOL PreTranslateMessage(MSG * pMsg);//获取用户输入
	void ShowMain();//显示主界面
	afx_msg void OnCancel();//直接按下左上关闭键时
	afx_msg void OnBnClickedButtonGamerestart();//
	afx_msg void OnTimer(UINT_PTR nIDEvent);//定时器
	void OnBnClickedButtonGamestoporconti();
	void PaintBigCanvas();//绘画大画布
	void PaintSmallCanvas();//绘画小画布
protected:
	afx_msg void Restart();//重新开始游戏
	void OnPaint();//绘画
	virtual BOOL OnInitDialog();
private:
	void GetAchieve(CTetrisDlg *tDlg, int tmpLines);//获得成就
};
