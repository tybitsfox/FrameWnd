#include"stdafx.h"
#include"myframe.h"

BEGIN_MESSAGE_MAP(myframe,CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

myframe::myframe()
{
		CString str=AfxRegisterWndClass(CS_DBLCLKS,(HCURSOR)(AfxGetApp()->LoadStandardCursor(IDC_ARROW)),HBRUSH(COLOR_WINDOW+1),
			(HICON)(AfxGetApp()->LoadStandardIcon((LPCTSTR)IDI_ICON1)));
		CRect rect;
		int x1,x2,y1,y2;
		x1=y1=0;
		x2=::GetSystemMetrics(SM_CXSCREEN);
		y2=::GetSystemMetrics(SM_CYSCREEN);
		rect.SetRect(x1,y1,x2,y2);
		Create(str,"山东省环境监控中心-超标快报审核系统",WS_OVERLAPPED|WS_CAPTION|WS_VISIBLE|WS_SYSMENU|WS_MINIMIZEBOX,rect,NULL,MAKEINTRESOURCE(IDR_MENU1));
};
myframe::~myframe(){};
int myframe::OnCreate(LPCREATESTRUCT lpcreatestruct)
{
	if(CFrameWnd::OnCreate(lpcreatestruct)==-1)
		return -1;
	if(!mview.Create(NULL,NULL,AFX_WS_DEFAULT_VIEW,CRect(0,0,0,0),this,AFX_IDW_PANE_FIRST))
		return -1;
	return 0;
};
BOOL myframe::PreCreateWindow(CREATESTRUCT &cs)
{
	if(!CFrameWnd::PreCreateWindow(cs))
		return false;
	cs.dwExStyle&=~WS_EX_CLIENTEDGE;
	return true;
};
void myframe::OnSetFocus(CWnd *pwnd)
{
	mview.SetFocus();
};
BOOL myframe::OnCmdMsg(UINT uint,int ncode,void *pextra,AFX_CMDHANDLERINFO *pinfo)
{
	if(mview.OnCmdMsg(uint,ncode,pextra,pinfo))
		return true;
	return CFrameWnd::OnCmdMsg(uint,ncode,pextra,pinfo);
};








