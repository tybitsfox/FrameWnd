#include"stdafx.h"
#include"resource.h"
#include"myview.h"
#include"myframe.h"
#include"myapp.h"

BOOL myapp::InitInstance()
{
	myframe *myf=new myframe;
	m_pMainWnd=myf;
	HICON ic=LoadIcon(IDI_ICON1);
	myf->SetIcon(ic,true);
	myf->SetIcon(ic,false);
	myf->ShowWindow(SW_SHOW);
	myf->UpdateWindow();
	return true;
};