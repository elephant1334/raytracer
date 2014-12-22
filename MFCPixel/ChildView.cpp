
// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "MFCPixel.h"
#include "ChildView.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_AMBIENT, &CChildView::OnAmbient)
	ON_UPDATE_COMMAND_UI(ID_AMBIENT, &CChildView::OnUpdateAmbient)
	ON_COMMAND(ID_DIRECTIONAL, &CChildView::OnDirectional)
	ON_UPDATE_COMMAND_UI(ID_DIRECTIONAL, &CChildView::OnUpdateDirectional)
	ON_COMMAND(ID_POINTLIGHT, &CChildView::OnPointlight)
	ON_UPDATE_COMMAND_UI(ID_POINTLIGHT, &CChildView::OnUpdatePointlight)
	ON_COMMAND(ID_DIRECTION_POINT, &CChildView::OnDirectionPoint)
	ON_UPDATE_COMMAND_UI(ID_DIRECTION_POINT, &CChildView::OnUpdateDirectionPoint)
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	vector<RGBColor> vc;
	World w;
	if(optionRec ==1)
	w.build();
	else if(optionRec ==2)
	w.buildwithdirectional();
	else if(optionRec == 3)
	w.buildwithpointlight();
	else if(optionRec == 4)
	w.buildwithpointanddirection();
	int hres = w.vp.hres;//650
	int vres = w.vp.vres;//300
	w.camera_ptr->render_scene(w);
	//vcolor=w.camera_ptr->getcolorvector();
	vc=w.getVectorColor();
	//vcolor=w.getVectorColor();
	// TODO: 在此处添加消息处理程序代码
	//for()
	for(int r = 0;r<vres;r++)
		for(int c = 0;c<=hres;c++){
			dc.SetPixel(c,vres-r,RGB((int)(vc[r*(hres+1)+c].r*255),(int)(vc[r*(hres+1)+c].g*255),(int)(vc[r*(hres+1)+c].b*255)));
		}
		
	//dc.MoveTo(100,100);
	//dc.LineTo(100,200);
	// 不要为绘制消息而调用 CWnd::OnPaint()
}



void CChildView::OnAmbient()
{
	// TODO: 在此添加命令处理程序代码
	optionRec = 1;
	Invalidate ();	
}


void CChildView::OnUpdateAmbient(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(optionRec == 1);
}


void CChildView::OnDirectional()
{
	// TODO: 在此添加命令处理程序代码
	optionRec = 2;
	Invalidate ();	
}


void CChildView::OnUpdateDirectional(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(optionRec == 2);
}


void CChildView::OnPointlight()
{
	// TODO: 在此添加命令处理程序代码
	optionRec = 3;
	Invalidate ();	
}


void CChildView::OnUpdatePointlight(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(optionRec == 3);
}


void CChildView::OnDirectionPoint()
{
	// TODO: 在此添加命令处理程序代码
	optionRec = 4;
	Invalidate ();	
}


void CChildView::OnUpdateDirectionPoint(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(optionRec == 4);
}
