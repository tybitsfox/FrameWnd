#ifndef DEFAULT_MY_VIEW_ONE
#include"myview.h"
#endif
#ifndef IDI_ICON1
#include"resource.h"
#endif


class myframe:public CFrameWnd
{
public:
	myview mview;
	myframe();
	~myframe();
	int OnCreate(LPCREATESTRUCT lpcreatestruct);
	BOOL PreCreateWindow(CREATESTRUCT &cs);
	void OnSetFocus(CWnd *pwnd);
	BOOL OnCmdMsg(UINT uint,int ncode,void *pextra,AFX_CMDHANDLERINFO *pinfo);
DECLARE_MESSAGE_MAP()
};