
// ChildView.h : CChildView ��Ľӿ�
//


#pragma once


// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();

// ����
public:
	int optionRec;
// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
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

