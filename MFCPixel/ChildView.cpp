
// ChildView.cpp : CChildView ���ʵ��
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



// CChildView ��Ϣ�������

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
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
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
	// TODO: �ڴ˴������Ϣ����������
	//for()
	for(int r = 0;r<vres;r++)
		for(int c = 0;c<=hres;c++){
			dc.SetPixel(c,vres-r,RGB((int)(vc[r*(hres+1)+c].r*255),(int)(vc[r*(hres+1)+c].g*255),(int)(vc[r*(hres+1)+c].b*255)));
		}
		
	//dc.MoveTo(100,100);
	//dc.LineTo(100,200);
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}



void CChildView::OnAmbient()
{
	// TODO: �ڴ���������������
	optionRec = 1;
	Invalidate ();	
}


void CChildView::OnUpdateAmbient(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(optionRec == 1);
}


void CChildView::OnDirectional()
{
	// TODO: �ڴ���������������
	optionRec = 2;
	Invalidate ();	
}


void CChildView::OnUpdateDirectional(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(optionRec == 2);
}


void CChildView::OnPointlight()
{
	// TODO: �ڴ���������������
	optionRec = 3;
	Invalidate ();	
}


void CChildView::OnUpdatePointlight(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(optionRec == 3);
}


void CChildView::OnDirectionPoint()
{
	// TODO: �ڴ���������������
	optionRec = 4;
	Invalidate ();	
}


void CChildView::OnUpdateDirectionPoint(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(optionRec == 4);
}
