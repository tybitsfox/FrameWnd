#include"stdafx.h"
#include"resource.h"
#include"myview.h"

BEGIN_MESSAGE_MAP(myview,CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

int myview::OnCreate(LPCREATESTRUCT lpcreatestruct)
{
	if(CWnd::OnCreate(lpcreatestruct)==-1)
		return -1;
	cbmp.LoadBitmapA(IDB_BITMAP1);
	return 0;
};
BOOL myview::PreCreateWindow(CREATESTRUCT &cs)
{
	if(!CWnd::PreCreateWindow(cs))
		return false;
	//cs.dwExStyle|=WS_EX_CLIENTEDGE;
	cs.style&=~WS_BORDER;
	return true;
};
void myview::OnPaint()
{
	int i,j;
	CFont ft,*oldfont;
	//CPen pen,*oldpen;
	//CBrush brush,*oldbrush;
	CPaintDC adc(this);
	adc.SetMapMode(MM_TEXT);
	adc.SetBkMode(TRANSPARENT);
	CRect rect,rt1;
	GetClientRect(rect);
	BITMAP bp;
	CBitmap *ccmp;
	cbmp.GetBitmap(&bp);
	CDC memdc;
	memdc.CreateCompatibleDC(&adc);
	int cx,cy,ci,cj;//,ck;
	cx=rect.Width()/(bp.bmWidth)+1;
	cy=rect.Height()/(bp.bmHeight)+1;
	ccmp=memdc.SelectObject(&cbmp);
	for(cj=0;cj<cy;cj++)
	{
		for(ci=0;ci<cx;ci++)
		{
			adc.BitBlt(ci*bp.bmWidth,cj*bp.bmHeight,bp.bmWidth,bp.bmHeight,&memdc,0,0,SRCCOPY);
		}
	}
	memdc.SelectObject(ccmp);
	/*
	brush.CreateStockObject(NULL_BRUSH);
	oldbrush=adc.SelectObject(&brush);
	rect.DeflateRect(5,35,5,5);
	adc.Rectangle(rect);
	adc.SelectObject(oldbrush);
	brush.DeleteObject();	

	pen.CreatePen(PS_SOLID,1,RGB(255,0,255));
	oldpen=adc.SelectObject(&pen);
	adc.SelectObject(oldpen);
	pen.DeleteObject();*/
	i=rect.Width();
	j=rect.Height();
	rt1.SetRect(i/2-160,j/2-10,i/2+160,j/2+10);
	ft.CreatePointFont(140,"华文行楷");
	oldfont=adc.SelectObject(&ft);
	adc.DrawText("泰安市环境保护局",rt1,DT_CENTER|DT_VCENTER);
	adc.SelectObject(oldfont);
	ft.DeleteObject();
};

