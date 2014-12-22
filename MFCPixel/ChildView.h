
// ChildView.h : CChildView 类的接口
//


#pragma once


// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 特性
public:
	int optionRec;
// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAmbient();
	afx_msg void OnUpdateAmbient(CCmdUI *pCmdUI);
	afx_msg void OnDirectional();
	afx_msg void OnUpdateDirectional(CCmdUI *pCmdUI);
	afx_msg void OnPointlight();
	afx_msg void OnUpdatePointlight(CCmdUI *pCmdUI);
	afx_msg void OnDirectionPoint();
	afx_msg void OnUpdateDirectionPoint(CCmdUI *pCmdUI);
};

