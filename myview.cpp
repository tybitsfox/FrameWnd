#include"stdafx.h"
#include"resource.h"
#include"myview.h"

BEGIN_MESSAGE_MAP(myview,CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_NOTIFY(TVN_SELCHANGED,IDC_TREE1,on_tree_chg)
END_MESSAGE_MAP()

int myview::OnCreate(LPCREATESTRUCT lpcreatestruct)
{
	if(CWnd::OnCreate(lpcreatestruct)==-1)
		return -1;
	cbmp.LoadBitmapA(IDB_BITMAP1);
	CRect rect,rt1;
	if(!tree.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS|TVS_SHOWSELALWAYS,CRect(0,0,0,0),this,IDC_TREE1))
	{
		MessageBox("create treectrl error");
		return -1;
	}
	HTREEITEM ht=tree.InsertItem(_T("ITEM"),TVI_ROOT,TVI_LAST);
	tree.InsertItem(_T("item0"),ht);
	tree.InsertItem(_T("item1"),ht);
	tree.InsertItem(_T("item2"),ht);
	tree.InsertItem(_T("item3"),ht);
	tree.InsertItem(_T("item4"),ht);
	tree.InsertItem(_T("item5"),ht);
	tree.InsertItem(_T("item6"),ht);
	tree.InsertItem(_T("item7"),ht);
	tree.InsertItem(_T("item8"),ht);
	tree.InsertItem(_T("item9"),ht);
	tree.InsertItem(_T("item10"),ht);
	tree.InsertItem(_T("item11"),ht);
	tree.InsertItem(_T("item12"),ht);
	tree.InsertItem(_T("item13"),ht);
	tree.InsertItem(_T("item14"),ht);
	tree.InsertItem(_T("item15"),ht);
	tree.InsertItem(_T("item16"),ht);
	tree.InsertItem(_T("item17"),ht);
	tree.InsertItem(_T("item18"),ht);
	HTREEITEM ht1=tree.InsertItem(_T("BATTY"),TVI_ROOT,TVI_LAST);
	tree.InsertItem(_T("batty0"),ht1);
	tree.InsertItem(_T("batty1"),ht1);
	tree.InsertItem(_T("batty2"),ht1);
	HTREEITEM ht2=tree.InsertItem(_T("batty3"),ht1,TVI_LAST);
	tree.InsertItem(_T("batty30"),ht2);
	tree.InsertItem(_T("batty31"),ht2);
	tree.InsertItem(_T("batty32"),ht2);
	tree.InsertItem(_T("batty4"),ht1);
	tree.InsertItem(_T("batty5"),ht1);
	tree.InsertItem(_T("batty6"),ht1);
	tree.InsertItem(_T("batty7"),ht1);
	tree.InsertItem(_T("batty8"),ht1);
	tree.InsertItem(_T("batty9"),ht1);
	tree.InsertItem(_T("batty10"),ht1);
	tree.InsertItem(_T("batty11"),ht1);
	tree.InsertItem(_T("batty12"),ht1);
	tree.InsertItem(_T("batty13"),ht1);
	tree.InsertItem(_T("batty14"),ht1);
	tree.InsertItem(_T("batty15"),ht1);
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
	static int flg=0;
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
	rt1.SetRect(i/2-200,j/2-15,i/2+200,j/2+15);
	ft.CreatePointFont(180,"华文行楷");
	oldfont=adc.SelectObject(&ft);
	adc.SetTextColor(RGB(255,0,0));
	adc.DrawText("山东省环境监控中心",rt1,DT_CENTER|DT_VCENTER);
	if(flg==0)
	{
		rt1.SetRect(rect.left+3,rect.top+3,rect.left+200,rect.bottom-3);
		tree.MoveWindow(rt1);
		flg=1;
	}
	if(paintnum==1)
	{
		rt1.SetRect(i/2-100,j/2-70,i/2+100,j/2-40);
		adc.SetTextColor(RGB(0,0,255));
		adc.DrawText(g_str,rt1,DT_CENTER|DT_VCENTER);
	}
	adc.SelectObject(oldfont);
	ft.DeleteObject();
};
afx_msg void myview::on_tree_chg(NMHDR *phdr,LRESULT *lresult)
{
	HTREEITEM ht=tree.GetSelectedItem();
	if(tree.ItemHasChildren(ht))
		return;
	g_str=tree.GetItemText(ht);
	paintnum=1;//显示树形列表框信息
	CRect rect;
	GetClientRect(rect);
	InvalidateRect(rect);
};




